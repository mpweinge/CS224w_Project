//
//  main.cpp
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-11-07.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

#include "constants.h"
#include "fileReader.hpp"
#include "DatabaseStatistics.hpp"

using namespace std;

// GLOBALS
PNGraph donorGraph;
PUNGraph undirectedDonorGraph;

map<string, int> committeeStringToNodeNumber;

unordered_map<string, int> donorStringToNodeNumber;

unordered_map<string, int> candidateToDonorFunds;
unordered_map<string, int> candidateToPACFunds;

unordered_map<string, int> candidateToNumberDonors;

// Data structure taken from here: http://www.fec.gov/finance/disclosure/metadata/DataDictionaryContributionsbyIndividuals.shtml

void computePageRank() {
    TIntFltH nodeToHash;
    TSnap::GetPageRank(donorGraph, nodeToHash);
    
    float maxPageRank = 0;
    int maxPageRankIndex = 0;
    
    for (int i = 0; i < donorGraph->GetNodes(); i++) {
        //cout << "Page rank for user: " << nodeToName[i] << " value: " << nodeToHash[i] << endl;
        if (nodeToHash[i] > maxPageRank) {
            maxPageRank = nodeToHash[i];
            maxPageRankIndex = i;
        }
    }
    
    //for (unordered_map<string, int>::iterator committeeKeys = committeeStringToNodeNumber.begin(); committeeKeys != committeeStringToNodeNumber.end(); ++committeeKeys){
   //     cout << "Page rank for user: " << committeeKeys->first << " value: " << nodeToHash[committeeKeys->second] << endl;
    //}
  for (int i = 0; i< numDemocraticCandidates; i++) {
    TNGraph::TNodeI node = donorGraph->GetNI(committeeStringToNodeNumber[democraticCandidates[i]]);
    
    string name = democraticCandidates[i];
    
    cout << /*demNames.find(name)->second << " pagerank, Donor, PAC, Total donations: " << */nodeToHash[node.GetId()] << "," << candidateToDonorFunds[democraticCandidates[i]] << "," << candidateToPACFunds[democraticCandidates[i]] << "," << candidateToDonorFunds[democraticCandidates[i]] +  candidateToPACFunds[democraticCandidates[i]] << endl;
  }
  
  for (int i = 0; i< numRepublicanCandidates; i++) {
    TNGraph::TNodeI node = donorGraph->GetNI(committeeStringToNodeNumber[republicanCandidates[i]]);
    
    string name = republicanCandidates[i];
    
    cout << /*repNames.find(name)->second << " pagerank, Donor, PAC, Total donations: " <<*/ nodeToHash[node.GetId()] << "," << candidateToDonorFunds[republicanCandidates[i]] << "," << candidateToPACFunds[republicanCandidates[i]] << "," << candidateToDonorFunds[republicanCandidates[i]] +  candidateToPACFunds[republicanCandidates[i]] << endl;
  }
}

void computeDonationsPerCandidate()
{
  /*for (auto candidate = demNames.begin(); candidate != demNames.end(); candidate++) {
    cout << candidate->second << " Donor, PAC, Total donations: " << candidateToDonorFunds[candidate->first] << "," << candidateToPACFunds[candidate->first] << "," << candidateToDonorFunds[candidate->first] +  candidateToPACFunds[candidate->first] << endl;
  }
  
  for (auto candidate = repNames.begin(); candidate != repNames.end(); candidate++) {
    cout << candidate->second << " Donor, PAC, Total donations: " << candidateToDonorFunds[candidate->first] << "," << candidateToPACFunds[candidate->first] << "," << candidateToDonorFunds[candidate->first] +  candidateToPACFunds[candidate->first] << endl;
  }*/
}

void computeUndirectedBetweenness() {
    // Calculate betweenness
    TIntFltH nodeBetweennessCentr;
    TSnap::GetBetweennessCentr(undirectedDonorGraph, nodeBetweennessCentr);
    
    for (map<string, int>::iterator committeeKeys = committeeStringToNodeNumber.begin(); committeeKeys != committeeStringToNodeNumber.end(); ++committeeKeys){
        cout << "Betweenness score for user: " << committeeKeys->first << " value: " << nodeBetweennessCentr[committeeKeys->second] << endl;
    }
}

