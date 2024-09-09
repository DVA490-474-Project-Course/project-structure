// a.h
//==============================================================================
// Author: Carl Larsson
// Creation date: 2024-09-09
// Last modified: 2024-09-09 by Carl Larsson
// Description: Example .h file structure and Google C++ style guide, it is only meant to be used as a template. All functions and variables are dummy and the contents of this file should in no way been seen as a reflection of a real file.
// License: See LICENSE file for license details.
//==============================================================================

// Always use header guards in .h files
#ifndef <project>_<path>_<file>_H_ 
#define <project>_<path>_<file>_H_ 

...

#endif // <project>_<path>_<file>_H_ 

// This file should thus have (always capital letters for project, path, file and h):

#include "OtherHeaderNeeded.h"

// Macros are named with all capital letters and _ to seperate words.
// Header guards also end with a _.
#ifndef PROJECTSTRUCTURE_MODULEA_A_H_ 
#define PROJECTSTRUCTURE_MODULEA_A_H_ 

// Avoiding forward decleration
class B {};
...

#endif // PROJECTSTRUCTURE_MODULEA_A_H_ 
