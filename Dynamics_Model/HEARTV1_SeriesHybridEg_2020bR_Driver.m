%%%%%%%%%%%%%%% HEART V1 %%%%%%%%%%%%%%%

% clc
% clear all
% close all

current_directory = cd; 

%% Calling component input files
cd([cd,'/Components/Aerodynamics']);
Aerodynamics;                   % This file supplies the aerodynamics library block with input values
cd(current_directory);
cd([cd,'/Components/Propeller']);
Propeller;                      % This file supplies the propeller library block with input values. The propeller component should be called before any other component that has a weight calculation associated with it. See propeller component input file for reference
cd(current_directory);
cd([cd,'/Components/ShaftPM']);
ShaftPM;                        % This file supplies the propeller-motor shaft library block with input values
cd(current_directory);
cd([cd,'/Components/Engine']);
Engine;                         % This file supplies the engine library block with input values
cd(current_directory);
cd([cd,'/Components/RLBControl']);
RLBControl;                     % This file supplies the rule-based controller library block with input values
cd(current_directory);
cd([cd,'/Components/Battery']);
Battery;                        % This file supplies the battery library block with input values
cd(current_directory);
cd([cd,'/Components/Motor']);
Motor;                          % This file supplies the motor library block with input values
cd(current_directory);
cd([cd,'/Components/SpeedSetpointControl']);
SpeedSetpointControl;           % This file supplies the speed septpoint controller library block with input values
cd(current_directory);
cd([cd,'/Components/Generator']);
Generator;                      % This file supplies the generator library block with input values
cd(current_directory);
cd([cd,'/Components/ThermalManagement/BatteryThermal']);
BatteryThermal;                 % This file supplies the battery thermal management library block with input values
cd(current_directory);
cd([cd,'/Components/ThermalManagement/MotorThermal']);
MotorThermal;                   % This file supplies the motor thermal management library block with input values
cd(current_directory);
cd([cd,'/Components/ThermalManagement/EngineThermal']);
EngineThermal;                  % This file supplies the engine thermal management library block with input values
cd(current_directory);
cd([cd,'/Components/ThermalManagement/GeneratorThermal']);
GeneratorThermal;               % This file supplies the generator thermal management library block with input values
cd(current_directory);
cd([cd,'/Components/ShaftEG']);
ShaftEG;                        % This file supplies the engine-generator shaft library block with input values
cd(current_directory);

%% Simulation Settings
tend = 6000; % Simulation time [sec] 
RelTol = 1e-2; % Rela tive tolerance 
%%% Open and Run Simulation
%open('HEARTV1_SeriesHybridEg.slx');
%sim('HEARTV1_SeriesHybridEg.slx');

%% Plot Figures
%run('Plotfiles.m');
