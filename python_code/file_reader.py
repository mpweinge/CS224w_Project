import networkx as nx# sudo pip install networkx
import random

donorFile = "../CS224w_Project/2007_2008/itcont.txt"
committeeFile = "../CS224w_Project/2007_2008/itoth.txt"

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

# returns true if first date is earlier than first date.
# e.g. dateLater("04032007", "04042007") = True.
def dateEarlier(first, second):
	if len(first) < 8 or len(second) < 8: return False
	if first[-4:] < second[-4:]: return True
	if first[-4:] > second[-4:]: return False
	if first[0:2] < second[0:2]: return True
	if first[0:2] > second[0:2]: return False
	return first[2:4] < second[2:4]
# p is the probability of adding the new node to the graph.
# weighted is whether or not to use weights.
def readInDonors(G, maxDate=None):
	weights_so_far = {} # "(n1name, n2name) -> weight"
	num_lines = 0
	num_negative_amount = 0
	for line in open(donorFile):
		num_lines += 1
		line = line.split('|')
		date = line[13]
		if maxDate is not None and not dateEarlier(date, maxDate): 
			continue
		committeeId = line[0]
		name = line[7]
		if len(name.split(",")) < 2: continue
		name = name.split(" ")[0] + name.split(",")[1].strip().split(" ")[0]
		zipCode = line[10]
		amount = int(line[14])
		donorId = name + zipCode
		if amount < 0: 
			num_negative_amount += 1
			continue
		else: 
			key = (donorId, committeeId)
			weights_so_far[key] = weights_so_far[key] + amount if key in weights_so_far else amount
			G.add_weighted_edges_from([(donorId, committeeId, weights_so_far[key])])

def readCommitteeToCommittee(G, maxDate=None): 
	num_lines = 0
	num_negative_amount = 0
	weights_so_far = {}
	for line in open(committeeFile):
		num_lines += 1
		line = line.split('|')
		id1 = line[0]
		date = line[13]
		if maxDate is not None and not dateEarlier(date, maxDate): 
			continue
		amount = int(line[14])
		if amount < 0:
			num_negative_amount += 1
		else:
			id2 = line[15]
			key = (id1, id2)
			weights_so_far[key] = weights_so_far[key] + amount if key in weights_so_far else amount
			G.add_weighted_edges_from([(id1, id2, weights_so_far[key])])
