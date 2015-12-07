//
//  2008ElectionHeader.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-12-06.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef _008ElectionHeader_h
#define _008ElectionHeader_h

const string contPath = "../../data/2007_2008/itcont.txt";
const string othPath = "../../data/2007_2008/itoth.txt";
const string pasPath = "../../data/2007_2008/itpas2.txt";
const string cnPath = "../../data/2007_2008/cn.txt";
const string cclPath = "../../data/2007_2008/ccl.txt";

const string endCampaign = "03012008";

//Democrats
const string obamaTag = "C00431445";
const string clintonTag = "C00431569";
const string edwardsTag = "C00384073";
const string kucinichTag = "C00430975";
const string richardsonTag = "C00431577";
const string bidenTag = "C00431916";
const string gravelTag = "C00423202";
const string doddTag = "C00431379";

const string democraticCandidates[] = {obamaTag, clintonTag, edwardsTag, kucinichTag, richardsonTag, bidenTag, gravelTag, doddTag};
const int numDemocraticCandidates = 8;

const map<string, string> demNames =
{{obamaTag, "Barack Obama"}, {clintonTag, "Hilary Clinton"}, {edwardsTag, "John Edwards"},
  {kucinichTag,  "Dennis Kucinich"}, {richardsonTag, "Bill Richardson"},
  {bidenTag, "Joe Biden"}, {gravelTag, "Mike Gravel"}, {doddTag, "Chris Dodd"}};

//Republicans
const string mccainTag = "C00430470";
const string romneyTag = "C00431171";
const string huckTag = "C00431809";
const string paulTag = "C00495820";
const string thompsonTag = "C00438507";
const string giulianiTag = "C00430512";
const string keyesTag = "C00452532";
const string hunterTag = "C00431411";

const string republicanCandidates[] = {mccainTag, romneyTag, huckTag, paulTag, thompsonTag, giulianiTag, keyesTag, hunterTag};
const int numRepublicanCandidates = 8;

const map<string, string> repNames =
{{mccainTag, "John McCain"}, {romneyTag, "Mitt Romney"}, {huckTag, "Mike Huckabee"},
{paulTag, "Ron Paul"}, {thompsonTag, "Fred Thompson"}, {giulianiTag, "Rudy Giuliani"},
{keyesTag, "Alan Keyes"}, {hunterTag, "Duncan Hunter"}};


#endif /* _008ElectionHeader_h */
