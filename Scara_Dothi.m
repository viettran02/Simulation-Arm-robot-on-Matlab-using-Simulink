l1 = 320;
l2 = 330;
l3 = 185;
% Tạo figure mới để vẽ
figure('Name', 'Khong gian hoat dong cua Scara Robot');
for t1 = -2*pi/3:0.1:2*pi/3
    for t2 = -4*pi/5:0.1:4*pi/5
        x = -l3*sin(t1 + t2) -l2*sin(t1);
        y =  l3*cos(t1+t2) + l2*cos(t1);
        z =  l1;
        plot3(x, y, z, '*');
        hold on
    end
end
% Đặt tên cho các trục
grid on;
grid minor;

xlabel('X Axis');
ylabel('Y Axis');
zlabel('Z Axis');

