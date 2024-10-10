function load = fn_bemt_edgewise(rpm,States,ip)

%% decoding parameters



% rotor parameters

Nb			= ip.Nb;
rad_ft		= ip.rad;
rad_in_ft	= ip.rad_in;
sigma_eq	= ip.sigma;
data		= ip.data;
data_high   = ip.data_high;
theta75_deg = ip.theta;
% rotation	= ip.rotation;
rotation = 1;


N_bet		= ip.N_bet;
rho			= ip.rho; 



% use_soln	= ip.use_soln;
% tiploss		= ip.tiploss;
itermax		= ip.itermax_bemt;
iter_cutoff	= ip.cutoff_bemt;
% rw			= ip.rw;


kt = ip.kt;
kp = ip.kp;

delpsi	= ip.delpsi;

%% unit conversion

tilt	= States(7);		        % radian
rad		= rad_ft*12*0.0254;			% meter

vc		= States(6);		        % meter/sec
vinf	= States(4);		        % meter/sec


%% rpm

disc_area	= pi*rad^2;		% disc area


omega		= rpm*2*pi/60;	% rotational speed
vtip		= omega*rad;    % tip speed (without considering fluid speed)
lambdac		= vc/vtip;      % non-dimensional climb velocity
mu			= vinf/vtip;
mux			= vinf*cos(tilt)/vtip;
muz			= vinf*sin(tilt)/vtip;


%%  Reynolds number
%Re = ip.Re;


% calculate Reynolds number
%index_75 = round(ip.N_bet*0.75);


%% BEMT loop


% azimuthal discretization

psi		= 0:delpsi:(360-delpsi);
psi		= psi'*pi/180;
npsi	= length(psi);

% matrix initialization

F			= zeros(N_bet,npsi);
theta		= zeros(N_bet,npsi);
lambdai		= zeros(N_bet,npsi);
lambdai_old	= zeros(N_bet,npsi);
Ut			= zeros(N_bet,npsi);
Up			= zeros(N_bet,npsi);
U			= zeros(N_bet,npsi);
phi			= zeros(N_bet,npsi);
alpha		= zeros(N_bet,npsi);
cl2d		= zeros(N_bet,npsi);
cd			= zeros(N_bet,npsi);
cm			= zeros(N_bet,npsi);
cl			= zeros(N_bet,npsi);
dL			= zeros(N_bet,npsi);
dD			= zeros(N_bet,npsi);        
dFz			= zeros(N_bet,npsi); 
dFtan		= zeros(N_bet,npsi);
dFtan2		= zeros(N_bet,npsi);
dQ			= zeros(N_bet,npsi);
dQ2			= zeros(N_bet,npsi);
dMy			= zeros(N_bet,npsi);
dMx			= zeros(N_bet,npsi);
dMp			= zeros(N_bet,npsi);	

Ftan		= zeros(npsi,1);
Fx			= zeros(npsi,1);
Fy			= zeros(npsi,1);
Fz			= zeros(npsi,1);
Q			= zeros(npsi,1);
Q2			= zeros(npsi,1);
Mx			= zeros(npsi,1);
My			= zeros(npsi,1);
Mp			= zeros(npsi,1);
error2      = zeros(itermax,1);


for j=1:length(psi)
    for i = 1:N_bet
        F(i,j) = 1;
    end
end

lambda0 = 0;
lambda  = lambdac;

for iter=1:itermax
	kai = atan2 (mux,(muz+lambda0) );
	%kai3 = atan2 (mux,(muz) );
	kx = 15*pi/23*tan( kai/2 );
% 	kx = 0.5;
%   kx(i,j) = (sin(kai(i,j)))^2;
%   kx(i,j) = 4/3*(1-cos(kai(i,j))-1.8*mu^2)/sin(kai(i,j));
	ky = -2*mu*0;   
	for j =1:length(psi)        
		for i = root_cut:N_bet
			theta(i,j) = thetacol(i) + thetac*cos(psi(j))+thetas*sin(psi(j));
			% dynamic inflow calculations
			lambdai_old(i,j) = lambdai(i,j);     
			lambdai(i,j) = lambda0*(1 + kx*r(i)*cos(psi(j)) + ky*r(i)*sin(psi(j)) );
			Ut(i,j) = ( r(i) + sin(psi(j))*mux )*vtip;
			Up(i,j) = ( lambdai(i,j) + lambdac + muz )*vtip;
			U(i,j) = sqrt( (Up(i,j))^2 + (Ut(i,j))^2 );
			phi(i,j) =atan2(Up(i,j),Ut(i,j));
			alpha(i,j) = theta(i,j)-phi(i,j);
%             if i==75
% %                 disp({'alpha',alpha(i,j)*180/pi})
%             end
            if alpha(i,j)>pi
                alpha(i,j) = 2*pi-pi;
            end
            if alpha(i,j)<-pi
                alpha(i,j) = 2*pi+pi;
            end
