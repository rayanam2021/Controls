close all
clear all
clc
 
 %% 1. define the motion coordinates 
%     t = out.out.tout;
%     tt    = 0:0.03:6;
    out = load("quadbi_mission2.mat");
    z     = -out.out.states_gamalph.data(1:end,3);
    y     = -out.out.states_gamalph.data(1:end,2);
    x     = out.out.states_gamalph.data(1:end,1);
    yaw   = -out.out.states_gamalph.data(1:end,9);
    roll  = out.out.states_gamalph.data(1:end,7);
    pitch = -out.out.states_gamalph.data(1:end,8);
 %% 6. animate by using the function makehgtform
 % Function for ANimation of QuadCopter
  dronebi_Animation(x,y,z,roll,pitch,yaw)
 
 
 %% step5: Save the movie
%myWriter = VideoWriter('drone_animation', 'Motion JPEG AVI');
% myWriter = VideoWriter('drone_animation1', 'MPEG-4');
% myWriter.Quality = 100;
% myWritter.FrameRate = 120;
% 
% % Open the VideoWriter object, write the movie, and class the file
% open(myWriter);
% writeVideo(myWriter, movieVector);
% close(myWriter); 