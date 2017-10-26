%img=imread('cameraman.tif');

img=imread('RakulPreet.jpg');
img=rgb2gray(img);
img2=img;

freq= zeros(1,256);
[r,c]=size(img);
n=r*c;

for i=1:size(img,1)
    for j=1:size(img,2)
        pos= img(i,j)+1;
        freq(pos)= freq(pos) + 1;
    end
end

pdf=zeros(1,256);
for i=1:256
    pdf(i)=freq(i)/n;
end

cdf=zeros(1,256);
cdf(1)=pdf(1);
new=zeros(1,256);
new(1)=floor(cdf(1)*255);
for i=2:256;
    cdf(i)=cdf(i-1)+pdf(i);
    new(i)= floor(cdf(i)*255);
end

for i=1:size(img2,1)
    for j=1:size(img2,2)
        temp=img2(i,j)+1;
        img2(i,j)= new(temp);
    end
end

eqhis=zeros(1,256);

for i=1:size(img2,1)
    for j=1:size(img2,2)
        pos= img2(i,j)+1;
        eqhis(pos)= eqhis(pos) + 1;
    end
end

subplot(2,2,1)
imshow(img);
title('Original Image');

subplot(2,2,2);
stem(freq  , 'marker','none');
title('Histogram');

subplot(2,2,3)
imshow(img2);
title('Equalize Image');

subplot(2,2,4);
stem(eqhis  , 'marker','none');
title('Eualize Histogram');


