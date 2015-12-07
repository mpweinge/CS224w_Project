//
//  1996ElectionHeader.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-12-06.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef _996ElectionHeader_h
#define _996ElectionHeader_h

const string contPath = "../../data/1995_1996/itcont.txt";
const string othPath = "../../data/1995_1996/itoth.txt";

//Democrats
const string clintonTag = "C00321414";
const string laroucheTag = "C00364091";

const string democraticCandidates[] = {clintonTag, laroucheTag};
const int numDemocraticCandidates = 2;

const map<string, string> demNames =
{{clintonTag, "Bill Clinton"}, {laroucheTag, "Lyndon LaRouche"}};

//Republicans
const string doleTag = "C00317743";
const string buchananTag = "C00361352";
const string forbesTag = "C00343772";
const string keyesTag = "C00452532";
const string lugarTag = "C00301333";
const string grammTag = "C00299917";
const string dornanTag = "C00301465";
const string taylorTag = "C00302216";

const string republicanCandidates[] = {doleTag, buchananTag, forbesTag, keyesTag, lugarTag, grammTag, dornanTag, taylorTag};
const int numRepublicanCandidates = 8;

const map<string, string> repNames =
{{doleTag, "Bob Dole"}, {buchananTag, "Pat Buchanan"}, {forbesTag, "Steve Forbes"},
  {keyesTag, "Alan Keyes"}, {lugarTag, "Richard Lugar"},
  {grammTag, "Phil Gramm"}, {dornanTag, "Robert K. Dornan"}, {taylorTag, "Morry Taylor"} };


#endif /* _996ElectionHeader_h */
