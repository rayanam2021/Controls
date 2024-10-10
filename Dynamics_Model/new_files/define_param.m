ip = fn_param();
ip = fn_blade_profile(ip);
ip_bus_info = Simulink.Bus.createObject(ip);
ip_bus = evalin('base', ip_bus_info.busName);
evalin('base', 'clear slBus1' );



function [ip] = fn_param()

	ip.N_bet = 15*2;				% number of blade element panels, keep it 50 to 100
	
%% flight & flow conditions
	
	ip.flight_cond = 0;				% = 0 for axial flight, = 1 for edgewise flight
	ip.vc	= 0;					% axial velocity in knots		
    ip.vinf = 0;                    % edge-wise forward velocity in knots
	ip.rho	= 1.2256;				% density kg/m^3;
	ip.mu_visc = 1.825e-5;			% dynamic viscosity
	ip.vc_int = 0;					% interference velocity, keep it zero

%% rotor configuration

	ip.Nb		= 2;				% number of blades
	ip.rad		= 0.328084;%0.416667;%0.328084;				% rotor radius in ft
	ip.rad_in	= 0.15*ip.rad;		% root cut in ft

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 	ip.sigma	= 0.20;				% equivalent solidity
% 	ip.twist	= -9;				% blade twist in deg
% 	ip.taper	= 2;				% blade taper

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    N_bet = ip.N_bet;
    M_dat = readmatrix('apcsf_10x4.7_geom.txt');
    rad_dat = M_dat(:,1);
    chord_dat = M_dat(:,2);
    beta_dat = M_dat(:,3);
    root_cut_val = rad_dat(1,1)*N_bet;
    size_cut = size(chord_dat);
    xq = 1:((size_cut-1)/(N_bet-root_cut_val)):size_cut;
    ip.chord_inter = interp1(chord_dat,xq);
    ip.beta_inter = interp1(beta_dat,xq);

% option for blade sweep
% for unswept blades, keep sweep1 = sweep2=0

% 	ip.sweep1	= 15*0;				% forward sweep in deg
% 	ip.sweep2	= 30*0;				% backward sweep in deg
% 	ip.rs		= 0.48;			% point of sweep reversal
	
% option for dual twist, keep tw1 = 1 for uniform twist rate

% 	ip.tw1	= 1;					% inner twist (normalized by by thetatw)
% 	ip.tc	= 0.4;					% radial location where twist rate changes
		
%% control parameters

% 	ip.treq = 15;					% required thrust in lbs
	ip.theta = 0;					% collective pitch (at 75% span) in degree
	ip.thetac = 0;					% cosinusoidal pitch, unused for hover
	ip.thetas = 0;					% sinusoidal pitch, unused for hover
	ip.tilt = 0;					% tilt, unused for hover
	
% 	ip.yct		= 0;
% 	if (ip.yct == 0)
% 		ip.rpm	= 6000;				% rpm
% 		ip.ctbysigmacheck = ip.treq*4.44822/(ip.rho*2*pi*(ip.rad*12*0.0254)^2*(ip.rad*12*0.0254*ip.rpm*2*pi/60)^2*ip.sigma);
% 	end
% 	if (ip.yct == 1)
% 		
% 		ip.ctbysigma = 0.10;		% blade loading
% % 		ip.rpm = (2*pi/60)*sqrt(ip.th_req/(ip.ctbysigma*ip.sigma_eq*ip.rho*ip.rad))
% 	end	
% 	if (ip.yct == 2)		
% 		ip.mu = 0.6;		% blade loading
% 	end	
	
%% airfoil data
	% load airfoil data : C_L and C_D as function of AOA for certain Reynolds and Mach number
	% Present data is generated using Xfoil
	% include more airfoil data if needed
	
% 	ip.af = 1;
% 	if (ip.af == 1)
	ip.data = load('data_airfoil/E63.dat');
    ip.data_high = load('data_airfoil/high_aoa.dat');
    %ip.data_high_aoa_cd = load('data_airfoil/high_aoa_cd.dat');
        %ip.data = load('data_airfoil\naca4412_200K.dat');		% choose airfoil section
        %ip.data = load('data_airfoil\clarkY.dat');
% 	end
% 	if(ip.af == 0)
% 		ip.cl_alpha = 2*pi;
% 		ip.cd = [0.01,0.5,1];
% 	end
	ip.data_interference = xlsread('data_misc/interference.xlsx');

%% initial solution, if required
% keep use_soln=1 if you want to use solution file, otherwise use any other number

	ip.use_soln = 0;	
