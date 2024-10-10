%%%% Motor thermal component input file %%%%

%% General Masked inputs
Cpcore_m = 387;                          % Specific heat capacity of BLDC motor magnet (material: Copper) [J/kgK]
kcore_m = 386;                           % Thermal conductivity of BLDC motor magnet (material: Copper) [W/(mk)]
casingCp_m = 903;                        % Specific heat capacity of motor casing (material: Aluminum) [J/kgK] 
Simh_m = 41.6;                           % Forced convection coefficient for air [W/m^2K]

% h_air = 12.12=-1.16v+11.6v^(1/2) empirical equation for air forced convection as a function of velocity and can be used for velocities 2 to 20 m/s


