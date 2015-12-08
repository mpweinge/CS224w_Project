Dist = [23,11,9,11,2,6,13,16,26,40,2,8,33,9,9,2,7,11,21,2,7,20,2,7,22,2,2,8]

Dist = 1./Dist

squareform(Dist)
Z = linkage(Dist)

[H, T] = dendrogram(Z);
% get the handle of the axis
hAxis = get(H(1),'parent');
% Get the permutation of the nodes
perm=str2num(get(hAxis,'XtickLabel'));
% label data
labels = {'Obama', 'Clinton', 'Edwards', 'Biden', 'Dodd', 'Gravel', 'Kucinich', 'Richardson'};
% Create the XTickLabels
set(hAxis,'XTickLabel',labels(perm))
set(gca,'fontsize',22)
ylabel(' Inverse of PAC/donors in common')
title('Dendrogram from PACs/Donors in Common')