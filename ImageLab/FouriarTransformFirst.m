clc, clear, close all;

Img= imread('imgfft.png');   %Main Image
Img=rgb2gray(Img);

fft_Img= fft2(Img);

fft_shift_Img= fftshift(fft_Img);

fft_shift_log_Img= mat2gray(log(1+abs(fft_shift_Img)));

fft_log_img= mat2gray(log(1+abs(fft_Img)));

%Ploting Area.
subplot(3,2,1);
imshow(Img);
title('Original Image');

subplot(3,2,2);
imshow(fft_shift_log_Img);
title('With Shift & Log')

subplot(3,2,3);
imshow(fft_shift_Img);
title('With  Shift & Without Log');

subplot(3,2,4);
imshow(fft_log_img);
title('With Log && Without Shift');

subplot(3,2,5);
imshow(fft_Img);
title('Without Log &  shift');





