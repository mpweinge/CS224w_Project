//
//  constants.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-11-10.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef constants_h
#define constants_h

#include <string> 
#include <unordered_map>

#include "Snap.h"

#define TRAIN_2007
#define CAP_DONATIONS

#pragma once

using namespace std;

// Candidates started dropping out in 2008 primary on jan 1st, 2008
const string end2007Campaign = "01012008";

//If the last four digits are >= 2008, then don't include
const string end2007Year = "2008";

const string obamaTag = "C00431445";
const string clintonTag = "C00431569";
const string edwardsTag = "C00431205";
const string bidenTag = "C00431916";
const string doddTag = "C00431379";
const string gravelTag = "C00423202";
const string kucinichTag = "C00430975";
const string richardsonTag = "C00431577";

const string democraticCandidates2008[] = {obamaTag, clintonTag, edwardsTag, bidenTag, doddTag, gravelTag, kucinichTag, richardsonTag};

const int numDemocraticCandidates2008 = 8;

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

#endif /* constants_h */