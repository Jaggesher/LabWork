clear all;
%Given that
v = 128748 / 3600; %80 miles per hour
theta = 45 * (pi / 180) ; %in radian
g = 9.8 ;

% travel time of flight
Travel_time = (2 * v * sin(theta)) / g 

% distance the ball traveled
distance_traveled = v * Travel_time * cos(theta)

Fs = 100;
T = 1 / Fs;
dt = 0:T:Travel_time-T;

high = (v * dt * sin(theta)) - (.5 * g * dt.^2);
plot(dt,(high));
xlabel('Time (sec)'); ylabel('Height (meter)');
title('travel line of the object');