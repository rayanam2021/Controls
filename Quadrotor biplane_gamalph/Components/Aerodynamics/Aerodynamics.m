%%%% Aerodynamics component input file %%%%

%% General masked inputs

%%% Mission profile
Mv = 1.25;                                           % UAV speed multiplier 
UAVSpeed_Cmd = [0,10.8,16.69,27,27,27,0,0].*Mv;      % Command Mission UAV Speed [m/s]
Altitude_Cmd = [0,0,329,867.7,2500,2500,0,0];        % Command Altitude [m]
Ref_Time = [0,512,800,1440,3200,5000,6000,6500];     % Reference operation time [sec]

%%% Lift calculation inputs
MinAw = 40;                                          % Min. wing area [m^2] 
MaxAw = 60;                                          % Max wing area [m^2] 
CLf = 0.35;                                          % lift correction factor [-]
MaxLift = 7000;                                      % Max lift [N]



