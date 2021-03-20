load('input1.mat');
load('input.mat');
interval = 10:10:n;
optiune = 1;
run('alg_GPC.m');
run('GPP.m');
run('S_REZ_G.m');
run('Kacsmarz.m');
save('timpi.mat','timpi_kaczmarz','timpi_G','timpi_GPP','timpi_GPC','interval');
gcf = figure('visible','off');
grid on;
plot(interval, timpi_kaczmarz,'r');
hold on;
plot(interval,timpi_G,'b');
hold on;
plot(interval,timpi_GPP,'m');
hold on;
plot(interval,timpi_GPC,'g');
saveas(gcf,'Andu.png');