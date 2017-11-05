clc, clear, close all;

Img=imread('smooth.tif');

%Img=imread('RakulPreet.jpg');
%Img=rgb2gray(Img);
Avg=size(Img);
WtAvg=size(Img);

%Padarray with zeros
A=padarray(Img,[1,1]);
A=double(A);

AvgBOX=[1 1 1; 1 1 1; 1 1 1]*(1/9); %3*3 box mask
WegBOX=[1 2 1; 2 4 2; 1 2 1]*(1/16); %3*3 weighted average mask
[row,column]=size(A);
for i=2:row-1
    for j=2:column-1
         Avg(i-1,j-1)=(AvgBOX(1,1)*A(i-1,j-1))+(AvgBOX(1,2)*A(i-1,j))+(AvgBOX(1,3)*A(i-1,j+1))+(AvgBOX(2,1)*A(i,j-1))+(AvgBOX(2,2)*A(i,j))+(AvgBOX(2,3)*A(i,j+1))+(AvgBOX(3,1)*A(i+1,j-1))+(AvgBOX(3,2)*A(i+1,j))+(AvgBOX(3,3)*A(i+1,j+1));
        WtAvg(i-1,j-1)=(WegBOX(1,1)*A(i-1,j-1))+(WegBOX(1,2)*A(i-1,j))+(WegBOX(1,3)*A(i-1,j+1))+(WegBOX(2,1)*A(i,j-1))+(WegBOX(2,2)*A(i,j))+(WegBOX(2,3)*A(i,j+1))+(WegBOX(3,1)*A(i+1,j-1))+(WegBOX(3,2)*A(i+1,j))+(WegBOX(3,3)*A(i+1,j+1));
    end
end


%Ploting Area.
row=2;
col=2;
subplot(row,col,1);
imshow(Img);
title('Original Image');

subplot(row,col,2);
imshow(Avg);
title('Avarage');

subplot(row,col,3);
imshow(WtAvg);
title('Weighted Avarage');





