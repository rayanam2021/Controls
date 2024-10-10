function [kt,R] = wind_machine(km,Udc,w,margin)
% Winds a motor for a given DC voltage and shaft speed 
% + desired bEMF margin
%% NOTES
%   Providing a back-EMF margin (say 20%) gives 
%   the motor some wiggle-room. This wiggle-room 
%   (voltage-wise) is required for bursts of 
%   hig-speed.
%   High-speed := shaft speed > nominal cruise 
%   shaft speed
%   20% margin seems reasonable for now
%
%   SAME APPLIES TO GENERATOR with bursts of 
%   high-speed engine output
%% INPUTS
%   km [N.m/sqrt(W)]    := figure of merit
%   Udc [V]             := bus voltage
%   w [rad/s]           := shaft speed
%   margin [-]          := margin between Vdc & 
%                       back-EMF at nominal speed
%% OUTPUTS
%   ke [N.m/A]          := back-emf constant
%   R [Ohms]            := phase resistance
%% CODE
Umarg = Udc .* (1.0-margin);
kt = Umarg./w;
R = (kt./km).^2;
end