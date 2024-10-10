%%%% Generator component input file %%%%

%% General masked inputs

Kp_GenVCntrl = 0.1;                       % Voltage controller P-gain [-]
Ki_GenVCntrl = 0.1;                       % Voltage controller I-gain [-]
GenV_UpL = 500;                           % Voltage controller: max Limit [V]
Eta_gen = 0.95;                           % Generator efficiency [%/100] 

%%%%%%% Generator sizing inputs: No masking
gr = 1;                                   % Gear ratio [-]
rotor_rpm_gen = 3000;                     % Design or rated rotor rpm for sizing [rpm]
Udc_gen = 200;                            % Design or rated DC bus voltage [V]
T_gen = 350;                              % Design or rated torque [Nm]
AR_gen = 2.7;                             % Aspect-ratio [-]
emf_margin_gen = 0.2;                     % Margin between Vdc and back-EMF

% Calculated sizing i/ps
w_rot_gen = rotor_rpm_gen .* (pi/30.0);   % Design rotor speed [rad/s]
w_gen = w_rot_gen .* gr;                  % Design rotor speed after gearbox [rad/s]
P_gen = T_gen.*w_gen;                     % Rated generator power [W]

% TAMU function to estimate generator sizing
[m_gen,Vol_gen,km_gen,D_gen,L_gen,T0a_gen,T0b_gen,T0c_gen] = gen_size_machine(T_gen,AR_gen);

% TAMU generator resistance function
[kt_gen,R_gen] = gen_wind_machine(km_gen,Udc_gen,w_gen,emf_margin_gen);

% Generator mass and volume
GenMass = m_gen;                      % Generator mass [kg]                  
GenVol = Vol_gen;                     % Generator volume [m^3]


% TAMU function to estimate generator efficiency
% [n_gen] = sim_gen(T_gen,w_gen,kt_gen,R_gen,T0a_gen,T0b_gen,T0c_gen);