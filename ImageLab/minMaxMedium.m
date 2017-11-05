clc, clear, close all;

Img=imread('median.tif');

%Img=imread('RakulPreet.jpg');
%Img=rgb2gray(Img);
Min=Img;
Max=Img;
Median=Img;

%Index for 3*3
hc=1;
hr=1;
[x, y] = meshgrid(-hc:hc, -hr:hr);
 
[row,column]=size(Img);

for i=1:row
    for j=1:column
        mn=inf;
        mx=0;
        Temp=zeros(1,9);
        index=0;
        for l=1:3
            for m=1:3
                index=index+1;
                if((i+l)>=1 && (i+l)<=row && (j+m)>=1 && (j+m)<=column)
                    mn=min(mn,Img(i+l,j+m));
                    mx=max(mx,Img(i+l,j+m));
                    Temp(index)=Img(i+l,j+m);
                end
            end
        end
        Min(i,j)=mn;
        Max(i,j)=mx;
        Temp=sort(Temp);
        Median(i,j)=Temp(5);%Middle Value
    end
end


%Ploting Area.
row=2;
col=2;
subplot(row,col,1);
imshow(Img);
title('Original Image');

subplot(row,col,2);
imshow(Max);
title('Max');

subplot(row,col,3);
imshow(Min);
title('Min');

subplot(row,col,4);
imshow(Median);
title('Median');



