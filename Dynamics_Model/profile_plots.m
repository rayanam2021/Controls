clc;
clear;
M = load('quadbi_mission.mat');

out = M.out;
t = out.tout;
inertial_pos = out.quadbi_states.data(1:end,1:3);
inertial_vel = out.quadbi_states.data(1:end,4:6);
euler_ang = out.quadbi_states.data(1:end,7:9);
body_vel = out.quadbi_states.data(1:end,19:21);
torques = out.quadbi_torque.data(1:end,1:end);
shaft_rpms = out.quadbi_rpm.data(1:end,1:end)*(60/2*pi);

%%%%%%%%%%Inertial Position%%%%%%%%%%%%%%%%
figure;
plot(t,inertial_pos.*[1,1,-1],'linewidth',3);
legend('x','y','z')
title('Position (m)')
xlabel('time')
% ylabel('m')
grid on;

%%%%%%%%%%Inertial Velocity%%%%%%%%%%%%%%%%
figure;
plot(t,inertial_vel.*[1,1,-1],'linewidth',3);
legend('vx','vy','vz')
title('Velocity (m/s)')
xlabel('time')
% ylabel('m/s')
grid on;

%%%%%%%%%%%Body Velocity%%%%%%%%%%%%%%%
% figure;
% plot(t,body_vel,'linewidth',3);
% legend('vx_b','vy_b','vz_b')
% title('Body Velocity')
% xlabel('time')
% ylabel('m/s')
% grid on;

%%%%%%%%%%Euler Angles%%%%%%%%%%%%%%%%
figure;
plot(t,euler_ang*180/pi,'linewidth',3);
legend('phi(roll)','theta(pitch)','psi(yaw)')
title('Euler angles (deg)')
xlabel('time')
% ylabel('rad')
grid on;

%%%%%%%%%%Mechanical Torques%%%%%%%%%%%%%%%%
figure;
plot(t,torques,'linewidth',3);
legend('rotor1','rotor2','rotor3','rotor4')
title('Torque of all motors (N-m)')
xlabel('time')
% ylabel('N-m')
grid on;

%%%%%%%%%%Shaft RPMs%%%%%%%%%%%%%%%%
figure;
plot(t,shaft_rpms,'linewidth',3);
legend('rpm1','rpm2','rpm3','rpm4')
title('RPM profile of all motors')
xlabel('time')
% ylabel('rpm')
grid on;
