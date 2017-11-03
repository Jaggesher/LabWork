clc, clear, close all;

Img= imread('lena512color.tiff');   %Main Image
Img=rgb2gray(Img);
Noise_Img = imnoise(Img,'salt & pepper');

%fft_Img=fft2(Noise_Img);

fft_Img=fft2(Img);
fft_shift_Img= fftshift(fft_Img);

[ir,ic] = size(Img); 
hr = (ir-1)/2; 
hc = (ic-1)/2; 
[x, y] = meshgrid(-hc:hc, -hr:hr);
z = sqrt(x.^2+y.^2);

c= z<25; %Cut Off 

lpf= fft_shift_Img .* c;

Re_Img= mat2gray(abs(ifft2(lpf)));

%Ploting Area.
row=2;
col=2;
subplot(row,col,1);
imshow(Img);
title('Original Image');

subplot(row,col,2);
imshow(Noise_Img);
title('Noisy Image');

subplot(row,col,3);
imshow(mat2gray(log(1+abs(lpf))));
title('Low pass Filter');

subplot(row,col,4);
imshow(Re_Img);
title('Reconstruect Image');

%subplot(row,col,3);
%figure;
%imshow(mat2gray(log(1+abs(fft_shift_Img))));
%title('FFT Shift Image');










