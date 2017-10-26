%img=imread('cameraman.tif');

img=imread('RakulPreet.jpg');
img=rgb2gray(img);

img2=im2double(img);
img3=img2;
factor= input('Input factor = ');

for i=1:size(img2,1);
    for j=1:size(img2,2)
        img3(i,j) = factor * log(1+img2(i,j));
    end
end
subplot(1,2,1);
imshow(img2);
title('Original Image.');
subplot(1,2,2);
imshow(img3);
title('Transformed Image.');