//
//  fileReader.cpp
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-11-11.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

#include "fileReader.hpp"


int nodeNum = 0;

bool isEarlierDate(string date1, string date2) {
  // Format of strings is MMDDYYYY
  // All we need to do is compare the last character
  if ( date1[date1.size() - 1] < date2[date2.size() - 1] ){
    return true;
  } else if (date1[date1.size() - 1] == date2[date2.size() - 1]) {
    
    // Compare the months aka the first two years
    string month1 = {date1[0], date1[1]};
    string month2 = {date2[0], date2[1]};
    
    int iMonth1 = stoi(month1);
    int iMonth2 = stoi(month2);
    
    if (iMonth1 < iMonth2) {
      return true;
    } else {
      return false;
    }
    
  } else {
    return false;
  }
}

void readInDonors( vector<candidateDonorNode>& nodes,
                  unordered_map<string, int> &donorStringToNodeNumber,
                  unordered_map<string, int> &committeeStringToNodeNumber,
                  PNGraph &donorGraph,
                  PUNGraph &undirectedDonorGraph,
                  string endDate) {
  
  // Read in the files from our individual to candidate donations
  ifstream candidateDonorFile;
  
  string currentLine;
  
#ifdef TRAIN_2007
    candidateDonorFile.open("../../CS224w_Project/2007_2008/itcont.txt");
#else
    candidateDonorFile.open("../../cs224w_Project/2015_2016/itcont.txt");
#endif
  
  string filerIdentificationNumber;
  string amendmentIndicator;
  string reportType;
  string electionType;
  string imageNumber;
  string transactionType;
  string entityType;
  string name;
  string city;
  string state;
  string zipCode;
  string employer;
  string occupation;
  string transactionDate;
  int transactionAmount;
  string otherIdentificationNumber;
  string transactionCode;
  int fileNum;
  string memoCode;
  string memoText;
  string uniqueRowID;
  
  while (getline(candidateDonorFile, filerIdentificationNumber, '|')) {
    getline(candidateDonorFile, amendmentIndicator, '|');
    getline(candidateDonorFile, reportType, '|');
    getline(candidateDonorFile, electionType, '|');
    getline(candidateDonorFile, imageNumber, '|');
    getline(candidateDonorFile, transactionType, '|');
    
    getline(candidateDonorFile, entityType, '|');
    getline(candidateDonorFile, name, '|');
    getline(candidateDonorFile, city, '|');
    getline(candidateDonorFile, state, '|');
    
    getline(candidateDonorFile, zipCode, '|');
    
    getline(candidateDonorFile, employer, '|');
    getline(candidateDonorFile, occupation, '|');
    getline(candidateDonorFile, transactionDate, '|');
    
    getline(candidateDonorFile, currentLine, '|');
    transactionAmount = stoi(currentLine);
    
    getline(candidateDonorFile, otherIdentificationNumber, '|');
    
    getline(candidateDonorFile, transactionCode, '|');
    
    getline(candidateDonorFile, currentLine, '|');
    if (currentLine == "") {
      fileNum = 0;
    } else {
      fileNum = stoi(currentLine);
    }
    
    getline(candidateDonorFile, memoCode, '|');
    getline(candidateDonorFile, memoText, '|');
    
    getline(candidateDonorFile, uniqueRowID);
    
    bool shouldAdd = true;
    
#ifdef CAP_DONATIONS
    shouldAdd = isEarlierDate(transactionDate, endDate);
#endif
    
    if (shouldAdd) {
      candidateDonorNode nextNode = candidateDonorNode(filerIdentificationNumber,amendmentIndicator,reportType,electionType,\
                                                       imageNumber,transactionType,entityType,name,city,state, zipCode,\
                                                       employer, occupation, transactionDate, transactionAmount, otherIdentificationNumber, transactionCode, fileNum, memoCode, memoText, uniqueRowID);
      
      nodes.push_back(nextNode);
      
      // If donor does not exist in our database
      int donorNodeIndex = 0;
      int committeeNodeIndex = 0;
      
      auto search = donorStringToNodeNumber.find(name);
      if (search == donorStringToNodeNumber.end() ) {
        donorGraph->AddNode(nodeNum);
        undirectedDonorGraph->AddNode(nodeNum);
        donorNodeIndex = nodeNum;
        donorStringToNodeNumber[name] = nodeNum;
        nodeNum++;
      } else {
        donorNodeIndex = search->second;
      }
      
      // Add an edge from that node to that
      auto committeeSearch = committeeStringToNodeNumber.find(filerIdentificationNumber);
      if (committeeSearch == committeeStringToNodeNumber.end()) {
        // Create a new node for that edge
        donorGraph->AddNode(nodeNum);
        undirectedDonorGraph->AddNode(nodeNum);
        committeeStringToNodeNumber[filerIdentificationNumber] = nodeNum;
        candidateToFunds[filerIdentificationNumber] = 0;
        candidateToNumberDonors[filerIdentificationNumber] = 0;
        committeeNodeIndex = nodeNum;
        nodeNum++;
      } else {
        committeeNodeIndex = committeeSearch->second;
      }
      
      // Add an edge from our new node to that
      donorGraph->AddEdge(donorNodeIndex, committeeNodeIndex);
      undirectedDonorGraph->AddEdge(donorNodeIndex, committeeNodeIndex);
      candidateToFunds[filerIdentificationNumber] += transactionAmount;
      candidateToNumberDonors[filerIdentificationNumber] += 1;
    }
  }
}

