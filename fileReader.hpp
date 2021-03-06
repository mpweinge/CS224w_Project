//
//  fileReader.hpp
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-11-11.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef fileReader_hpp
#define fileReader_hpp

#include <stdio.h>
#include <vector>

#include "constants.h"
#include "DatabaseStatistics.hpp"

using namespace std;

void readCommitteeToCommitteeFile(map<string, int> &committeeStringToNodeNumber,
                                  PNGraph &donorGraph,
                                  PUNGraph &undirectedDonorGraph,
                                  string endDate);

void readInDonors( vector<candidateDonorNode>& nodes,
                  unordered_map<string, int> &donorStringToNodeNumber,
                  map<string, int> &committeeStringToNodeNumber,
                  PNGraph &donorGraph,
                  PUNGraph &undirectedDonorGraph,
                  string endDate);

void readInPAS( vector<candidateDonorNode>& nodes,
               unordered_map<string, int> &donorStringToNodeNumber,
               map<string, int> &committeeStringToNodeNumber,
               PNGraph &donorGraph,
               PUNGraph &undirectedDonorGraph,
               string endDate);

void readInCN();

void readCCL();

#endif /* fileReader_hpp */
