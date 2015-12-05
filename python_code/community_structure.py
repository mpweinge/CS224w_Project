import networkx as nx# sudo pip install networkx
import file_reader
import community
import matplotlib.pyplot as plt


G = nx.Graph() # non-directed graph: must be non-directed for com

file_reader.readInDonors(G, 1.0, False)
file_reader.readCommitteeToCommittee(G)

for node in G.nodes():
	deg = float(G.degree(node, weight='weight'))
	if deg < 0:
		break

#first compute the best partition
partition = community.best_partition(G)

#drawing
size = float(len(set(partition.values())))
# there are 756 communities

candidate_ids = {} 
for line in open('../CS224w_Project/2007_2008/cn.txt'):
	line = line.split('|')
	candidate_ids[line[9]] = line[1]


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


nodes_so_far = 0
candidates_per_community = []
pacs_per_community = [] 
community_size = []
for com in set(partition.values()) :
    list_nodes = [nodes for nodes in partition.keys() if partition[nodes] == com]
    num_candidates = 0
    num_pacs = 0
    for node in list_nodes:
    	if node[0:2] == 'C0': num_pacs += 1
    	if node in candidate_ids: num_candidates += 1
    	if node in dems2008:
    		print dems2008[node]
    print len(list_nodes)
    candidates_per_community.append(num_candidates)
    community_size.append(len(list_nodes))
    pacs_per_community.append(num_pacs)
    nodes_so_far += len(list_nodes)
    #print nodes_so_far, ",", G.number_of_nodes()

log_community_size = [math.log(i, 10) for i in community_size]
plt.hist(log_community_size, 50)
plt.xlabel("log base 10 of community size")
plt.ylabel("frequency")
plt.title("histogram of community size")
plt.show()

log_candidates_per_community = []
for i in candidates_per_community:
	if i > 1:
		log_candidates_per_community.append(math.log(i,10))

plt.hist(log_candidates_per_community, 50)
plt.xlabel("log base 10 of candidates per community (excluding 0 and 1-candidate communities)")
plt.ylabel("number of commnities")
plt.title("histogram of candidates per community")
plt.show()


nx.draw_networkx_edges(G,pos, alpha=0.5)
plt.show()