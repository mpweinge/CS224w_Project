import networkx as nx# sudo pip install networkx
import file_reader

G = nx.DiGraph() #directed graph

file_reader.readInDonors(G)
file_reader.readCommitteeToCommittee(G)
weightedPR = nx.pagerank(G)
for candidate in dems2008.keys():
	print dems2008[candidate], weightedPR[candidate] 
