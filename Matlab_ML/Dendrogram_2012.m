%Candidate dendrogram 2011

Dist = [171,325,118,233,444,28,0,206,6,380,79,20,123,88,1,477,3,126,52,212,86,1,538,7,29,47,41,0,172,22,80,7,0,36,1,21,0,107,4,0,140,2,4,0,16];

Dist = 1./Dist;

squareform(Dist)

Z = linkage(Dist);

[H, T] = dendrogram(Z);
% get the handle of the axis
hAxis = get(H(1),'parent');
% Get the permutation of the nodes
perm=str2num(get(hAxis,'XtickLabel'));
% label data
labels = {'Romney', 'Santorum', 'Gingrich', 'Paul','Hunstman', 'Perry', 'Bachmann', 'Roemer', 'Cain', 'Johnson'};
% Create the XTickLabels
set(hAxis,'XTickLabel',labels(perm))
set(gca,'fontsize',16)
ylabel(' Inverse of PAC/donors in common')
title('Dendrogram from PACs/Donors in Common')