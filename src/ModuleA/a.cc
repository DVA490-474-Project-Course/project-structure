// If this file needs something from OtherHeaderNeeded.h then it should be included, even if it already is included in a.h
#include "OtherHeaderNeeded.h"

// Avoid forward declerations, instead include the headers you need (see a.h)
#include "a.h"
