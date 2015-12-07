//
//  1988ElectionHeader.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-12-06.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef _988ElectionHeader_h
#define _988ElectionHeader_h

const string contPath = "../../data/1987_1988/itcont.txt";
const string othPath = "../../data/1987_1988/itoth.txt";
const string pasPath = "../../data/1987_1988/itpas2.txt";
const string cnPath = "../../data/1987_1988/cn.txt";

const string endCampaign = "01011988";

//Democratic
const string dukakisTag = "C00227629";
const string jacksonTag = "C00217893";
const string goreTag = "C00360982";
const string gephardtTag = "C00384123";
const string simonTag = "C00168807";
const string hartTag = "C00214452";
const string babbittTag = "C00213017";
const string traficantTag = "C00218941";
const string bidenTag = "C00431916";
const string laroucheTag = "C00364091";
const string dukeTag = "C00256735";

const string democraticCandidates[] = {dukakisTag, jacksonTag, goreTag, gephardtTag, simonTag, hartTag, babbittTag, traficantTag, bidenTag, laroucheTag, dukeTag};
const int numDemocraticCandidates = 11;

const map<string, string> demNames =
{{dukakisTag, "Michael Dukakis"}, {jacksonTag, "Jesse Jackson"}, {goreTag, "Al Gore"},
  {gephardtTag, "Dick Gephardt"}, {simonTag, "Paul Simon"}, {hartTag, "Gary Hart"},
  {babbittTag, "Bruce Babbitt"}, {traficantTag, "Jim Traficant"}, {bidenTag, "Joe Biden"},
  {laroucheTag, "Lyndon LaRouche"}, {dukeTag, "David Duke"}};


//Republican
const string bushTag = "C00273516";
const string doleTag = "C00317743";
const string robertsonTag = "C00218214";
const string kempTag = "C00321620";
const string dupontTag = "C00207530";
const string haigTag = "C00214189";
const string stassenTag = "C00218909";
const string laxaltTag = "C00214783";

const string republicanCandidates[] = {bushTag, doleTag, robertsonTag, kempTag, dupontTag, haigTag, stassenTag, laxaltTag};
const int numRepublicanCandidates = 8;

const map<string, string> repNames =
{{doleTag, "Bob Dole"}, {bushTag, "George H.W. Bush"}, {robertsonTag, "Pat Robertson"},
  {kempTag, "Jack Kemp"}, {dupontTag, "Pierre du Pont"}, {haigTag, "Alexander Haig"},
  {stassenTag, "Harold E. Stassen"}, {laxaltTag, "Paul Laxalt"} };


#endif /* _988ElectionHeader_h */
