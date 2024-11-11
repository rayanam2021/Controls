function dronebi_Animation(x,y,z,roll,pitch,yaw)

%% Define design parameters
D2R = pi/180;
R2D = 180/pi;
b   = 2.2;   % the length of total square cover by whole body of quadcopter in meter
a   = b/3;   % the legth of small square base of quadcopter(b/4)
H   = 3*0.06;  % hight of drone in Z direction (4cm)
H_m = H+H/2; % hight of motor in z direction (5 cm)
r_p = b/4;   % radius of propeller
%% Conversions
ro = 45*D2R;                   % angle by which rotate the base of quadcopter
Ri = [cos(ro) -sin(ro) 0;
      sin(ro) cos(ro)  0;
       0       0       1];     % rotation matrix to rotate the coordinates of base 

base_co = [-a/2  a/2 a/2 -a/2; % Coordinates of Base 
           -a/2 -a/2 a/2 a/2;
             0    0   0   0];
base = Ri*base_co;             % rotate base Coordinates by 45 degree 
to = linspace(0, 2*pi);
xp = r_p*cos(to);
yp = r_p*sin(to);
zp = zeros(1,length(to));
x_w1 = [b/(2*sqrt(2)),b/(2*sqrt(2)),b/(2*sqrt(2)),b/(2*sqrt(2))];
y_w1 = [b/(0.8*sqrt(2)),-b/(0.8*sqrt(2)),-b/(0.8*sqrt(2)),b/(0.8*sqrt(2))]; 
z_w1 = [1.5*H,1.5*H,-1.5*H,-1.5*H];
x_w2 = [-b/(2*sqrt(2)),-b/(2*sqrt(2)),-b/(2*sqrt(2)),-b/(2*sqrt(2))];
y_w2 = [b/(0.8*sqrt(2)),-b/(0.8*sqrt(2)),-b/(0.8*sqrt(2)),b/(0.8*sqrt(2))]; 
z_w2 = [1.5*H,1.5*H,-1.5*H,-1.5*H];

%% Define Figure plot
 fig1 = figure('pos', [0 50 800 600]);
 hg   = gca;
 view(120,20);
 grid on;
 axis equal;
 xlim([-1.5 1.5]); ylim([-2 2]); zlim([-1 2]);
 title('Quadrotor-Biplane Animation')
 xlabel('X[m]');
 ylabel('Y[m]');
 zlabel('Z[m]');
 hold(gca, 'on');
 
%% Design Different parts
% design the base square
 drone(1) = patch([base(1,:)],[base(2,:)],[base(3,:)],'r');
 drone(2) = patch([base(1,:)],[base(2,:)],[base(3,:)+H],'r');
 alpha(drone(1:2),0.7);
% design 2 parpendiculer legs of quadcopter 
 [xcylinder ycylinder zcylinder] = cylinder([H/2 H/2]);
 u1 = [b*zcylinder(1,:)-b/2;ycylinder(1,:);xcylinder(1,:)+H/2];
 u2 = [b*zcylinder(2,:)-b/2;ycylinder(2,:);xcylinder(2,:)+H/2];
 U1 = Ri*u1;
 U2 = Ri*u2;
 x_new = [U1(1,:);U2(1,:)];
 y_new = [U1(2,:);U2(2,:)];
 z_new = [U1(3,:);U2(3,:)];
 drone(3) =  surface(x_new,y_new,z_new,'facecolor','b');
 u1 = [ycylinder(1,:);b*zcylinder(1,:)-b/2;xcylinder(1,:)+H/2];
 u2 = [ycylinder(2,:);b*zcylinder(2,:)-b/2;xcylinder(2,:)+H/2];
 U1 = Ri*u1;
 U2 = Ri*u2;
 x_new = [U1(1,:);U2(1,:)];
 y_new = [U1(2,:);U2(2,:)];
 z_new = [U1(3,:);U2(3,:)];
 drone(4) =  surface(x_new,y_new,z_new,'facecolor','b') ; 
%  drone(4) =  surface(ycylinder,b*zcylinder-b/2,xcylinder+H/2,'facecolor','b') ;
 alpha(drone(3:4),0.6);
% design 4 cylindrical motors 
 drone(5) = surface(xcylinder+b/(2*sqrt(2)),ycylinder+b/(2*sqrt(2)),H_m*zcylinder+H/2,'facecolor','r');
 drone(6) = surface(xcylinder-b/(2*sqrt(2)),ycylinder+b/(2*sqrt(2)),H_m*zcylinder+H/2,'facecolor','r');
 drone(7) = surface(xcylinder+b/(2*sqrt(2)),ycylinder-b/(2*sqrt(2)),H_m*zcylinder+H/2,'facecolor','r');
 drone(8) = surface(xcylinder-b/(2*sqrt(2)),ycylinder-b/(2*sqrt(2)),H_m*zcylinder+H/2,'facecolor','r');
 alpha(drone(5:8),0.7);
% design 4 propellers
 drone(9)  = patch(xp+b/(2*sqrt(2)),yp+b/(2*sqrt(2)),zp+(H_m+H/2),'c','LineWidth',0.5);
 drone(10) = patch(xp-b/(2*sqrt(2)),yp+b/(2*sqrt(2)),zp+(H_m+H/2),'c','LineWidth',0.5);
 drone(11) = patch(xp+b/(2*sqrt(2)),yp-b/(2*sqrt(2)),zp+(H_m+H/2),'p','LineWidth',0.5);
 drone(12) = patch(xp-b/(2*sqrt(2)),yp-b/(2*sqrt(2)),zp+(H_m+H/2),'p','LineWidth',0.5);

% wing
 drone(13) = patch(x_w1,y_w1,z_w1,'g');
 drone(14) = patch(x_w2,y_w2,z_w2,'g');
 alpha(drone(9:12),0.3);
 alpha(drone(13:14),0.5);
%% create a group object and parent surface
  combinedobject = hgtransform('parent',hg );
  set(drone,'parent',combinedobject)
%  drawnow
%  patch([1000,1000,-1000,-1000],[1000,-1000,-1000,1000],[-1,-1,-1,-1],'k','FaceAlpha',0.75)
 myWriter = VideoWriter('dronebi_animation', 'MPEG-4');
 myWriter.Quality = 100;
%  myWriter.FrameRate = 120;
 open(myWriter);
 movieVector = getframe(gcf);
 writeVideo(myWriter, movieVector);
 for i = 1:100:int32(0.8*length(x))
  
     ba = plot3(x(1:i),y(1:i),z(1:i), 'b:','LineWidth',1.5);
   
     translation = makehgtform('translate',...
                               [x(i) y(i) z(i)]);
     %set(combinedobject, 'matrix',translation);
     rotation1 = makehgtform('xrotate',(pi/180)*(roll(i)));
     rotation2 = makehgtform('yrotate',(pitch(i)));
     rotation3 = makehgtform('zrotate',yaw(i));
     %scaling = makehgtform('scale',1-i/20);
     set(combinedobject,'matrix',...
          translation*rotation3*rotation2*rotation1);
      xlim([-10 10]+x(i)); ylim([-4 4]+y(i)); zlim([-3 5]+z(i)); 
      %movieVector(i) =  getframe(fig1);
        %delete(b);
     drawnow
     movieVector = getframe(gcf);
     writeVideo(myWriter, movieVector);
   % pause(0.2);
 end
 close(myWriter); 
end