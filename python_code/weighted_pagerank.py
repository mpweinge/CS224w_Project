import networkx as nx# sudo pip install networkx
import file_reader

minDate = "01012008"

G = nx.DiGraph() #directed graph

file_reader.readInDonors(G, 1.0, true, minDate)
file_reader.readCommitteeToCommittee(G)
weightedPR = nx.pagerank(G)
for candidate in dems2008.keys():
	print dems2008[candidate], weightedPR[candidate] 
