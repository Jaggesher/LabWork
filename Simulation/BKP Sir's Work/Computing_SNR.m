Fs = 1000 ;
T = 1/Fs ;
f = 5 ;
dt = 0:T:1-T ; 
s = 5 * sin(2*pi*f*dt) ;    % original signal
n = wgn(1,length(dt),0);    % noise signal
x = s + n;                  % noisy signal
subplot(311); 
plot(dt,s); title('Original Singnal');
subplot(312); 
plot(dt,n); title('Gaussian Noise Signal');
subplot(313);
plot(dt,x); title('Noisy Signal');

SNR = snr(s,n)