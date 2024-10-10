%%%% Propeller component input file %%%%

%% General masked inputs

%%% Propeller Characteristics 
Dp = 1.1;                                           % Propeller diameter [m]
Cpp = [0.12,0.11,0.1,0.08,0.06,0.04,0];             % Propeller power co-efficient [-]
Ctp = [0.092,0.091,0.090,0.088,0.07,0.03,0];        % Propeller torque co-efficient [-]
Ref_J = [0,0.2,0.4,0.6,0.8,1,1.2];                  % Propeller reference advance ratio [-]

%%%% UAV Translational Dynamics 
m_acft = 230;                                       % UAV empty body weight [kg]
hfrac = 0.63/100;                                   % Fractional weight of hydraulics, piping, cables [%]

%%%%%%% Select Components to Account for their Weights: No masking

% Select the components for which you wish to account the weights
% for. Enter '1' to account for the weight of that particular component and
% '0' to discount the weight of the component. For instance, if you have a
% battery-electric architecutre, enter '1' for 'BatteryMass' and '0' for
% 'EngineMass' as a battery-electric architecture does not incorporate an
% engine but does require a battery

MotorMass = 1;                                      % Enter '1' to account for the motor weight and '0' to discsount the motor weight
BatteryMass = 1;                                    % Enter '1' to account for the battery weight and '0' to discsount the battery weight
EngineMass = 1;                                     % Enter '1' to account for the engine weight and '0' to discsount the engine weight
GenMass = 1;                                        % Enter '1' to account for the generator weight and '0' to discsount the generator weight
Tank_Fuelwt = 1;                                    % Enter '1' to account for the tank and fuel weight and '0' to discsount the tank and fuel weight

