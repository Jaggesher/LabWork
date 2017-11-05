clc, clear, close all;

Img=imread('RakulPreet.jpg');
Img=rgb2gray(Img);

threshold=Img>150;


%Ploting Area.
row=1;
col=2;
subplot(row,col,1);
imshow(Img);
title('Original Image');

subplot(row,col,2);
imshow(threshold);
title('threshold Image');






