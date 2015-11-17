import networkx as nx# sudo pip install networkx
import file_reader

G = nx.DiGraph() #directed graph

obamaTag = "C00431445";
clintonTag = "C00431569";
edwardsTag = "C00431205";
bidenTag = "C00431916";
doddTag = "C00431379";
gravelTag = "C00423202";
kucinichTag = "C00430975";
richardsonTag = "C00431577";

dems2008 = {obamaTag : "Barack Obama", clintonTag: "Hilary Clinton", edwardsTag: "John Edwards",
    bidenTag: "Joe Biden", doddTag: "Chris Dodd", gravelTag: "Mike Gravel",
    kucinichTag: "Dennis Kucinich", richardsonTag: "Bill Richardson"};

maxDates = ['02012007','03012007','04012007','05012007','06012007','07012007','08012007','09012007','10012007','11012007','12012007','01012008']

weightedPRs = {}
for candidate in dems2008:
	weightedPRs[candidate] = []

for maxDate in maxDates:
	file_reader.readInDonors(G, maxDate)
	file_reader.readCommitteeToCommittee(G, maxDate)
	print "For donations before ", maxDate
	print "Graph size: nodes: ", str(G.number_of_nodes()), " edges: ", str(G.number_of_edges())
	weightedPR = nx.pagerank(G)
	for candidate in dems2008.keys():
		weightedPRs[candidate].append(weightedPR[candidate])
		print dems2008[candidate], weightedPR[candidate] 

import matplotlib.pyplot as plt