function [r_node,r,dr] = fn_discretization(ip)
	N_bet = ip.N_bet;
    r_node = linspace(0,1,N_bet+1);
    r = zeros(N_bet,1);
    dr = 1/N_bet;
    for i = 1:N_bet
        r (i) = ( r_node(i)+r_node(i+1) )/2;
    end
end