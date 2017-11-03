clc, clear, close all;

Img= imread('lena512color.tiff');   %Main Image
Img=rgb2gray(Img);
Noise_Img = imnoise(Img,'salt & pepper');

%fft_Img=fft2(Noise_Img);

fft_Img=fft2(Noise_Img);
fft_shift_Img= fftshift(fft_Img);

ObservePSNR=zeros(1,29);

D = 25; %Cut Off

[ir,ic] = size(Noise_Img); 
hr = (ir-1)/2; 
hc = (ic-1)/2; 
[x, y] = meshgrid(-hc:hc, -hr:hr);
for i=1:29
   
    c =1./(1+((x.^2+y.^2)/D)^(2*i));
  
    blpf= fft_shift_Img .* c;
    Re_Img= mat2gray(abs(ifft2(blpf)));
   
    %PSNR CAL
    maxValue = double(max(Noise_Img(:)));
    mseImage = (double(Noise_Img) - double(Re_Img)) .^ 2;
    [rows columns] = size(Noise_Img);   
    mse = sum(mseImage(:)) / (rows * columns);
    ObservePSNR(i) = 10 * log10( 256^2 / mse);
end

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
imshow(mat2gray(log(1+abs(fft_shift_Img))));
title('FFT Shift Image');

subplot(row,col,4);
plot(ObservePSNR);
ylabel('PSNR')
xlabel('Order Of filter')
title('PSNR');



 








