clear all;
%Taking the inputs
p0 = input('Enter the population at time(0): ');
d = input('Enter time in which population will be double: ');
%Have to calculate at 5,10,15 years
t = [5 10 15];
l = length(t);
%Population calculation
for i = 1:l
    temp = pow2( t(i) / d);
    x(i) = floor( p0 * temp);
end
%Output
fprintf('\nThe populations at 5,10 and 15 years are gradulally \n%d %d %d\n',x(1),x(2),x(3));

%Drawing graph
hold on;
plot(t,x,'g*');
grid on;
xlabel('Years(t)'); ylabel('Population');
title('Population at different years');
