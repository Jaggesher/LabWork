clc, clear, close all;

Img=imread('sobel.tif');

%Img=imread('RakulPreet.jpg');
%Img=rgb2gray(Img);


H_Image=zeros(size(Img));
V_Image=zeros(size(Img));

%Padarray with zeros
A=padarray(Img,[1,1]);
A=double(A);

[row,column]=size(A);

for i=2:row-1
    for j=2:column-1
        H_Image(i-1,j-1)=-1*A(i-1,j-1)-2*A(i-1,j)-1*A(i-1,j+1)+0*A(i,j-1)+0*A(i,j)+0*A(i,j+1)+1*A(i+1,j-1)+2*A(i+1,j)+1*A(i+1,j+1);
        V_Image(i-1,j-1)=-1*A(i-1,j-1)+0*A(i-1,j)+1*A(i-1,j+1)-2*A(i,j-1)+0*A(i,j)+2*A(i,j+1)-1*A(i+1,j-1)+0*A(i+1,j)+1*A(i+1,j+1);
    end
end


%Enhance Image

S_Image = sqrt(H_Image.^2+V_Image.^2);
H_Image=uint8(H_Image);
V_Image=uint8(V_Image);
S_Image=uint8(S_Image);

%Ploting Area.
row=2;
col=2;
subplot(row,col,1);
imshow(Img);
title('Original Image');

subplot(row,col,2);
imshow(H_Image);
title('Sobel Image for horizontally');

subplot(row,col,3);
imshow(V_Image);
title('Sobel Image for vertically');

subplot(row,col,4);
imshow(S_Image);
title('Gradient Image');



