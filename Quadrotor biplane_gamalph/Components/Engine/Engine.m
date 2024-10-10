%%%% Engine component input file %%%%

%% General Masked inputs
%%% Engine specifications
TC = 1;                                      % '1' for Turbocharged engine, '0' for Naturally-aspirated engine
Vd = 0.002;                                  % Engine displacement [m^3]
VolEta = 0.85;                               % Volumetric efficiency [%/100]
GIEta = 0.45;                                % Gross indicated efficiency [%/100]
Kp_fuelCntrl = 10;                           % Fuel controller p-gain [-]
Ki_fuelCntrl = 1;                            % Fuel controller I-gain [-]
AFRmax = 500;                                % Maximum air-fuel ratio [-]
AFRmin = 17;                                 % Minimum air-fuel ratio [-]
Hloss = 0.25;                                % Heat loss as a percentage of input fuel energy  [%/100]

%%% Fuel properties inputs
%CxHy + as/phi*(O2 + 3.76*N2) --> nC*CO2 +nH/2*H2O + 3.76*as/phi*N2 + as*(1/phi-1)*O_2 (eq.1)
nC = 13;                                     % Enter number of Carbon atoms in fuel
nH = 19.6;                                   % Enter number of Hydrogen atoms in fuel
nO = 0;                                      % Enter number of Oxygen atoms in fuel
LHV = 42.6e6;                                % Fuel LHV [J/kg]                   
 
%%% Fuel storage inputs
L_tank = 0.2;                                % Rectangular fuel tank length [m]
W_tank = 0.2;                                % Rectangular fuel tank width [m] 
H_tank = 0.1;                                % Rectangular fuel tank height [m] 
rho_poly = 940;                              % Density of polyethylene [kg/m3]
N_tanks = 1;                                 % No. of fuel tanks
FuelCap = 15;                                % Fuel capacity per tank [kg]

%%% Turbocharing
Comp_IsEta = 0.7;                            % Compressor isentropic efficiency [%/100]
Turb_IsEta = 0.7;                            % Turbine isentropic efficiency [%/100]
Turbo_MEta = 0.98;                           % Turbocharger mechanical efficiency [%/100]
DeltaP = -0.02;                              % Delta pressure between the compressor outlet pressure and exhaust pressure [bar]. 
                                             % *DeltaP is a negative value

%%%%%%% Engine sizing inputs: No masking
P_eng = 113;                                 % Rated engine power [kW] 
if P_eng == 113;
EngGD = 0.6209;                              % Engine gravimetric density
else
EngGD = 0.17;                                % Engine gravimetric density
end

EngVD = 17.4;                                % Engine volumetric density [kW/L]

% Engine mass and volume
EngineMass = P_eng*(1/EngGD);                % Engine mass [kg]                  
EngineVolume = P_eng*(1/EngVD);              % Engine volume [m3]

%%%%%%% Fuel storage sizing: No masking
Tank_vol = L_tank*W_tank*H_tank;
EmTank_wt = rho_poly*Tank_vol; % Empty tank weight [kg]
Tot_Tankwt = EmTank_wt*N_tanks; % Total empty tank weight [kg] 
Tot_FuelCap = FuelCap*N_tanks;  % Total fuel Capacity [kg]
Tank_Fuelwt = Tot_Tankwt+Tot_FuelCap; % Total Tank + Fuel weight [kg]