void readCommitteeToCommitteeFile(unordered_map<string, int> &committeeStringToNodeNumber,
                                  PNGraph &donorGraph,
                                  PUNGraph &undirectedDonorGraph,
                                  string endDate) {
  ifstream committeeToCommitteeFile;
  
  string currentLine;
  
#ifdef TRAIN_2007
  committeeToCommitteeFile.open("../../CS224w_Project/2007_2008/itoth.txt");
#else
  committeeToCommitteeFile.open("../../cs224w_Project/2015_2016/itoth.txt");
#endif
  
  string filerIdentificationNum;
  string AmendmentIndicator;
  string reportType;
  string primaryGeneralIndicator;
  string imageNumber;
  string transactionType;
  string entityType;
  string lenderName;
  string city;
  string state;
  string zipcode;
  string employer;
  string occupation;
  string date;
  int transactionAmount;
  string otherIdentification;
  string transactionID;
  string reportID;
  string memoCode;
  string memoText;
  string FECRecordNum;
  
  while ( getline(committeeToCommitteeFile, filerIdentificationNum, '|')) {
    
    getline(committeeToCommitteeFile, AmendmentIndicator, '|');
    getline(committeeToCommitteeFile, reportType, '|');
    getline(committeeToCommitteeFile, primaryGeneralIndicator, '|');
    getline(committeeToCommitteeFile, imageNumber, '|');
    getline(committeeToCommitteeFile, transactionType, '|');
    getline(committeeToCommitteeFile, entityType, '|');
    getline(committeeToCommitteeFile, lenderName, '|');
    getline(committeeToCommitteeFile, city, '|');
    getline(committeeToCommitteeFile, state, '|');
    getline(committeeToCommitteeFile, zipcode, '|');
    getline(committeeToCommitteeFile, employer, '|');
    getline(committeeToCommitteeFile, occupation, '|');
    getline(committeeToCommitteeFile, date, '|');
    
    getline(committeeToCommitteeFile, currentLine, '|');
    transactionAmount = stoi(currentLine);
    
    getline(committeeToCommitteeFile, otherIdentification, '|');
    getline(committeeToCommitteeFile, transactionID, '|');
    getline(committeeToCommitteeFile, reportID, '|');
    getline(committeeToCommitteeFile, memoCode, '|');
    getline(committeeToCommitteeFile, memoText, '|');
    getline(committeeToCommitteeFile, FECRecordNum);
    
    bool shouldAdd = true;
    
#ifdef CAP_DONATIONS
    shouldAdd = isEarlierDate(date, endDate);
#endif
    
    if (shouldAdd) {
      
      // Add an edge from that node to that
      int candidate1Index = 0, candidate2Index = 0;
      auto search = committeeStringToNodeNumber.find(filerIdentificationNum);
      if (search == committeeStringToNodeNumber.end()) {
        // Create a new node for that edge
        donorGraph->AddNode(nodeNum);
        undirectedDonorGraph->AddNode(nodeNum);
        candidate2Index = nodeNum;
        committeeStringToNodeNumber[filerIdentificationNum] = nodeNum;
        candidateToFunds[filerIdentificationNum] = 0;
        candidateToNumberDonors[filerIdentificationNum] = 0;
        nodeNum++;
      } else {
        candidate2Index = search->second;
      }
      
      auto lenderSearch = committeeStringToNodeNumber.find(otherIdentification);
      if (lenderSearch == committeeStringToNodeNumber.end()) {
        // Create a new node for that edge
        donorGraph->AddNode(nodeNum);
        undirectedDonorGraph->AddNode(nodeNum);
        candidate1Index = nodeNum;
        committeeStringToNodeNumber[otherIdentification] = nodeNum;
        candidateToFunds[otherIdentification] = 0;
        candidateToNumberDonors[otherIdentification] = 0;
        nodeNum++;
      } else {
        candidate1Index = lenderSearch->second;
      }
      
      donorGraph->AddEdge(candidate1Index, candidate2Index);
      undirectedDonorGraph->AddEdge(candidate1Index, candidate2Index);
      candidateToFunds[filerIdentificationNum] += transactionAmount;
      candidateToNumberDonors[filerIdentificationNum] += 1;
    }
  }
}