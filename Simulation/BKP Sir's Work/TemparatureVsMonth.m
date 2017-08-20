% Declaring months
Month = {'January' 'February' 'March' 'April' 'May' 'June' 'July' 'August' 'September' 'October' 'November' 'December'};

% Declaring temparature in every month
Tem = [12 14 25 24 28 33 36 32 22 24 20 18];

% Plotting 12 months vs temparature graph
plot(1:12,Tem);
xlabel('Months'); ylabel('Temparature'); 
title('Temparature flow in every month');

% Setting months name in X axis
set(gca,'xtick',1:12,'xticklabel',Month);