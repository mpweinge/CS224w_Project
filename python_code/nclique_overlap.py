import networkx as nx# sudo pip install networkx
import file_reader
import community
import matplotlib.pyplot as plt

G = nx.DiGraph() # non-directed graph: must be non-directed for com

file_reader.readInDonors(G, '01012008')
file_reader.readCommitteeToCommittee(G, '01012008')


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
	donatedTo = set([i[1] for i in G.out_edges(node)])
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
	curDonors  = [i[0] for i in G.in_edges(candidate, data=True) if not isPac(i[0])]
	curNumDonors = float(len(curDonors))
	directDonationAmt = sum([i[2]['weight'] for i in G.in_edges(candidate, data=True) if not isPac(i[0])])
	pacs = [i for i in G.in_edges(candidate, data=True) if isPac(i[0])]
	print '# of PACs: ', str(len(pacs))
	print 'direct donation amount: ', str(directDonationAmt)
	print '# of individual donors: ', str(len(curDonors))
	for pac in pacs:
		curDonors.append(pac[0])
		for pacDonor in G.in_edges(pac[0], data=True):
			if isPac(pacDonor): continue
			curDonors.append(pacDonor[0])
			indirectDonationAmt += pacDonor[2]['weight'] * pacCandidateDonationPercents[pac[0]][candidate]
		curNumDonors += pacCandidateDonationPercents[pac[0]][candidate] * len(G.in_edges(pac[0]))
	print '# of individual donors counting indirect: ', str(len(set(curDonors)))
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
	print 'n-clique overlap for all donors: ', round(sum(NCliqueOverlapAll[i]) / len(NCliqueOverlapAll[i]),4)
	print 'n-clique overlap for pacs: ', round(sum(NCliqueOverlapPac[i]) / len(NCliqueOverlapPac[i]),4)

# find pairwise overlap between candidates' cliques (jaccard similarity)




















