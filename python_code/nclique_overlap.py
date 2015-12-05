import networkx as nx# sudo pip install networkx
import file_reader
import community
import matplotlib.pyplot as plt

G = nx.DiGraph() # non-directed graph: must be non-directed for com

file_reader.readInDonors(G, 1.0, False)
file_reader.readCommitteeToCommittee(G)


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

def isPac(id):
	return id[0:2] == 'C0'

# edge (i, j) means that i donated to j.
allPacs = set([])
# first, find all pacs that donated to the candidates of interest. (exists edge )
for node in G.nodes():
	if not isPac(node): continue
	for candidate in dems2008.keys():
		if candidate in G[node]:
			allPacs.add(node)

pacCandidateDonationPercents = {} # pac -> candidate -> percent
# now figure out what % each pac donated to each candidate
for pac in allPacs:
	# find total amount that each pac donated to ANY candidate (including minor candidate)
	pacDonationRecipients = G[pac].keys()
	totalPacDonationAmount = sum([G[pac][recipient]['weight'] for recipient in pacDonationRecipients if isPac(recipient)])
	pacCandidateDonationPercents[pac] = {} 
	for recipient in pacDonationRecipients:
		if recipient not in dems2008.keys(): continue
		pacCandidateDonationPercents[pac][recipient] = float(G[pac][recipient]['weight']) / totalPacDonationAmount


# for each candidate of interest
	# calculate total # donors
	# find all their connected PACs
		# find all people who donate to that PACs
		# that is their clique
candidateDonors = {} # candidate ID -> set of donors
for candidate in dems2008.keys():
	indirectDonationAmt = 0
	directDonationAmt = 0
	print dems2008[candidate]
	neighbors = G[candidate].keys()
	curDonors = set([i for i in neighbors if not isPac(i) and len(i) > 1])
	curNumDonors = float(len(curDonors))
	directDonationAmt = sum([G[candidate][i]['weight'] for i in curDonors])
	pacs = set([i for i in neighbors if isPac(i)])
	print '# of PACs: ', str(len(pacs))
	print 'direct donation amount: ', str(directDonationAmt)
	print '# of individual donors: ', str(len(curDonors))
	for pac in pacs:
		curDonors.add(pac)
		for pacDonor in G[pac].keys():
			if isPac(pacDonor): continue
			curDonors.add(pacDonor)
			indirectDonationAmt += G[pac][pacDonor]['weight'] * pacCandidateDonationPercents[pac][candidate]
		curNumDonors += pacCandidateDonationPercents[pac][candidate] * len(G[pac].keys())
	print '# of individual donors counting indirect: ', str(len(curDonors))
	print 'total donation amount: ', str(indirectDonationAmt + directDonationAmt), '\n\n'
	candidateDonors[candidate] = curDonors

NCliqueOverlapPac = {} 
NCliqueOverlapAll = {} 
demsList = list(dems2008.keys())
for di in range(len(demsList)):
	NCliqueOverlapAll[demsList[di]] = []
	NCliqueOverlapPac[demsList[di]] = []

for di in range(len(demsList)):
	iAll = set(candidateDonors[demsList[di]])
	iPacOnly = set([i for i in iAll if isPac(i)])
	for dj in range(di + 1, len(demsList)):
		jAll = set(candidateDonors[demsList[dj]])
		jPacOnly = set([i for i in jAll if isPac(i)])
		jaccardAll = float(len(iAll & jAll)) / (len(iAll | jAll))
		jaccardPac = float(len(iPacOnly & jPacOnly)) / (len(iPacOnly | jPacOnly))
		print dems2008[demsList[di]], dems2008[demsList[dj]]
		NCliqueOverlapAll[demsList[di]].append(jaccardAll)
		NCliqueOverlapPac[demsList[di]].append(jaccardPac)
		NCliqueOverlapAll[demsList[dj]].append(jaccardAll)
		NCliqueOverlapPac[demsList[dj]].append(jaccardPac)
		print 'all: ', jaccardAll, ' / pac: ', jaccardPac

for i in dems2008.keys():
	print dems2008[i]
	print 'n-clique overlap for all donors: ', sum(NCliqueOverlapAll[i]) / len(NCliqueOverlapAll[i])
	print 'n-clique overlap for pacs: ', sum(NCliqueOverlapPac[i]) / len(NCliqueOverlapPac[i])

# find pairwise overlap between candidates' cliques (jaccard similarity)




















