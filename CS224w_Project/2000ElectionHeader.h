//
//  2000ElectionHeader.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-12-06.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef _000ElectionHeader_h
#define _000ElectionHeader_h

const string contPath = "../../data/1999_2000/itcont.txt";
const string othPath = "../../data/1999_2000/itoth.txt";
const string pasPath = "../../data/1999_2000/itpas2.txt";
const string cnPath = "../../data/1999_2000/cn.txt";

const string endCampaign = "01012000";

//Democrats
const string goreTag = "C00360982";
const string bradleyTag = "C00341818";
const string laroucheTag = "C00364091";

const string democraticCandidates[] = {goreTag, bradleyTag, laroucheTag};
const int numDemocraticCandidates = 3;

const map<string, string> demNames =
{{goreTag, "Al Gore"}, {bradleyTag, "Bill Bradley"},{laroucheTag, "Lyndon LaRouche"}};

//Republicans
const string bushTag = "C00404343";
const string keyesTag = "C00452532";
const string mccainTag = "C00430470";
const string forbesTag = "C00343772";
const string bauerTag = "C00342774";
const string hatchTag = "C00346783";
const string alexanderTag = "C00342220";

const string republicanCandidates[] = {bushTag, keyesTag, mccainTag, forbesTag, bauerTag, hatchTag, alexanderTag};
const int numRepublicanCandidates = 7;

const map<string, string> repNames =
{{bushTag, "George W. Bush"}, {keyesTag, "Alan Keyes"}, {mccainTag, "John McCain"},
  {forbesTag, "Steve Forbes"}, {bauerTag, "Gary Bauer"},
  {hatchTag, "Orrin Hatch"}, {alexanderTag, "Lamar Alexander"}};


#endif /* _000ElectionHeader_h */
