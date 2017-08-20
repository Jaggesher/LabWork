%I didn't get the problem properly. That's why I'm not sure about the
%solution
%%
clear all;
MSG1 = 'Enter the following data--> '
m = input('mass(m): ');
x1 = input('Initial position(x1): ');
x2 = input('Velocity(x2): ');
F = input('Given Force(F): ');
k = input('Spring constant: ');
c = input('Damping constant: ');

%Calculating acceleration
Acceleration = -((k * x1) / m)-((c * x2) /m)+(F / m);

%Showing output
Acceleration