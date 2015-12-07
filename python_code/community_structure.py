import networkx as nx# sudo pip install networkx
import file_reader
import community
import matplotlib.pyplot as plt


G = nx.Graph() # non-directed graph: must be non-directed for com
donorFile = "../CS224w_Project/1995_1996/itcont.txt"
committeeFile = "../CS224w_Project/1995_1996/itoth.txt"
cnFile = "../CS224w_Project/1995_1996/cn.txt"
itpasFile = "../CS224w_Project/1995_1996/itpas2.txt"

file_reader.readInDonors(G, "01011996", donorFile)
print 'read donors'
file_reader.readCommitteeToCommittee(G, committeeFile)
file_reader.readCommitteeToCandidate(G, itpasFile, cnFile, '01011996')
print 'read committees'
#first compute the best partition
print 'made partition'

candidates = set(['C00317743','C00361352','C00343772',  'C00452532', 'C00301333',  'C00299917', 
'C00301465','C00302216'])

def community_structure(G, candidates):
    partition = community.best_partition(G)
    to_return = {}
    candidates_found = 0
    for candidate in candidates:
        to_return[candidate] = {}
    candidate_to_pacs_in_community = {}
    candidate_to_community_size = {}
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
        	if node in candidates: num_candidates += 1
        for node in list_nodes:
            if node in candidates:
                to_return[node]['community_size'] = len(list_nodes)
                to_return[node]['pacs_in_community'] = num_pacs
                candidates_found += 1
                print 'found ', node
        if (candidates_found >= len(candidates)): break
    for candidate in candidates:
        if 'community_size' not in to_return[candidate]:
            to_return[candidate]['community_size']  = 0
            print 'didnt find ',candidate
    for candidate in candidates:
        if 'pacs_in_community' not in to_return[candidate]:
            to_return[candidate]['pacs_in_community']  = 0
    return to_return

print community_structure(G, candidates)