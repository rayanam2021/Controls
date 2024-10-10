function [n_gen] = sim_gen(T_gen,w_gen,kt_gen,R_gen,T0a_gen,T0b_gen,T0c_gen)
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
Tloss_gen = (T0a_gen .* w_gen.^2) + (T0b_gen .* w_gen) + T0c_gen;
% calculate required electromagetic torque
Temag_gen = T_gen + Tloss_gen; % electromagnetic torque = load + loss torque
% calculate back-EMF, phase current
E_gen = kt_gen .*w_gen; % rms phase voltage
I_gen = (Temag_gen .* w_gen)./ (3 .* E_gen);
% calculate efficiency
% rms phase current assuming I is in phase with E, from 3EI = Tw
n_gen = (T_gen .* w_gen) ./ ((Temag_gen .* w_gen) + (3.*R_gen .* I_gen.^2));
end

