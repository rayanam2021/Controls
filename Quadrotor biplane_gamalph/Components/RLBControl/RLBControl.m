%%%% Ruled-based controller component inputs %%%%
%%%% This rule-based controller provides control inputs for engine speed %%%%
%%%% controller setpoint and generator current controller setpoint based %%%%
%%%% on battery SOC and SOC derivative %%%% 

%% General Masked inputs
Nref = 3000;  % Engine speed setpoint [rpm]
Iref = 500;   % Current setpoint [A]
SOCmax = 80;  % Max SOC during charging [%]
SOCmin = 30;  % Min SOC during discharging [%]