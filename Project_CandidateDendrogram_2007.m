Dist = [23,11,9,11,2,6,13,16,26,40,2,8,33,9,9,2,7,11,21,2,7,20,2,7,22,2,2,8]

Dist = 1./Dist

squareform(Dist)
Z = linkage(Dist)

dendrogram(Z)