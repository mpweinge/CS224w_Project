//
//  2012ElectionHeader.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-12-06.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef _012ElectionHeader_h
#define _012ElectionHeader_h

const string contPath = "../../data/2011_2012/itcont.txt";
const string othPath = "../../data/2011_2012/itoth.txt";
const string pasPath = "../../data/2011_2012/itpas2.txt";
const string cnPath = "../../data/2011_2012/cn.txt";

const string endCampaign = "03012012";

//Democrats
const string obamaTag = "C00431445";

const string democraticCandidates[] = {obamaTag};
const int numDemocraticCandidates = 1;

const map<string, string> demNames =
{{obamaTag, "Barack Obama"}};

//Republicans
const string romneyTag = "C00431171";
const string santorumTag = "C00578492";
const string gingrichTag = "C00496497";
const string paulTag = "C00495820";
const string hunstmanTag = "C00498444";
const string perryTag = "C00500587";
const string bachmannTag = "C00410118";
const string roemerTag = "C00493692";
const string cainTag = "C00496067";
const string johnsonTag = "C00495622";

const string republicanCandidates[] = {romneyTag, santorumTag, gingrichTag, paulTag, hunstmanTag, perryTag, bachmannTag, roemerTag, cainTag, johnsonTag};
const int numRepublicanCandidates = 10;

const map<string, string> repNames =
{{romneyTag, "Mitt Romney"}, {santorumTag, "Rick Santorum"}, {gingrichTag, "Newt Gingrich"},
  {paulTag, "Ron Paul"}, {hunstmanTag, "Jon Hunstman"}, {perryTag, "Rick Perry"},
  {bachmannTag, "Michele Bachmann"}, {roemerTag, "Buddy Roemer"},
  {cainTag, "Herman Cain"}, {johnsonTag, "Gary Johnson"}};


#endif /* _012ElectionHeader_h */
