%img=imread('cameraman.tif');

img=imread('RakulPreet.jpg');
img=rgb2gray(img);
freq= zeros(1,256);

for i=1:size(img,1)
    for j=1:size(img,2)
        pos= img(i,j)+1;
        freq(pos)= freq(pos) + 1;
    end
end

subplot(1,2,1)
imshow(img);
title('Original Image');

subplot(1,2,2);
stem(freq  , 'marker','none');
title('Histogram');

