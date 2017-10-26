img=imread('moon.tif');
%img=imread('RakulPreet.jpg');
%img=rgb2gray(img);
ngimg=img;
for i=1:size(img,1)
    for j=1:size(img,2)
        ngimg(i,j) = 255-img(i,j);
    end
end
subplot(1,2,1)
imshow(img);
title('Original Image');
subplot(1,2,2);
imshow(ngimg);
title('Negative Image');