% 			cl(i,j) = cl_alpha*alpha(i,j);
% 			cd(i,j) = cd0 + d1*alpha(i,j) + d2*alpha(i,j)^2;
% 			if (alpha(i,j)<0)
% 				alpha(i,j)=0;
% 			end
 			[cl2d(i,j),cd(i,j),cm(i,j)] = fn_clcdcm_data(alpha(i,j),data,data_high);
            %[cl2d(i,j),cd(i,j),cm(i,j)] = fn_clcdcm_new(alpha(i,j),data);
            %[cl2d(i,j),cd(i,j),cm(i,j)] = fn_clcdcm(alpha(i,j),data);
            cl(i,j) = cl2d(i,j)/(1+1/AR);
			dL(i,j) = 0.5*rho*U(i,j)^2*chd(i)*cl(i,j)*dr*rad^2;
			dD(i,j) = 0.5*rho*U(i,j)^2*chd(i)*cd(i,j)*dr*rad^2;        
			dFz(i,j) = dL(i,j)*cos(phi(i,j)) - dD(i,j)*sin(phi(i,j));  
			dFtan(i,j) = dL(i,j)*sin(phi(i,j)) + dD(i,j)*cos(phi(i,j));
			%dFtan2(i,j) = kp*dL(i,j)*sin(phi(i,j)) + dD(i,j)*cos(phi(i,j));
			dQ(i,j) = dFtan(i,j)*r(i)*rad;
			%dQ2(i,j) = dFtan2(i,j)*r(i)*rad;
			dMy(i,j) =  dFz(i,j)*r(i)*cos(psi(j))*rad;
			dMx(i,j) = -dFz(i,j)*r(i)*sin(psi(j))*rad;
			dMp(i,j) = 0.5*rho*U(i,j)^2*chd(i)^2*cm(i,j)*dr*rad^3;        
% 			f(i,j) = Nb*(1-r(i))/lambda(i,j)/2;
% 			if (tiploss ==1)
% 				F(i,j) = 2*acos( exp(-f(i)) )/pi;
% 			end
		end    
		Ftan(j,1) = sum(dFtan(:,j));
		Fx(j,1) = -sum(dFtan(:,j))*sin(psi(j));
		Fy(j,1) = sum(dFtan(:,j))*cos(psi(j));
		Fz(j,1) = sum(dFz(:,j));
		Q(j,1) = sum(dQ(:,j)); 
		%Q2(j,1) = sum(dQ2(:,j)); 
		Mx(j,1) = sum(dMx(:,j));
		My(j,1) = sum(dMy(:,j));
		Mp(j,1) = sum(dMp(:,j));
	end
    ct = Nb*mean(Fz)/(rho*disc_area*vtip^2);
	
% 	steady part of dynamic inflow update    
% 	lambda0 = 0.5*ct/sqrt( lambda0^2 + mu^2);
	ct_m = 1*ct;
    lambda_2 = lambda;
	if (iter <=itermax)
		lambda_1 = sqrt(0.5*( sqrt(mu^4+ ct_m^2)-mu^2 ) ) + lambdac;   
	end
	if (iter>itermax)
		lambda_1 = mu*tan(tilt)*0+0.5*ct/sqrt(mu^2+lambda^2) + lambdac;
	end
    
    lambda = lambda_2 + (lambda_1-lambda_2)*0.5;
	lambda0 = lambda-lambdac;
	
    error = lambdai-lambdai_old;
    norm_error = 0;
    for j =1:length(psi)
        for i=root_cut:N_bet
            norm_error = norm_error+error(i,j)^2;
        end
    end
    error2(iter,1)=norm_error;
    
    if((error2(iter)<iter_cutoff) && (iter >1))
        break
    end
end


%% final performance calculation

Fx = kt*Fx;
Fy = kt*Fy;
Fz  = kt*Fz;
ct = kt*ct;

net_Mx = Nb*mean(Mx);
net_My = Nb*mean(My);
net_Mz = -Nb*mean(Q2);
net_Mp = mean(Mp);
Forcex = Nb*mean(Fx);
Forcey = Nb*mean(Fy);
Forcez = Nb*mean(Fz);
torque = abs(Nb*mean(Q));
torque2 = abs(Nb*mean(Q2));
power = omega*torque;
power2 = omega*torque2;
power = abs(power);
power2 = abs(power2);
Force_total = sqrt((Nb*mean(Fz))^2+(Nb*mean(Fx))^2);

thrust_N = Force_total;
power_watt = power2;
torque_Nm = torque2;

thrust_lbs = thrust_N*0.224809;
power_hp = power_watt/746;

theta_deg = theta.*180/pi;		% sectional pitch in deg.
alpha_deg = alpha.*180/pi;		% sectional AOA


phi_deg = phi*180/pi;
alpha2 = atan(Forcex/Forcez);
alphaf2 = tilt - alpha2;
load = zeros(6,1);
load(1) = Forcex;	% Fx
load(2) = Forcey*rotation*0;	% Fy
load(3) = Forcez;	% Fz
load(4) = net_Mx*rotation;	% Mx
load(5) = net_My;	% My
load(6) = net_Mz*rotation;	% Mz


end