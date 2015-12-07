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

//Democrats
const string obamaTag = "C00431445";
const string clintonTag = "C00431569";
const string edwardsTag = "C00431205";
const string kucinichTag = "C00430975";
const string richardsonTag = "C00431577";
const string bidenTag = "C00431916";
const string gravelTag = "C00423202";
const string doddTag = "C00431379";

const map<string, string> demNames =
{{obamaTag, "Barack Obama"}, {clintonTag, "Hilary Clinton"}, {edwardsTag, "John Edwards"},
  {bidenTag, "Joe Biden"}, {doddTag, "Chris Dodd"}, {gravelTag, "Mike Gravel"},
  {kucinichTag, "Dennis Kucinich"}, {richardsonTag, "Bill Richardson"}};

//Republicans
const string mccainTag = "";


#endif /* _008ElectionHeader_h */
