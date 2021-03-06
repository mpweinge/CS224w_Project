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


def checkDate(transactionDate, endDate):
	if (len(transactionDate) != 8 or len(endDate) != 8): return False
	if ( transactionDate[4:8] < endDate[4:8] ):
		return True
  	elif (transactionDate[len(transactionDate) - 1] == endDate[len(endDate) - 1]):
	    # Compare the months aka the first two years
	    month1 = transactionDate[0] + transactionDate[1]
	    month2 = endDate[0] + endDate[1]
	    
	    iMonth1 = int(month1)
	    iMonth2 = int(month2)
	    
	    if (iMonth1 < iMonth2):
	      return True
	    else:
	      return False
	    
	else:
	    return False

# p is the probability of adding the new node to the graph.
# Add a parameter here 'date' to determine whether the date of the transaction
# is before or after a certain date
# weighted is whether or not to use weights.
def readInDonors(G, endDate, donorfile):
	weights_so_far = {} # "(n1name, n2name) -> weight"
	num_lines = 0
	num_negative_amount = 0
	for line in open(donorfile):
		num_lines += 1
		line = line.split('|')
		committeeId = line[0]
		name = line[7]
		
		date = line[13]

		if (not checkDate(date, endDate)): 
			continue

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
			# find donor and committee, add edge from donor to committee.

def readCommitteeToCandidate(G, itpasfile, cnFile, endDate):
	candidate_to_committee = {} 
	for line in open(cnFile):
		line = line.split('|')
		committee = line[9]
		candidate = line[0]
		candidate_to_committee[candidate] = committee

	for line in open(itpasfile):
		line = line.split('|')
		donorCommittee = line[0]
		recipientCandidate = line[16]
		if recipientCandidate in candidate_to_committee:
			recipientCommittee = candidate_to_committee[line[16]]
		else: 
			recipientCommitee = line[15]
		amount = int(line[14])
		date = line[13]
		if (not checkDate(date, endDate)): 
			continue
		if amount >= 0:
			G.add_weighted_edges_from([(donorCommittee, recipientCommittee, amount)])

def readCommitteeToCommittee(G, committeefile, endDate): 
	num_lines = 0
	num_negative_amount = 0
	weights_so_far = {}
	for line in open(committeefile):
		num_lines += 1
		line = line.split('|')
		id1 = line[0]
		date = line[13]
		if (not checkDate(date, endDate)): 
			continue
		amount = int(line[14])
		if amount < 0:
			num_negative_amount += 1
		else:
			id2 = line[15]
			key = (id1, id2)
			weights_so_far[key] = weights_so_far[key] + amount if key in weights_so_far else amount
			G.add_weighted_edges_from([(id1, id2, weights_so_far[key])])
