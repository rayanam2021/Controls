%%%% Battery component inputs %%%%

%% General masked inputs
%%% Battery design
N_parallel      = 2;                                               % Number of cells in parallel [-]
N_series        = 6;                                                % Number of cells in series   [-]

%%% Battery cell paramters
SOC_init        = 100;                                              % Initial SOC [%]
E0              = 3.7348;                                           % Battery constant Voltage [V]
tau_bat         = 30;                                               % Battery response time [s]
Q_max           = 3;                                                % Maximum cell capacity [Ah]
Bat_Rint        = 0.09;                                             % Internal resistance [ohm]
Bat_K           = 0.0087662;                                        % Polarization constant [V/Ah]
Bat_A           = 0.468;                                            % Exponential zone amplitude [V]
Bat_B           = 3.5294;                                           % Exponential zone time constant [1/Ah]
Bat_lambda      = 0.1;                                              % Polarization resistance shift during the charge cycle
Vcell_max       = 4.2;                                              % Max battery cell voltage [V]
% %%%%%%% Other inputs: No masking
% n = 1;                              % Number of electrons
% F = ;                          % Faraday constant [C/mol]

%%%%%%% Battery sizing inputs: No masking
BaType = 'Li-ion';                                                  % Battery type
if BaType == 'Li-ion'
    BatGD = 0.200;                                                  % Battery gravimetric density [kWh/kg]
    BatVD = 0.450;                                                  % Battery volumetric density  [kWh/L]
else
    BatGD = 0.150;
    BatVD = 0.450;
end

BatP_max        = (Q_max*Vcell_max*N_series*N_parallel)/1000;       % Max battery power capacity [KWhr] 


% Battery mass and volume
BatteryMass = BatP_max*(1/BatGD);                                   % Battery mass [kg]                  
BatteryVol = BatP_max*(1/BatVD);                                      % Battery volume [m3]