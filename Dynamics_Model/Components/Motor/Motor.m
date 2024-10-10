%%%% Motor component input file %%%%

%% General masked inputs
Kp_TCntrl = 0.002;                  % Torque controller P-gain [-]
Ki_TCntrl = 0.002;                    % Torque controller I-gain [-]
Kd_TCntrl = 0.0;                    % Torque controller I-gain [-]
TCntrl_maxlim = 0.2;                 % Torque controller Max limit [Nm]

%%%%%%% Motor sizing inputs: No masking
gr = 1;                             % Gear ratio [-]
rotor_rpm = 7000;                   % Design or rated rotor rpm for sizing [rpm]
Udc = 24;                           % Design or rated DC bus voltage [V]
T_mot = 0.035;                      % Design or rated torque [Nm] 
aspect_ratio = 2.0;                 % Aspect-ratio [-]
emf_margin = 0.5;                   % Margin between Vdc and back-EMF at hover

% Calculated sizing i/ps
w_rot = rotor_rpm .* (pi/30.0);     % Design rotor speed [rad/s]
w_mot = w_rot .* gr;                % Design rotor speed after gearbox [rad/s]
P_mot = T_mot.*w_mot;               % Rated motor power [W]

% TAMU function to estimate motor sizing
[m,Vol,km,D,L,T0a,T0b,T0c] = size_machine(T_mot,aspect_ratio);

% TAMU motor resistance function
[kt,R] = wind_machine(km,Udc,w_mot,emf_margin);
%kt = 0.0108;
%R = 0.127;

% Motor mass and volume
MotorMass = m;                      % Motor mass [kg]                  
MotorVol = Vol;                     % Motor volume [m3]
