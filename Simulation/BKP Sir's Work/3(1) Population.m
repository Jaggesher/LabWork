clear all;
%Taking the inputs
p0 = input('Enter the population at time = 0: ');
d = input('Enter time in which population will be double: ');
%Have to calculate at 5,10,15 years
t = [5 10 15];
l = length(t);
%Population 
p = ones(1,3)
for i = 1:l
    temp = pow2( t(i) / d);
    x(i) = floor( p0 * temp);
end
%Output
'The populations at 5,10 and 15 years are gradulally ' 
x

%Drawing graph
plot(t,x);
xlabel('Years(t)'); ylabel('Population');
title('Population at different years');


