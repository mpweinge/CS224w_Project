//
//  1980ElectionHeader.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-12-06.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef _980ElectionHeader_h
#define _980ElectionHeader_h

 const string contPath = "../../data/1979_1980/itcont.txt";
 const string othPath = "../../data/1979_1980/itoth.txt";


//DEMOCRATS
const string carterTag = "C00129445";
const string kennedyTag = "C00115022";
const string brownTag = "C00253914";
const string laroucheTag = "C00364091";
const string kayTag = "C00111492";
const string finchTag = "C00120915";

const string democraticCandidates[] = {carterTag, kennedyTag, brownTag, laroucheTag, kayTag, finchTag};
const int numDemocraticCandidates = 6;

const map<string, string> demNames =
{{carterTag, "Jimmy Carter"}, {kennedyTag, "Ted Kennedy"}, {brownTag, "Jerry Brown"},
  {laroucheTag, "Lyndon LaRouche"}, {kayTag, "Richard B Kay"}, {finchTag, "Cliff Finch"}};

//REPUBLICANS
const string reaganTag = "C00186312";
const string bushTag = "C00079350";
const string andersonTag = "C00000802";
const string bakerTag = "C00107466";
const string craneTag = "C00100834";
const string connallyTag = "C00107318";
const string fernandezTag = "C00212480";
const string stassenTag = "C00108639";

const string republicanCandidates[] = {reaganTag, bushTag, andersonTag, bakerTag, craneTag, connallyTag, fernandezTag, stassenTag};
const int numRepublicanCandidates = 8;

const map<string, string> repNames =
{{reaganTag, "Ronald Reagan"}, {bushTag, "George H.W. Bush"}, {andersonTag, "John Anderson"},
  {bakerTag, "Howard Baker"}, {craneTag, "Phil Crane"}, {connallyTag, "John Connally"},
  {fernandezTag, "Ben Fernandez"}, {stassenTag, "Harold Stassen"} };


#endif /* _980ElectionHeader_h */
