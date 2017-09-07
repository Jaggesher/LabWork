function spring_dumping_system()  
clear all; close all;  

time_span =0:0.001:18; %time in seconds.  
k = 40; % spring stiffness. N/m 
m = 5;  % mass, kg
x0 = [0 0]; %initial_position & initial_speed
P = 100;   % force amplitude 
f=10;  %unit step 
c=3; %damping coefficient 
 
[t,x]=ode45(@myFunction,time_span,x0); 
plot(t,x(:,1),'g'); 
ylim([-.1 .5]); 
grid on;
xlabel('time'); ylabel('Displacement');

    % solves m x''+ c x' + k x = f(t) 
    function xdot=myFunction(t,x) 
        xdot_1 = x(2); 
        xdot_2 = -(c/m)*x(2) - (k/m)*x(1) + f/m; 
 
        xdot = [xdot_1 ; xdot_2]; 
    end 
end