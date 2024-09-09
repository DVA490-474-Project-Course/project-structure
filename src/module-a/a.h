// Always use header guards in .h files
#ifndef <project>_<path>_<file>_H_ 
#define <project>_<path>_<file>_H_ 

...

#endif // <project>_<path>_<file>_H_ 

// This file should thus have (always capital letters for project, path, file and h):

#include "OtherHeaderNeeded.h"

#ifndef PROJECTSTRUCTURE_MODULEA_A_H_ 
#define PROJECTSTRUCTURE_MODULEA_A_H_ 

// Avoiding forward decleration
class B {};
...

#endif // PROJECTSTRUCTURE_MODULEA_A_H_ 
