//
//  DatabaseStatistics.cpp
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-11-12.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#include "DatabaseStatistics.hpp"
#include "Snap.h"

float getAverageNumberOfDonationsPerIndividual()
{
  // TODO: Fix this once I fix the map with the key
  return 0.0;
}


float getAverageNumberOfDonationsPerPAC(PNGraph & graph)
{
  // Go through our pacs and see how many out edges they have
  int totalEdges = 0;
  int totalPacs = 0;
  
  for (unordered_map<string, int>::iterator committeeKeys = committeeStringToNodeNumber.begin(); committeeKeys != committeeStringToNodeNumber.end(); ++committeeKeys){
    TNGraph::TNodeI currNode = graph->GetNI(committeeKeys->second);
    totalEdges += currNode.GetOutDeg();
    totalPacs++;
  }
  
  return ((float)totalEdges) / totalPacs;
}

int getNumberOfEdges(TNGraph & graph)
{
  return graph.GetEdges();
}

int getNumberOfCommittees()
{
  return committeeStringToNodeNumber.size();
}

float averageOutDegreePerCandidate(TNGraph & graph)
{
  // Go through our 8 democratic candidates and get their out degree
  
  //const string democraticCandidates2008[] = {obamaTag, clintonTag, edwardsTag, bidenTag, doddTag, gravelTag, kucinichTag, richardsonTag};
  //const int numDemocraticCandidates2008 = 8;
  int totalOutDegrees = 0;
  
  for (int i = 0; i < numDemocraticCandidates2008; i++)
  {
    TNGraph::TNodeI currNode = graph.GetNI(committeeStringToNodeNumber[democraticCandidates2008[i]]);
    totalOutDegrees += currNode.GetOutDeg();
  }
  
  return ((float) totalOutDegrees) / numDemocraticCandidates2008;
}

float averageInDegreePerCandidate(TNGraph & graph)
{
  //const string democraticCandidates2008[] = {obamaTag, clintonTag, edwardsTag, bidenTag, doddTag, gravelTag, kucinichTag, richardsonTag};
  //const int numDemocraticCandidates2008 = 8;
  int totalInDegrees = 0;
  
  for (int i = 0; i < numDemocraticCandidates2008; i++)
  {
    TNGraph::TNodeI currNode = graph.GetNI(committeeStringToNodeNumber[democraticCandidates2008[i]]);
    totalInDegrees += currNode.GetInDeg();
  }
  
  return ((float) totalInDegrees) / numDemocraticCandidates2008;
}

// Some candidates donate to other candidates
float getAverageNumberOfDonationsFromCandidates(TNGraph & graph)
{
  return averageOutDegreePerCandidate(graph);
}

float calculatePageRanksWithoutInterCandidateDonations();



