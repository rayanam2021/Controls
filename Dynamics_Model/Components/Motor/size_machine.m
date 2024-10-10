function [m,Vol,km,D,L,T0a,T0b,T0c] = size_machine(T,AR)
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
m = T./(1.098E+01);
Vol = T./(4.596E+04);
km = (2.258E+03).*Vol;
% derive geometry
D = nthroot((4.*Vol.*AR)./pi,3);
L = nthroot((4.*Vol)./(pi.*AR.^2),3);
% estimate no-load curve parameters (via Emrax)
T0a = (1.36E-02).*(D.^3) + (-5.18E-03).*(D.^2) + (4.94E-04).*D;
T0b = (-4.31).*(D.^3) + (1.61).*(D.^2) + (-1.36E-01).*D;
T0c = (5.19E+02).*(D.^3) + (-1.30E+02).*(D.^2) + (9.23).*D;
end