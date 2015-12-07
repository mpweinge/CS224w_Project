//
//  1984ElectionHeader.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-12-06.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef _984ElectionHeader_h
#define _984ElectionHeader_h

const string contPath = "../../data/1983_1984/itcont.txt";
const string othPath = "../../data/1983_1984/itoth.txt";
const string pasPath = "../../data/1983_1984/itpas2.txt";
const string cnPath = "../../data/1983_1984/cn.txt";

const string endCampaign = "03011984";

//Democrats
const string mondaleTag = "C00186296";
const string hartTag = "C00214452";
const string jacksonTag = "C00217893";
const string eagletonTag = "C00029488";
const string glennTag = "C00164855";
const string mcgovernTag = "C00170407";
const string kirklandTag = "C00159392";

const string democraticCandidates[] = {mondaleTag, hartTag, jacksonTag, eagletonTag, glennTag, mcgovernTag, kirklandTag};
const int numDemocraticCandidates = 7;

const map<string, string> demNames =
{{mondaleTag, "Walter Mondale"}, {hartTag, "Gary Hart"}, {jacksonTag, "Jesse Jackson"},
  {eagletonTag, "Thomas Eagleton"}, {glennTag, "John Glenn"}, {mcgovernTag, "George McGovern"}, {kirklandTag, "Martha Kirkland"}};

//Republican
const string reaganTag = "C00186312";
const string stassenTag = "C00218909";

const string republicanCandidates[] = {reaganTag, stassenTag};
const int numRepublicanCandidates = 2;

const map<string, string> repNames =
{{reaganTag, "Ronald Reagan"}, {stassenTag, "Harold Stassen"} };


#endif /* _984ElectionHeader_h */
