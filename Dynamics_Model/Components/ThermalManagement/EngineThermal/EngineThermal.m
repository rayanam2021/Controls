%%%% Engine thermal component input file %%%%
%% General Masked inputs

Act_Temp = 340;                                  % Thermostat activation temperature [K] 

%%% Fluid properties: No masking
Re_TLU   = [6, 8, 12, 14, 16]' .* 1e4;           % Reynolds number vector [-]
Pr_TLU   = [2, 4, 6, 8, 10];                     % Prandtl number vector [-]
% Fluid properties calculated
Nu_TLU  = 0.3.* Re_TLU .^ 0.8 * Pr_TLU .* 0.33;  %  Nusselt number table [-]

