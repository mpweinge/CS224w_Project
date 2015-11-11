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

using namespace std;

// GLOBALS
PNGraph donorGraph;
PUNGraph undirectedDonorGraph;

unordered_map<string, int> committeeStringToNodeNumber;

unordered_map<string, int> donorStringToNodeNumber;


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
   
   for (unordered_map<string, int>::iterator committeeKeys = committeeStringToNodeNumber.begin(); committeeKeys != committeeStringToNodeNumber.end(); ++committeeKeys){
   cout << "Page rank for user: " << committeeKeys->first << " value: " << nodeToHash[committeeKeys->second] << endl;
   }
}

void computeUndirectedBetweenness() {
  // Calculate betweenness
  TIntFltH nodeBetweennessCentr;
  TSnap::GetBetweennessCentr(undirectedDonorGraph, nodeBetweennessCentr);
  
  for (unordered_map<string, int>::iterator committeeKeys = committeeStringToNodeNumber.begin(); committeeKeys != committeeStringToNodeNumber.end(); ++committeeKeys){
    cout << "Betweenness score for user: " << committeeKeys->first << " value: " << nodeBetweennessCentr[committeeKeys->second] << endl;
  }
}



int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  
  vector<candidateDonorNode> nodes;
  
  donorGraph = TNGraph::New();
  undirectedDonorGraph = TUNGraph::New();

  readInDonors(nodes, donorStringToNodeNumber, committeeStringToNodeNumber, donorGraph, undirectedDonorGraph);
  
  readCommitteeToCommitteeFile(committeeStringToNodeNumber, donorGraph, undirectedDonorGraph);

  //cout << "Clinton funds: " << committeeToAmount["C00358895"] + committeeToAmount["C00575795"] << endl;
  
  // Count the number of in edges to clinton
  //cout << "Number of edges to clinton";
  //TNGraph::TNodeI clintonIndex = donorGraph->GetNI(committeeStringToNodeNumber["C00575795"]);
  
  //cout << clintonIndex.GetInDeg() << endl;
  
  cout << "Number of edges: " << donorGraph->GetEdges() << endl;
  cout << "Number of nodes: " << donorGraph->GetNodes() << endl;
  
  // Compute pagerank for all of the nodes in our graph
   computePageRank();
  
  /*for (unordered_map<string, int>::iterator committeeKeys = committeeStringToNodeNumber.begin(); committeeKeys != committeeStringToNodeNumber.end(); ++committeeKeys){
    
    float currCloseness = TSnap::GetClosenessCentr(undirectedDonorGraph, committeeKeys->second);

    cout << "Closeness for user: " << committeeKeys->first << " value: " << currCloseness << endl;
  }*/
  
  return 0;
}