/*void performHeirarchicalClustering() {
    // Perform heirarchical clustering based on distance in undirected graph
    cout << "Distances for heirarchical clustering. Candidates are in the order: 1. Obama 2. Clinton"
    << "3. Edwards 4. Biden 5. Dodd 6. Gravel 7. Kucinich 8. Richardson"
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[obamaTag], committeeStringToNodeNumber[clintonTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[obamaTag], committeeStringToNodeNumber[edwardsTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[obamaTag], committeeStringToNodeNumber[bidenTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[obamaTag], committeeStringToNodeNumber[doddTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[obamaTag], committeeStringToNodeNumber[gravelTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[obamaTag], committeeStringToNodeNumber[kucinichTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[obamaTag], committeeStringToNodeNumber[richardsonTag]) << ","
    
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[clintonTag], committeeStringToNodeNumber[edwardsTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[clintonTag], committeeStringToNodeNumber[bidenTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[clintonTag], committeeStringToNodeNumber[doddTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[clintonTag], committeeStringToNodeNumber[gravelTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[clintonTag], committeeStringToNodeNumber[kucinichTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[clintonTag], committeeStringToNodeNumber[richardsonTag]) << ","
    
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[edwardsTag], committeeStringToNodeNumber[bidenTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[edwardsTag], committeeStringToNodeNumber[doddTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[edwardsTag], committeeStringToNodeNumber[gravelTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[edwardsTag], committeeStringToNodeNumber[kucinichTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[edwardsTag], committeeStringToNodeNumber[richardsonTag]) << ","
    
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[bidenTag], committeeStringToNodeNumber[doddTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[bidenTag], committeeStringToNodeNumber[gravelTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[bidenTag], committeeStringToNodeNumber[kucinichTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[bidenTag], committeeStringToNodeNumber[richardsonTag]) << ","
    
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[doddTag], committeeStringToNodeNumber[gravelTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[doddTag], committeeStringToNodeNumber[kucinichTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[doddTag], committeeStringToNodeNumber[richardsonTag]) << ","
    
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[gravelTag], committeeStringToNodeNumber[kucinichTag]) << ","
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[gravelTag], committeeStringToNodeNumber[richardsonTag]) << ","
    
    << TSnap::GetShortPath(undirectedDonorGraph, committeeStringToNodeNumber[kucinichTag], committeeStringToNodeNumber[richardsonTag]) << "," << endl;
}*/

int numberOfPathsOfLengthTwo(int node1, int node2) {
    // Look for times that node2 is a neighbour of a neighbour
    
    int neighbourCount = 0;
    
    TUNGraph::TNodeI itNode1 = undirectedDonorGraph->GetNI(node1);
    int numEdges = itNode1.GetOutDeg();
    
    for (int i = 0; i < numEdges; i++) {
        int nbrID = itNode1.GetNbrNId(i);
        
        TUNGraph::TNodeI nbr = undirectedDonorGraph->GetNI(nbrID);
        int numNbrEdges = nbr.GetOutDeg();
        for (int j = 0; j < numNbrEdges; j++) {
            int nbrnbrID = nbr.GetNbrNId(j);
            
            if (nbrnbrID == node2) {
                neighbourCount++;
            }
        }
    }
    
    return neighbourCount;
}

