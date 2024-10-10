clc;
clear;

alpha = -180:180;
cl = zeros(length(alpha),1);
cd = zeros(length(alpha),1);
cm = zeros(length(alpha),1);
for i = 1:length(alpha)
    [cl(i),cd(i),cm(i)] = fun(alpha(i));
end

plot(alpha,cl)
hold on;
plot(alpha,cd)
hold on;
plot(alpha,cm)


function [cl,cd,cm] = fun(alpha)

if alpha >=-15 && alpha <= 15
    cl = 2*pi*alpha*(pi/180);
elseif alpha <= -25
    cl = -2*sind(alpha)*sind(alpha)*cosd(alpha);
elseif alpha >= 25
    cl = 2*sind(alpha)*sind(alpha)*cosd(alpha);
elseif alpha > 15 && alpha < 25
    cl = interp1([15,25],[2*pi*15*(pi/180),2*sind(25)*sind(25)*cosd(25)],alpha);
else
    cl = interp1([-25,-15],[-2*sind(25)*sind(25)*cosd(25),-2*pi*15*(pi/180)],alpha);
end

cd = 2*sind(abs(alpha))*sind(abs(alpha))*sind(abs(alpha));
cm = 0;
end

