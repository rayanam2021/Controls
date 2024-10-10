function [n] = sim_motor(T,w,kt,R,T0a,T0b,T0c)
% Estimate motor efficiency within rated shaft speed & torque limits
%% NOTES
% 	T0 = f(w), curve fit WRT shaft speed of torque losses at no-load
%   Future: incorporate harmonics, saturation, thermal effects
%% INPUTS
%   T [N.m]             := torque
%   w [rad/s]           := shaft speed
%   kt [N.m/A]          := torque constant
%   R [Ohms]            := phase resistance
%   T0a [N.m/(rad/s)^2] := no-load torque loss quadratic coefficient
%   T0b [N.m/(rad/s)]   := no-load torque loss linear coefficient
%   T0c [N.m]           := no-load torque loss constant coefficient
%
%% OUTPUTS
%   n [-]       := efficiency
%% CODE
% calculate no-load losses
Tloss = (T0a .* w.^2) + (T0b .* w) + T0c;
% calculate required electromagetic torque
Temag = T + Tloss; % electromagnetic torque = load + loss torque
% calculate back-EMF, phase current
E = kt .*w; % rms phase voltage
I = (Temag .* w)./ (3 .* E);
% calculate efficiency
% rms phase current assuming I is in phase with E, from 3EI = Tw
n = (T .* w) ./ ((Temag .* w) + (3.*R .* I.^2));
end

