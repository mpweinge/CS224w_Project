import networkx as nx# sudo pip install networkx
import file_reader
import community
import matplotlib.pyplot as plt

def isPac(id):
	return id[0:2] == 'C0'

# returns, for each candidate:
# numpacs, number of direct donors, numebr of direct+indirect donors, 
# nclique overlap for everything, nclique overlap for pacs
def nCliqueOverlap(G, candidates):
	toReturn = {} 
	for i in candidates:
		toReturn[i] = [] 
	# edge (i, j) means that i donated to j.
	allPacs = set([])
	# first, find all pacs that donated to the candidates of interest. (exists edge )
	for node in G.nodes():
		if not isPac(node): continue
		donatedTo = set([i[1] for i in G.out_edges(node)])
		for candidate in candidates:
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
			if recipient not in candidates: continue
			pacCandidateDonationPercents[pac][recipient] = float(G[pac][recipient]['weight']) / totalPacDonationAmount


	# for each candidate of interest
		# calculate total # donors
		# find all their connected PACs
			# find all people who donate to that PACs
			# that is their clique
	candidateDonors = {} # candidate ID -> set of donors
	for candidate in candidates:
		indirectDonationAmt = 0
		directDonationAmt = 0
		print candidate
		curDonors  = [i[0] for i in G.in_edges(candidate, data=True) if not isPac(i[0])]
		curNumDonors = float(len(curDonors))
		directDonationAmt = sum([i[2]['weight'] for i in G.in_edges(candidate, data=True) if not isPac(i[0])])
		pacs = [i for i in G.in_edges(candidate, data=True) if isPac(i[0])]
		toReturn[candidate].append(len(pacs)) # number of pacs
		toReturn[candidate].append(len(set(curDonors))) # number of individual direct donor
		print '# of PACs: ', str(len(pacs))
		print 'direct donation amount: ', str(directDonationAmt)
		print '# of individual donors: ', str(len(set(curDonors)))
		for pac in pacs:
			curDonors.append(pac[0])
			for pacDonor in G.in_edges(pac[0], data=True):
				if isPac(pacDonor): continue
				curDonors.append(pacDonor[0])
				indirectDonationAmt += pacDonor[2]['weight'] * pacCandidateDonationPercents[pac[0]][candidate]
			curNumDonors += pacCandidateDonationPercents[pac[0]][candidate] * len(G.in_edges(pac[0]))
		print '# of individual donors counting indirect: ', str(len(set(curDonors)))
		toReturn[candidate].append(len(set(curDonors))) # number of individual direct+indirect donor
		print 'total donation amount: ', str(indirectDonationAmt + directDonationAmt), '\n\n'
		candidateDonors[candidate] = curDonors

	NCliqueOverlapPac = {} 
	NCliqueOverlapAll = {} 
	for di in range(len(candidates)):
		NCliqueOverlapAll[candidates[di]] = []
		NCliqueOverlapPac[candidates[di]] = []

	for di in range(len(candidates)):
		iAll = set(candidateDonors[candidates[di]])
		iPacOnly = set([i for i in iAll if isPac(i)])
		for dj in range(di + 1, len(candidates)):
			jAll = set(candidateDonors[candidates[dj]])
			jPacOnly = set([i for i in jAll if isPac(i)])
			jaccardAll = float(len(iAll & jAll)) / (len(iAll | jAll))
			jaccardPac = float(len(iPacOnly & jPacOnly)) / (len(iPacOnly | jPacOnly))
			print candidates[di], candidates[dj]
			NCliqueOverlapAll[candidates[di]].append(jaccardAll)
			NCliqueOverlapPac[candidates[di]].append(jaccardPac)
			NCliqueOverlapAll[candidates[dj]].append(jaccardAll)
			NCliqueOverlapPac[candidates[dj]].append(jaccardPac)
			print 'all: ', jaccardAll, ' / pac: ', jaccardPac

	for i in candidates:
		print i
		toReturn[i].append(round(sum(NCliqueOverlapAll[i]) / len(NCliqueOverlapAll[i]),4))
		toReturn[i].append(round(sum(NCliqueOverlapPac[i]) / len(NCliqueOverlapPac[i]),4))
		print 'n-clique overlap for all donors: ', round(sum(NCliqueOverlapAll[i]) / len(NCliqueOverlapAll[i]),4)
		print 'n-clique overlap for pacs: ', round(sum(NCliqueOverlapPac[i]) / len(NCliqueOverlapPac[i]),4)

	return toReturn
	# find pairwise overlap between candidates' cliques (jaccard similarity)


#obamaTag = "C00431445";
#clintonTag = "C00431569";
#edwardsTag = "C00431205";
#bidenTag = "C00431916";
#doddTag = "C00431379";
#gravelTag = "C00423202";
#kucinichTag = "C00430975";
#richardsonTag = "C00431577";


#gg = nx.DiGraph() # non-directed graph: must be non-directed for com
#donorFile = "../CS224w_Project/2007_2008/itcont.txt"
#committeeFile = "../CS224w_Project/2007_2008/itoth.txt"
#cnFile = "../CS224w_Project/2007_2008/cn.txt"
#itpasFile = "../CS224w_Project/2007_2008/itpas2.txt"


#file_reader.readInDonors(gg, '01012008', donorFile)
#file_reader.readCommitteeToCommittee(gg, committeeFile)
#file_reader.readCommitteeToCandidate(gg, itpasFile, cnFile)


#stats = nCliqueOverlap(gg, [obamaTag, clintonTag, edwardsTag, bidenTag, doddTag, gravelTag, kucinichTag, richardsonTag])


#print stats
















