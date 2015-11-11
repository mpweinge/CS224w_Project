//
//  constants.h
//  CS224w_Project
//
//  Created by Michael Weingert on 2015-11-10.
//  Copyright © 2015 Michael Weingert. All rights reserved.
//

#ifndef constants_h
#define constants_h

#include <string> 

#define TRAIN_2007
#define CAP_DONATIONS

// Candidates started dropping out in 2008 primary on jan 1st, 2008
const std::string end2007Campaign = "01012008";

//If the last four digits are >= 2008, then don't include
const std::string end2007Year = "2008";

#endif /* constants_h */