% 	if (ip.use_soln == 1)
% 		ip.soln = xlsread('data_misc/init_soln.xlsx');	
% 	end
	
%% some more parameters
% tiploss flag,tiploss =1 means effect of tiploss is considered, 
% tiploss = any other number to neglect tiploss effect
	ip.tiploss = 1;	
	ip.fp = 3;				% flat plate area in ft^2
	ip.cutoff_bemt = 0.05;	% residual cutoff value, bemt loop
	ip.cutoff_coax = 1e-5;	% residual cutoff value, coax interference loop
	ip.cutoff_trim = 1e-4;	% residual cutoff value, trim loop
	ip.itermax_bemt	= 30;	% max. number of iterations, bemt loop
	ip.itermax_coax = 10;	% max. number of iterations, coax interference loop
	ip.itermax_trim = 10;	% max. number of iterations, trim loop
	ip.rw	= 1;			% denotes the radial location that sees climb vel., keep it 1
	ip.rot_sep = 0.25;		% vertical distance between coax rotors
	ip.gamma_UL = 0.6;		% coax interference parameters, keep it fixed
	ip.gamma_LU = 0.4;		% coax interference parameters, keep it fixed
	ip.delpsi = 10;			% delta azimuth (deg.) for ff, keep 5 to 10
	ip.kp = 1.00;			% increase in power due to non-uniform inflow in ff
	ip.kt = 1.00;			% reduction in thrust due to non-uniform inflow in ff
	ip.fac = 0.05;			% increase in instantaneous forces due to coaxial interference	
end



function [ip] = fn_blade_profile(ip)
%% decode inputs
rad			= ip.rad;
rad_in		= ip.rad_in;
Nb			= ip.Nb;
% sigma_eq	= ip.sigma_eq;
% twist		= ip.twist;
% taper		= ip.taper;
N_bet		= ip.N_bet;
theta75     = ip.theta;

%% bemt discretization
% n_bet = number of panels,r = position of mid-point of each panels, dr = length of each panels

[r_node,r,dr] = fn_discretization(ip);  
root_cut	= round(rad_in/rad*N_bet);    % cut-off percentage
if (root_cut == 0)
    root_cut = 1;
end
if (root_cut > 1)
	rc = (r(root_cut)+r(root_cut-1))*0.5;
end
if (root_cut == 1)
    rc = 0;
end


%% calculate sectional configurations   

chd			        = zeros(N_bet,1);
sigma		        = zeros(N_bet,1);
Re		            = zeros(N_bet,1);
thetacol			= zeros(N_bet,1);
theta_org			= zeros(N_bet,1);
% M_dat = readmatrix('apcsf_10x4.7_geom.txt');
% rad_dat = M_dat(:,1);
% chord_dat = M_dat(:,2);
% beta_dat = M_dat(:,3);
% 
% root_cut_val = rad_dat(1,1)*N_bet;
% 
% size_cut = size(chord_dat);
% xq = 1:((size_cut-1)/(N_bet-root_cut_val)):size_cut;
chord_inter = ip.chord_inter;
beta_inter = ip.beta_inter;
for i = root_cut:N_bet	
	chd(i,1)		= chord_inter(i-root_cut+1);			                    % sectional chord
	sigma(i,1)		= (Nb/pi)*chd(i);					                        % sectional solidity
	thetacol(i,1)		= theta75+beta_inter(i-root_cut+1)*(pi/180);			% sectional pitch
	theta_org(i,1)	= beta_inter(i-root_cut+1)*(pi/180);			            % sectional pitch
	%if(r(i) <= tc)
	%	theta(i,1)		= theta75+ thetatw2 * (tc-0.75)+ tw1*thetatw2 *(r(i)-tc);
	%	theta_org(i,1)	=  thetatw2 * (tc-0.75)+ tw1*thetatw2 *(r(i)-tc);
	%end
    
    
% 	Re(i,1) = rho*chd(i)*vtip*r(i)/mu_visc;
end
AR		= (rad-rad_in)/(rad*mean(chd));
%disp(AR)
% figure(1);
% plot(1:100,chd)
% title('C/R')
% figure(2);
% plot(1:100,theta)
% title('Picth')

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% calculate tangential distance of blade elements
% [rd1,rd2] = fn_blade_shape(ip,root_cut);
% rd = rd2;


%%

ip.chd = chd;
ip.sigma = sigma;
ip.thetacol = thetacol;
ip.rc = rc;
ip.AR = AR;
ip.root_cut = root_cut;
ip.r = r;
ip.dr = dr;
ip.rc = rc;

end



