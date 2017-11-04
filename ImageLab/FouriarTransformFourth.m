clc, clear, close all;

Img= imread('lena512color.tiff');   %Main Image
Img=rgb2gray(Img);

%Noise_Img = imnoise(Img,'salt & pepper');

%fft_Img=fft2(Noise_Img);

fft_Img=fft2(Img);
fft_shift_Img= fftshift(fft_Img);

[ir,ic] = size(Img); 
hr = (ir-1)/2; 
hc = (ic-1)/2; 
D=55; %Cut Off

%Ideal Low Pass & High Pass
[x, y] = meshgrid(-hc:hc, -hr:hr);
z = sqrt(x.^2+y.^2);
Low = z<=D;
High= z>=D;

lpf= fft_shift_Img .* Low;
Re_Img_Ilpf= mat2gray(abs(ifft2(lpf)));

hpf= fft_shift_Img .* High;
Re_Img_Ihpf= mat2gray(abs(ifft2(hpf)));

%Butterworth Low Pass & High Pass
n=3;%Order
[x, y] = meshgrid(-hc:hc, -hr:hr);
Low = 1./(1.+(((x.^2+y.^2).^0.5)./D).^(2*n));
High= 1./(1.+(D./(x.^2+y.^2).^0.5).^(2*n));

lpf= fft_shift_Img .* Low;
Re_Img_Blpf= mat2gray(abs(ifft2(lpf)));

hpf= fft_shift_Img .* High;
Re_Img_Bhpf= mat2gray(abs(ifft2(hpf)));


%Gaussian Low Pass & High Pass

[x, y] = meshgrid(-hc:hc, -hr:hr);
Low = exp(-(x.^2+y.^2)/(2*D^2));
High= 1.-Low;

lpf= fft_shift_Img .* Low;
Re_Img_Glpf= mat2gray(abs(ifft2(lpf)));

hpf= fft_shift_Img .* High;
Re_Img_Ghpf= mat2gray(abs(ifft2(hpf)));


%Ploting Area.
row=2;
col=4;
subplot(row,col,1);
imshow(Img);
title('Original Image');

subplot(row,col,2);
imshow(mat2gray(log(1+abs(fft_shift_Img))));
title('FFT Shift Image');

subplot(row,col,3);
imshow(Re_Img_Ilpf);
title('Ideal Low Pass Filtered Image');

subplot(row,col,4);
imshow(Re_Img_Ihpf);
title('Ideal High Pass Filtered Image');

subplot(row,col,5);
imshow(Re_Img_Blpf);
title('Butterworth Low Pass Filtered Image');

subplot(row,col,6);
imshow(Re_Img_Bhpf);
title('Butterworth High Pass Filtered Image');

subplot(row,col,7);
imshow(Re_Img_Glpf);
title('Gaussian Low Pass Filtered Image');

subplot(row,col,8);
imshow(Re_Img_Ghpf);
title('Gaussian High Pass Filtered Image');


