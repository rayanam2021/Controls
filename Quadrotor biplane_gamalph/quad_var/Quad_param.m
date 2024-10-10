% Quadrotor Physical Parameters

N_rotor = 4;

Quad = fn_quad_param();
Quad_bus_info = Simulink.Bus.createObject(Quad);
Quad_bus = evalin('base', Quad_bus_info.busName);
evalin('base', 'clear slBus1' );

function [Quad] = fn_quad_param()
    Quad.g = 9.8;
    Quad.m = 1.4;      % Quadrotor mass (kg)
    Quad.l = .56;     % Distance from the center of mass to the each motor (m)
    Quad.t = .02;   %Thickness of the quadrotor's arms for drawing purposes (m)
    Quad.rot_rad = .1;   %Radius of the propellor (m)
    Quad.Kd = 6.6355e-08;  %3.5000e-09;%6.6355e-08%1.1563e-08;%2.1923e-07%1.3858e-6;    % Drag torque coeffecient (kg-m^2)

    Quad.Kdx = 0.16481;    % Translational drag force coeffecient (kg/s)
    Quad.Kdy = 0.31892;    % Translational drag force coeffecient (kg/s)
    Quad.Kdz = 1.1E-6;    % Translational drag force coeffecient (kg/s)

    Quad.Jx = .05;     % Moment of inertia about X axis (kg-m^2)
    Quad.Jy = .05;     % Moment of inertia about Y axis (kg-m^2)
    Quad.Jz = .24;    % Moment of inertia about Z axis (kg-m^2)
    
    Quad.KT = 6.2543e-06;
    
    %Altitude
    Quad.Z_KP = 0.01;
    Quad.Z_KD = -0.02;
    
    
    Quad.N_rotor = 4;
    Quad.rotor1_angle = 0;             %-|-
    Quad.arm_angle = pi/2; 

end