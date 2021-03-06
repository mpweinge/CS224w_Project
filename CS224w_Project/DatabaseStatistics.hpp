//
//  DatabaseStatistics.hpp
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-11-12.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef DatabaseStatistics_hpp
#define DatabaseStatistics_hpp

#include <stdio.h>
#include "Constants.h"
#include "2000ElectionHeader.h"

float getAverageNumberOfDonationsPerIndividual();
float getAverageNumberOfDonationsPerPAC(PNGraph & graph);

int getNumberOfEdges();

int getNumberOfCommittees();

float averageOutDegreePerCandidate();
float averageInDegreePerCandidate(PNGraph & graph);


// Some candidates donate to other candidates
float getAverageNumberOfDonationsFromCandidates();

float calculatePageRanksWithoutInterCandidateDonations();



#endif /* DatabaseStatistics_hpp */
