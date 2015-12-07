//
//  1992ElectionHeader.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-12-06.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef _992ElectionHeader_h
#define _992ElectionHeader_h

const string contPath = "../../data/1991_1992/itcont.txt";
const string othPath = "../../data/1991_1992/itoth.txt";
const string pasPath = "../../data/1991_1992/itpas2.txt";
const string cnPath = "../../data/1991_1992/cn.txt";
const string cclPath = "";

const string endCampaign = "03011992";

//Democratic
const string clintonTag = "C00321414";
const string brownTag = "C00253914";
const string tsongasTag = "C00250951";
const string kerreyTag = "C00254250";
const string harkinTag = "C00254375";
const string laroucheTag = "C00364091";
const string mccarthyTag = "C00254698";
const string woodsTag = "C00256289";
const string agranTag = "C00254227";
const string perotTag = "C00321778";

const string democraticCandidates[] = {clintonTag, brownTag, tsongasTag, kerreyTag, harkinTag, laroucheTag, mccarthyTag, woodsTag, agranTag, perotTag};
const int numDemocraticCandidates = 10;

const map<string, string> demNames =
{{clintonTag, "Bill Clinton"}, {brownTag, "Jerry Brown"}, {tsongasTag, "Paul Tsongas"},
  {kerreyTag, "Bob Kerrey"}, {harkinTag, "Tom Harkin"}, {laroucheTag, "Lyndon LaRouche"},
  {mccarthyTag, "Eugene McCarthy"}, {woodsTag, "Charles Woods"}, {agranTag, "Larry Agran"},
  {perotTag, "Ross Perot"}};

//Republican
const string bushTag = "C00273516";
const string buchananTag = "C00361352";
const string dukeTag = "C00256735";
const string hortonTag = "C00208108";
const string stassenTag = "C00108639";

const string republicanCandidates[] = {bushTag, buchananTag, dukeTag, perotTag, hortonTag, stassenTag};
const int numRepublicanCandidates = 6;

const map<string, string> repNames =
{{buchananTag, "Pat Buchanan"}, {bushTag, "George H.W. Bush"}, {dukeTag, "David Duke"},
  {perotTag, "Ross Perot"}, {hortonTag, "Marice Horton"},
  {stassenTag, "Harold E. Stassen"} };


#endif /* _992ElectionHeader_h */
