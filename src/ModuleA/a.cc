// Headers should be included in the order of: related headers, C system headers, C++ standard library headers, other libraries headers, and then finally projects headers.
// Alphabetical ordering should be used internally to each category.
// Always have a empty line between each category.
// Only use <> for includes when the library requires it.
// If this file needs something from OtherHeaderNeeded.h then it should be included, even if it already is included in a.h. This goes for all inclusions. What this means is that you should not rely on transistive inclusions

// Try to only used C++ libraries, what i mean with this is to use cstddef over stddef.h.

// Related .h file, related maybe because we are for example implementing or testing the stuff from a.h.
// Avoid forward declerations, instead include the headers you need (see a.h).
// Project headers should be included as decendents of the src directory of the project.
#include "/ModuleA/a.h"

// Example C system header.
#include <unistd.h>

// Example C++ standard library header.
#include <algorithm>

// Other libraries .h files.
#include "OtherHeaderNeeded.h"

// Projects .h files.
#include ""


void temp_func()
{
  // If temp_var does not need to be referenced outside of this file, then use static (EXCEPT IF IT IS A .h FILE!).
  // Local variables should be initialized in the decleration.
  static int temp_var = 5;

  // variables needed for: if, for, while statements should be declared and initialized in those statements.
  for(int i = 0; i < 100; ++i)
  {
    // DO NOT DECLARE VARIABLES IN LOOPS!

  }
}
