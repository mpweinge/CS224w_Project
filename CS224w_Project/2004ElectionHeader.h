//
//  2004ElectionHeader.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-12-06.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef _004ElectionHeader_h
#define _004ElectionHeader_h

const string contPath = "../../data/2003_2004/itcont.txt";
const string othPath = "../../data/2003_2004/itoth.txt";
const string pasPath = "../../data/2003_2004/itpas2.txt";
const string cnPath = "../../data/2003_2004/cn.txt";

const string endCampaign = "01012004";

//Democrats
const string kerryTag = "C00404160";
const string edwardsTag = "C00384073";
const string deanTag = "C00378125";
const string clarkTag = "C00390898";
const string kucinichTag = "C00430975";
const string sharptonTag = "C00384388";
const string gephardtTag = "C00384123";
const string liebermanTag = "C00384297";

const string democraticCandidates[] = {kerryTag, edwardsTag, deanTag, clarkTag, kucinichTag, sharptonTag, gephardtTag, liebermanTag};
const int numDemocraticCandidates = 8;

const map<string, string> demNames =
{{kerryTag, "John Kerry"}, {edwardsTag, "John Edwards"},{deanTag, "Howard Dean"},
{clarkTag, "Wesley Clark"}, {kucinichTag, "Dennis Kucinich"},{sharptonTag, "Al Sharpton"},
{gephardtTag, "Dick Gephardt"}, {liebermanTag, "Joe Lieberman"}};

//Republican
const string bushTag = "C00404343";

const string republicanCandidates[] = {bushTag};
const int numRepublicanCandidates = 1;

const map<string, string> repNames =
{{bushTag, "George W. Bush"}};


#endif /* _004ElectionHeader_h */