void performAverageDistHeirarchicalClustering() {
    
    // Running the clustering to get 'minimum' distance gives the same value for all candidates. This is because there is often one pac in common between all candidates
    // The code above gives the output 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2
    
    // Attempt 2: Count the *instances* of pacs in common (ie. the number of different paths we get to with a distance of two
    
    // As we know that we are looking for distance '2', we can avoid doing a full BFS tree and just looking for different paths of distance '2'
    
    for (int i = 0; i < numDemocraticCandidates; i++)
    {
        for (int j = i+1; j < numDemocraticCandidates; j++) {
            cout << numberOfPathsOfLengthTwo( committeeStringToNodeNumber[democraticCandidates[i]], committeeStringToNodeNumber[democraticCandidates[j]]) << ",";
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector<candidateDonorNode> nodes;
    
    donorGraph = TNGraph::New();
    undirectedDonorGraph = TUNGraph::New();
  
  readInDonors(nodes, donorStringToNodeNumber, committeeStringToNodeNumber, donorGraph, undirectedDonorGraph, endCampaign);
  readCommitteeToCommitteeFile(committeeStringToNodeNumber, donorGraph, undirectedDonorGraph, endCampaign);
  
  readInCN();
  readInPAS(nodes, donorStringToNodeNumber, committeeStringToNodeNumber, donorGraph, undirectedDonorGraph, endCampaign);
  
 /*
  //Run this over 12 months and see how the data changes over that time
  const string end2007Campaign = "01012008";
  
  const string months2007Campaign[] = {"02012007", "03012007", "04012007", "05012007", "06012007", "07012007", "08012007", "09012007", "10012007", "11012007", "12012007", "01012008" };
  
  for (int i = 0; i < 12; i++) {
    
    candidateToFunds.clear();
    candidateToNumberDonors.clear();
    
    readInDonors(nodes, donorStringToNodeNumber, committeeStringToNodeNumber, donorGraph, undirectedDonorGraph, months2007Campaign[i]);
    readCommitteeToCommitteeFile(committeeStringToNodeNumber, donorGraph, undirectedDonorGraph, months2007Campaign[i]);
    
    cout << " i: " << i << endl;
    
    // Output the number of funds for each candidate
    for (auto candidate = demNames.begin(); candidate != demNames.end(); candidate++) {
       //float currCloseness = TSnap::GetClosenessCentr(undirectedDonorGraph, committeeStringToNodeNumber[candidate->first]);
      
     // cout << '\t' << "Candidate: " << candidate->second << " funds: " << candidateToFunds[candidate->first] << endl;
      cout << '\t' << "Candidate: " << candidate->second << " number of donations: " << candidateToNumberDonors[candidate->first] << endl;
    }
    for (auto candidate = demNames.begin(); candidate != demNames.end(); candidate++) {
      //float currCloseness = TSnap::GetClosenessCentr(undirectedDonorGraph, committeeStringToNodeNumber[candidate->first]);
      
      cout << '\t' << "Candidate: " << candidate->second << " funds: " << candidateToFunds[candidate->first] << endl;
     // cout << '\t' << "Candidate: " << candidate->second << " number of donations: " << candidateToNumberDonors[candidate->first] << endl;
    }
  }

    cout << "Number of edges: " << donorGraph->GetEdges() << endl;
    cout << "Number of nodes: " << donorGraph->GetNodes() << endl;
    cout << "donorStringToNodeNumber " << donorStringToNodeNumber.size() << endl;
    cout << "committeeStringToNodeNumber " << committeeStringToNodeNumber.size() << endl;
    
    // Count the number of in edges to clinton
    TNGraph::TNodeI clintonIndex = donorGraph->GetNI(committeeStringToNodeNumber["C00431569"]);

    cout << "Number of edges to clinton" << clintonIndex.GetInDeg() << endl;

    cout << "cstnn  " << committeeStringToNodeNumber["C00431569"] << endl;
    
    performAverageDistHeirarchicalClustering();
    
    */
    // Compute pagerank for all of the nodes in our graph
    computePageRank();
    computeDonationsPerCandidate();
  
    //cout << "Average number of donations per PAC " << getAverageNumberOfDonationsPerPAC(donorGraph) << endl;
  
    // Plot total number of donations over time
    // Plot number of donations over time 
  
  
    /*for (unordered_map<string, int>::iterator committeeKeys = committeeStringToNodeNumber.begin(); committeeKeys != committeeStringToNodeNumber.end(); ++committeeKeys) {
     float currCloseness = TSnap::GetClosenessCentr(undirectedDonorGraph, committeeKeys->second);
     cout << "Closeness for user: " << committeeKeys->first << " value: " << currCloseness << endl;
    }*/
    /*for (auto candidate = dem2008Names.begin(); candidate != dem2008Names.end(); candidate++) {
        float currCloseness = TSnap::GetClosenessCentr(undirectedDonorGraph, committeeStringToNodeNumber[candidate->first]);
        cout << candidate->second << " closeness: " << currCloseness << endl;
    }*/

    
    return 0;
}
