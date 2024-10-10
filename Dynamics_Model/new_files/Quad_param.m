% Quadrotor Physical Parameters

Quad = fn_quad_param();
Quad_bus_info = Simulink.Bus.createObject(Quad);
Quad_bus = evalin('base', Quad_bus_info.busName);
evalin('base', 'clear slBus1' );

function [Quad] = fn_quad_param()
    Quad.g = 9.8;
    Quad.m = 12;      % Quadrotor mass (kg)
    Quad.l = .4675;     % Distance from the center of mass to the each motor (m)
    Quad.rot_rad = .1;   %Radius of the propellor (m)
    Quad.Kd = 6.6355e-08;  %3.5000e-09;%6.6355e-08%1.1563e-08;%2.1923e-07%1.3858e-6;    % Drag torque coeffecient (kg-m^2)

   

%     Quad.Jx = .05;     % Moment of inertia about X axis (kg-m^2)
%     Quad.Jy = .05;     % Moment of inertia about Y axis (kg-m^2)
%     Quad.Jz = .24;    % Moment of inertia about Z axis (kg-m^2)
    Quad.J = [1.86 0 0;...
              0 2.031 0;...
              0 0 3.617];
    Quad.J_inv = inv(Quad.J);      

end