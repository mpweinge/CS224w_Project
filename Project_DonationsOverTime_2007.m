%Project_DonationsOverTime
Gravel =[700	6025	10662	26720	59375	71087	93557	109962	122867	149131	168471	184663];
Kucinich = [14200	46750	116256	180115	237360	312877	384665	537518	677850	762515	1002957	1127750];
Edwards = [2356098	4526692	12089986	12895815	13925930	17879160	18219699	18822029	21934931	22407113	28288946	32988769];
Dodd = [40152	3752579	8720324	8950774	9138473	11885086	12001986	12139836	13247670	13530905	14050112	15729249];
Obama = [1216597	4397869	20169301	24927807	32618291	45038019	46750674	50630696	59539282	61695638	65970601	72713998];
Clinton = [4058299	7853800	34392482	36715901	42210894	59587043	61541637	67328584	83367574	89146842	95985303	106423137];
Richardson = [356910	2616310	5643278	6890820	8259251	11274852	11928595	12468373	15102979	15652401	16614837	18954294];
Biden = [1676299	3719089	5802547	5988672	6288997	8014866	8249390	8810390	9444199	9754473	10294347	11901618];

XLabels = ['JFMAMJJASOND'];

X = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12];

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
set(gca,'XtickLabel',str2mat('Jan','Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec' ))
title('Value of Donations over Time', 'FontSize', 24)
set(gca,'fontsize',16)
ylabel('Total value of donations ($)', 'FontSize', 24);
xlabel('Months of 2007', 'FontSize', 24);
xlim([1,12])