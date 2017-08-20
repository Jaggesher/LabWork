clear all;
Fs = 100 ;
T = 1/Fs ;
f = 0.3 ;
dt = 0:T:50-T ; 

subplot(211);
y = 5 * sin(2*pi*f*dt) ;
y(y<0) = 0; % if the value is <0 then it is 0

plot(dt,y);
axis([xlim -.2 5.1]);  %showing y axis from -.2 5.1
xlabel('time (sec)'); ylabel('amplitude');
title('A positive value sine signal');
