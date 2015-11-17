%Project_NumberOfDonationsOverTime
Gravel =[3	13	19	47	96	118	159	182	223	269	294	314];
Kucinich = [20	59	174	292	403	532	653	868	1133	1332	1842	2129];
Edwards = [1695	3478	9802	10699	11814	16248	16867	17873	22222	23278	24516	26502];
Dodd = [30	227	2811	3007	3131	5143	5350	5542	6403	6720	7143	7534];
Obama = [1293	4594	17964	24221	31686	45497	48349	52713	62641	66399	73281	84287];
Clinton = [1626	4581	15257	17047	21118	33479	35466	40406	53097	58324	64862	74209];
Richardson = [283	1817	4460	5642	7108	10196	10993	11907	14550	15210	16832	18093];
Biden = [1755	1968	3382	3567	3844	5085	5323	5859	6502	6866	7663	8427];

X = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];

close all
figure
hold on

plot (X, Gravel)
plot (X, Kucinich)
plot (X, Edwards)
plot (X, Dodd)
plot (X, Obama, 'k')
plot (X, Clinton, 'm')
plot (X, Richardson)
plot (X, Biden)

h_legend = legend('Gravel', 'Kucinich', 'Edwards', 'Dodd', 'Obama', 'Clinton', 'Richardson', 'Biden');
set(h_legend,'FontSize',16);
title('Number of Donations over Time', 'FontSize', 24)
set(gca,'fontsize',16)
ylabel('Number of donations', 'FontSize', 24);
xlabel('Months of 2007', 'FontSize', 24);