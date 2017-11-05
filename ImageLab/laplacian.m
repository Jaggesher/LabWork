clc, clear, close all;

Img=imread('laplacian.tif');

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
        H_Image(i-1,j-1)=0*A(i-1,j-1)-1*A(i-1,j)+0*A(i-1,j+1)-1*A(i,j-1)+4*A(i,j)-1*A(i,j+1)+0*A(i+1,j-1)-1*A(i+1,j)+0*A(i+1,j+1);
        V_Image(i-1,j-1)=-1*A(i-1,j-1)-1*A(i-1,j)-1*A(i-1,j+1)-1*A(i,j-1)+8*A(i,j)-1*A(i,j+1)-1*A(i+1,j-1)-1*A(i+1,j)-1*A(i+1,j+1);
    end
end
H_Image=uint8(H_Image);
V_Image=uint8(V_Image);

%Enhance Image

S_Image = Img + H_Image;

%Ploting Area.
row=2;
col=2;
subplot(row,col,1);
imshow(Img);
title('Original Image');

subplot(row,col,2);
imshow(H_Image);
title('Laplace Image for horizontally');

subplot(row,col,3);
imshow(V_Image);
title('Laplace Image for vertically');

subplot(row,col,4);
imshow(S_Image);
title('Sharpening Image');



