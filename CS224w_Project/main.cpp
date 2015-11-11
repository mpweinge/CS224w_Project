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
#include "Snap.h"


using namespace std;

// Data structure taken from here: http://www.fec.gov/finance/disclosure/metadata/DataDictionaryContributionsbyIndividuals.shtml


unordered_map<string, int> committeeToAmount;

unordered_map<string, int> committeeStringToNodeNumber;

unordered_map<string, int> donorStringToNodeNumber;

int nodeNum = 0;

PNGraph donorGraph;

struct candidateDonorNode {
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
  
  candidateDonorNode(string _filerIdentificationNumber,
                     string _amendmentIndicator,
                     string _reportType,
                     string _electionType,
                     string _imageNumber,
                     string _transactionType,
                     string _entityType,
                     string _name,
                     string _city,
                     string _state,
                     string _zipCode,
                     string _employer,
                     string _occupation,
                     string _transactionDate,
                     int _transactionAmount,
                     string _otherIdentificationNumber,
                     string _transactionCode,
                     int _fileNum,
                     string _memoCode,
                     string _memoText,
                     string _uniqueRowID):
  filerIdentificationNumber(_filerIdentificationNumber),
  amendmentIndicator(_amendmentIndicator),
  reportType(_reportType),
   electionType(_electionType),
   imageNumber(_imageNumber),
   transactionType(_transactionType),
   entityType(_entityType),
   name(_name),
   city(_city),
   state(_state),
   zipCode(_zipCode),
   employer(_employer),
   occupation(_occupation),
   transactionDate(_transactionDate),
   transactionAmount(_transactionAmount),
   otherIdentificationNumber(_otherIdentificationNumber),
   transactionCode(_transactionCode),
   fileNum(_fileNum),
   memoCode(_memoCode),
   memoText(_memoText),
  uniqueRowID(_uniqueRowID) {}
  
};

struct committeeToCommitteeTransaction {
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
  
  committeeToCommitteeTransaction(string _filerIdentificationNum,
                                  string _AmendmentIndicator,
                                  string _reportType,
                                  string _primaryGeneralIndicator,
                                  string _imageNumber,
                                  string _transactionType,
                                  string _entityType,
                                  string _lenderName,
                                  string _city,
                                  string _state,
                                  string _zipcode,
                                  string _employer,
                                  string _occupation,
                                  string _date,
                                  int _transactionAmount,
                                  string _otherIdentification,
                                  string _transactionID,
                                  string _reportID,
                                  string _memoCode,
                                  string _memoText,
                                  string _FECRecordNum) :
  filerIdentificationNum(_filerIdentificationNum),
  AmendmentIndicator(_AmendmentIndicator),
  reportType( _reportType),
  primaryGeneralIndicator( _primaryGeneralIndicator),
  imageNumber( _imageNumber),
  transactionType( _transactionType),
  entityType( _entityType),
  lenderName( _lenderName),
  city( _city),
  state( _state),
  zipcode( _zipcode),
  employer( _employer),
  occupation( _occupation),
  date( _date),
  transactionAmount( _transactionAmount),
  otherIdentification( _otherIdentification),
  transactionID( _transactionID),
  reportID( _reportID),
  memoCode( _memoCode),
  memoText( _memoText),
  FECRecordNum( _FECRecordNum) { }
  
};

void readInDonors( vector<candidateDonorNode>& nodes ) {
  
  // Read in the files from our individual to candidate donations
  ifstream candidateDonorFile;
  
  string currentLine;
  candidateDonorFile.open("../../cs224w_Project/itcont.txt");
  
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
      donorNodeIndex = nodeNum;
      nodeNum++;
    } else {
      donorNodeIndex = search->second;
    }
    
    // Add an edge from that node to that
    auto committeeSearch = committeeStringToNodeNumber.find(filerIdentificationNumber);
    if (committeeSearch == committeeStringToNodeNumber.end()) {
      // Create a new node for that edge
      donorGraph->AddNode(nodeNum);
      committeeStringToNodeNumber[filerIdentificationNumber] = nodeNum;
      committeeNodeIndex = nodeNum;
      nodeNum++;
    } else {
      committeeNodeIndex = committeeSearch->second;
    }
    
    // Add an edge from our new node to that
    donorGraph->AddEdge(donorNodeIndex, committeeNodeIndex);

  }
}

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  
  vector<candidateDonorNode> nodes;
  
  donorGraph = TNGraph::New();

  readInDonors(nodes);
  
  // Filer number is who the money is going to.
  
  // Take that and see who they donate it to?
  // OTH has information for this
  
  ifstream committeeToCommitteeFile;
  
  string currentLine;
  committeeToCommitteeFile.open("../../cs224w_Project/itoth.txt");
  
  vector<committeeToCommitteeTransaction> commToCommTransactions;
  
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
    
    int currNum = committeeToAmount[filerIdentificationNum];
    currNum += transactionAmount;
    committeeToAmount[filerIdentificationNum] = currNum;
    
    // Add an edge from that node to that
    int candidate1Index = 0, candidate2Index = 0;
    auto search = committeeStringToNodeNumber.find(filerIdentificationNum);
    if (search == committeeStringToNodeNumber.end()) {
      // Create a new node for that edge
      donorGraph->AddNode(nodeNum);
      candidate2Index = nodeNum;
      committeeStringToNodeNumber[filerIdentificationNum] = nodeNum;
      nodeNum++;
    } else {
      candidate2Index = search->second;
    }
    
    auto lenderSearch = committeeStringToNodeNumber.find(otherIdentification);
    if (lenderSearch == committeeStringToNodeNumber.end()) {
      // Create a new node for that edge
      donorGraph->AddNode(nodeNum);
      candidate1Index = nodeNum;
      committeeStringToNodeNumber[otherIdentification] = nodeNum;
      nodeNum++;
    } else {
      candidate1Index = lenderSearch->second;
    }
    
    donorGraph->AddEdge(candidate1Index, candidate2Index);
    
  }

  cout << "Clinton funds: " << committeeToAmount["C00358895"] + committeeToAmount["C00575795"] << endl;
  
  // Count the number of in edges to clinton
  cout << "Number of edges to clinton";
  TNGraph::TNodeI clintonIndex = donorGraph->GetNI(committeeStringToNodeNumber["C00575795"]);
  
  cout << clintonIndex.GetInDeg() << endl;
  
  // Compute pagerank for all of the nodes in our graph
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
  
  
  return 0;
}
