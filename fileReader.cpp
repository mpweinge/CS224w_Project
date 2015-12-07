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
  
  // Compare the last 4 digits (the year)
  if (date1 == "")
    return true;
  string year1 = date1.substr(date1.length() - 4);
  string year2 = date2.substr(date2.length() - 4);
  
  if ( stoi(year1) < stoi(year2) ){
    return true;
  } else {
    
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
    
  }
  return false;
}

unordered_map<string, string> candidateIdToCommittee;

void readInCN() {
  ifstream candidateDonorFile;
  
  string currentLine;
  
  string candidateID;
  string dummyInput;
  string candidateComm;
  
  candidateDonorFile.open(cnPath);
  
  while (getline(candidateDonorFile, candidateID, '|')) {
    for (int i = 0; i < 8; i++)
    {
      getline(candidateDonorFile, dummyInput, '|');
    }
    getline(candidateDonorFile, candidateComm, '|');
    getline(candidateDonorFile, dummyInput);
    candidateIdToCommittee[candidateID] = candidateComm;
    
    
    if (candidateComm == "C00186312" ) {
      int k;
      k = 0;
      k++;
    }
    
  }
}

void readInPAS( vector<candidateDonorNode>& nodes,
               unordered_map<string, int> &donorStringToNodeNumber,
               map<string, int> &committeeStringToNodeNumber,
               PNGraph &donorGraph,
               PUNGraph &undirectedDonorGraph,
               string endDate) {
  
  // Read in the files from our individual to candidate donations
  ifstream candidateDonorFile;
  
  string currentLine;
  
  candidateDonorFile.open(pasPath);
  
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
  string candidateID;
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
    getline(candidateDonorFile, candidateID, '|');
    
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
    
    
    // Turn that candidateID into a candidate committee through array
    
    if (candidateID == "P60000452") {
      int k;
      k = 0;
    }
    if (candidateIdToCommittee[candidateID] != "") {
      candidateID = candidateIdToCommittee[candidateID];
    }
    
    if (candidateID == "C00186312") {
      int k = 0;
      k++;
    }
    
    if (shouldAdd) {
      candidateDonorNode nextNode = candidateDonorNode(filerIdentificationNumber,amendmentIndicator,reportType,electionType,\
                                                       imageNumber,transactionType,entityType,name,city,state, zipCode,\
                                                       employer, occupation, transactionDate, transactionAmount, otherIdentificationNumber, transactionCode, fileNum, memoCode, memoText, uniqueRowID);
      
      nodes.push_back(nextNode);
      
      // If donor does not exist in our database
      int recipientNodeIndex = 0;
      int committeeNodeIndex = 0;
      
      // Add an edge from that node to that
      auto committeeSearch = committeeStringToNodeNumber.find(candidateID);
      if (committeeSearch == committeeStringToNodeNumber.end()) {
        // Create a new node for that edge
        donorGraph->AddNode(nodeNum);
        undirectedDonorGraph->AddNode(nodeNum);
        committeeStringToNodeNumber[candidateID] = nodeNum;
        candidateToDonorFunds[candidateID] = 0;
        candidateToNumberDonors[candidateID] = 0;
        recipientNodeIndex = nodeNum;
        nodeNum++;
      } else {
        recipientNodeIndex = committeeSearch->second;
      }
      
      auto search = committeeStringToNodeNumber.find(filerIdentificationNumber);
      if (search == committeeStringToNodeNumber.end() ) {
        donorGraph->AddNode(nodeNum);
        undirectedDonorGraph->AddNode(nodeNum);
        committeeNodeIndex = nodeNum;
        committeeStringToNodeNumber[filerIdentificationNumber] = nodeNum;
        candidateToDonorFunds[filerIdentificationNumber] = 0;
        candidateToNumberDonors[filerIdentificationNumber] = 0;

        nodeNum++;
      } else {
        committeeNodeIndex = search->second;
      }
      
      // Add an edge from our new node to that
      donorGraph->AddEdge(committeeNodeIndex, recipientNodeIndex);
      undirectedDonorGraph->AddEdge(committeeNodeIndex, recipientNodeIndex);
      candidateToPACFunds[candidateID] += transactionAmount;
      candidateToNumberDonors[candidateID] += 1;
    }
  }
}

void readInDonors( vector<candidateDonorNode>& nodes,
                  unordered_map<string, int> &donorStringToNodeNumber,
                  map<string, int> &committeeStringToNodeNumber,
                  PNGraph &donorGraph,
                  PUNGraph &undirectedDonorGraph,
                  string endDate) {
  
  // Read in the files from our individual to candidate donations
  ifstream candidateDonorFile;
  
  string currentLine;
  
/*#ifdef TRAIN_2007
  const string contPath = "../../data/2007_2008/itcont.txt";
    candidateDonorFile.open("../../CS224w_Project/2007_2008/itcont.txt");
#else
    candidateDonorFile.open("../../cs224w_Project/2015_2016/itcont.txt");
#endif*/
  candidateDonorFile.open(contPath);
  
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
        candidateToDonorFunds[filerIdentificationNumber] = 0;
        candidateToNumberDonors[filerIdentificationNumber] = 0;
        committeeNodeIndex = nodeNum;
        nodeNum++;
      } else {
        committeeNodeIndex = committeeSearch->second;
      }
      
      // Add an edge from our new node to that
      donorGraph->AddEdge(donorNodeIndex, committeeNodeIndex);
      undirectedDonorGraph->AddEdge(donorNodeIndex, committeeNodeIndex);
      candidateToDonorFunds[filerIdentificationNumber] += transactionAmount;
      candidateToNumberDonors[filerIdentificationNumber] += 1;
    }
  }
}

void readCommitteeToCommitteeFile(map<string, int> &committeeStringToNodeNumber,
                                  PNGraph &donorGraph,
                                  PUNGraph &undirectedDonorGraph,
                                  string endDate) {
  ifstream committeeToCommitteeFile;
  
  string currentLine;
  
/*#ifdef TRAIN_2007
  committeeToCommitteeFile.open(othPath);
#else
  committeeToCommitteeFile.open("../../cs224w_Project/2015_2016/itoth.txt");
#endif*/
  committeeToCommitteeFile.open(othPath);
  
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
        candidateToPACFunds[filerIdentificationNum] = 0;
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
        candidateToPACFunds[otherIdentification] = 0;
        candidateToNumberDonors[otherIdentification] = 0;
        nodeNum++;
      } else {
        candidate1Index = lenderSearch->second;
      }
      
      donorGraph->AddEdge(candidate1Index, candidate2Index);
      undirectedDonorGraph->AddEdge(candidate1Index, candidate2Index);
      candidateToPACFunds[filerIdentificationNum] += transactionAmount;
      candidateToNumberDonors[filerIdentificationNum] += 1;
    }
  }
}