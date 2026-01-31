/*
This program is to plot the output file from the CH5_5.cpp program
*/

//Axis 1
a = fscanfMat('Output1');
c = color("black");
plot2d(a(:,1),a(:,2),style=c);
title('Weather Balloon Altitude');
xlabel('Time, hrs');
ylabel('Altitude, meters');

//Axis 2
d = color("blue");
h2 = newaxes();
h2.font_color = d;
plot2d(a(:,1),a(:,3),style=d);
h2.filled = "off";
h2.axes_visible(1) = "off";
h2.y_location = "right";
ylabel('Velocity, m/s',"color",d);


