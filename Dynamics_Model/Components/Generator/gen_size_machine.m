function [m_gen,Vol_gen,km_gen,D_gen,L_gen,T0a_gen,T0b_gen,T0c_gen] = gen_size_machine(T_gen,AR_gen)
% abstract code to size electric machine for given 
% operating conditions and mechanical & electrical constraints
%% FUTURE WORK
%   Increase fidelity (more physics), radial vs. axial
%% INPUTS
%   T [N.m]                 := continuous torque
%   AR [-]                  := motor aspect ratio (diameter/length)
%% OUTPUTS
%   m [kg]                  := motor dry mass
%   Vol [m^3]               := motor volume
%   km [N.m/sqrt(W)]        := figure of merit
%   D [m]                   := diameter
%   L [m]                   := length
%   T0a [N.m/(rad/s)^2]     := no-load torque curve-fit coefficient
%   T0b [N.m/(rad/s)]       := no-load torque curve-fit coefficient
%   T0c [N.m]               := no-load torque curve-fit coefficient
%% CODE
% estimate size, figure of merit
m_gen = T_gen./(1.098E+01);
Vol_gen = T_gen./(4.596E+04);
km_gen = (2.258E+03).*Vol_gen;
% derive geometry
D_gen = nthroot((4.*Vol_gen.*AR_gen)./pi,3);
L_gen = nthroot((4.*Vol_gen)./(pi.*AR_gen.^2),3);
% estimate no-load curve parameters (via Emrax)
T0a_gen = (1.36E-02).*(D_gen.^3) + (-5.18E-03).*(D_gen.^2) + (4.94E-04).*D_gen;
T0b_gen = (-4.31).*(D_gen.^3) + (1.61).*(D_gen.^2) + (-1.36E-01).*D_gen;
T0c_gen = (5.19E+02).*(D_gen.^3) + (-1.30E+02).*(D_gen.^2) + (9.23).*D_gen;
end