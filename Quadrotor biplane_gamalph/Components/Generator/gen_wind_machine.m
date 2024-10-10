function [kt_gen,R_gen] = wind_machine(km_gen,Udc_gen,w_gen,emf_margin_gen)
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
Umarg_gen = Udc_gen .* (1.0-emf_margin_gen);
kt_gen = Umarg_gen./w_gen;
R_gen = (kt_gen./km_gen).^2;
end