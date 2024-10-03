// a.h
//==============================================================================
// Author: Carl Larsson
// Creation date: 2024-09-09
// Last modified: 2024-09-18 by Carl Larsson
// Description: Example .h file used for example file structure and Google C++ 
// style guide, it is only meant to be used as a template. All functions and 
// variables are dummy and the contents of this file should in no way been seen 
// as a reflection of a real file.
// License: See LICENSE file for license details.
//==============================================================================


// General:
// - Try to only use C++ libraries, what I mean with this is to use cstddef over 
// stddef.h.
// - Do not use type deduction.
// - Avoid macros.
// - Avoid Run-time type information (RTTI).
// - Do not use exceptions.
// - If using inheritance, make it public.
// - Normal indent should be 2 spaces, 4 spaces is used for when wrapping (like 
// for example wrapping condition or arguments).
// - Use /* */ to create comments.
// - The use of the "using" directive to remove the need to write the namespace 
// name is FORBIDDEN!
// - Try to keep as small and local scope as possible, if a class, enum, struct 
// or similar is only to be used in a .cc file, then it can be declared there, 
// otherwise have it in the .h file.
// - Minimize whitespaces. whitespaces should be used to sepate two thoughts. 
// Do not start or end with whitespaces. Avoid using more than one whitespaces, 
// never use more than two.
// - Each line of text must be 80 or less characters long.

// .h files should contain the decleration, the .cc file the implementation

// Always use header guards in .h files.
// #ifndef <project>_<path>_<file>_H_ 
// #define <project>_<path>_<file>_H_ 

// ...

// #endif // <project>_<path>_<file>_H_ 


// Macros are named with all capital letters and _ to seperate words.
// Header guards also end with a _.
#ifndef PROJECTSTRUCTURE_MODULEA_A_H_ 
#define PROJECTSTRUCTURE_MODULEA_A_H_ 
// - If a.cc needs something from other_header_needed.h and a.cc includes it, 
// then it should still be included in this file (a.h), always include in both 
// .h and .cc file. This goes for all inclusions. What this means is that you 
// should not rely on transistive inclusions.
// - Headers should be included in the order of: related headers, C system 
// headers, C++ standard library headers, other libraries headers, and then 
// finally projects headers.
// - Alphabetical ordering should be used internally to each category.
// - Always have a empty line between each category.
// - Only use <> for includes when the library requires it.

// - Related .h file, related maybe because we are for example implementing or 
// testing the stuff from some_file.h.
// - Avoid forward declerations, instead include the headers you need.
// - Project headers should be included as decendents of the src directory of 
// the project.
#include "somewhere/some_file.h"

// Example C system header.
#include <unistd.h>

// Example C++ standard library header.
#include <algorithm>

// Other libraries .h files.
#include "other_header_needed.h"

// Projects .h files.
#include "somewhere/some_project_header.h"


// - Avoid static variables, and if you can not, then use it only for simple 
// variables like the int bellow.
// - Try to have globals be constant if possible using constexpr. 
// - Const should come before int.
// - Constants start with a k and then capital letter at the beginning of each 
// new word.
constexpr int kTempVar = 5;

// - Global variables should have comment describing what they are, what they 
// are used for, and why they need to be global.
// - Vaiables are all lowercase with _ for word seperation.
int global_var = 1;


// - Avoiding forward decleration.
// - A class's API must specify whether the class is copyable, move-only, or 
// neither.
// - Class names start with capital letter and every new word begins with 
// capital letter.
class SomeClass
{
  // Class definition order: public, then protected, lastly private.
  // Within each section follow this order:
  // 1. Types and type aliases
  // 2. non-static data members
  // 3. Static constants
  // 4. Factory functions
  // 5. Constructors and assignment operators
  // 6. Destructor
  // 7. All other functions (static and non static member functions, and friend 
  // functions)
  // 8. All other data members (static and non static)
 // public, protected and private keywords should only be indented 1 space 
 // (NOT TAB!).
 public:
  // Class data members should be named with all lowercase and _ for seperating 
  // words and one _ in the end.
  const int class_var_;
 // Classes data members which are part of a test fixture class (defined in a 
 // .cc file) can be protected if using Google Test.
 protected:
  char class_char_;
 // Classes data members should be private unless they are constants.
 private:
  void class_private_;
}

// - For enums, declare them using enum class, not just enum.
// - Enums are named just like constants.
// - Enums begin with lower case k and then each new word begins with capital
// letter. 
enum class SomeEnum 
{
  kEnumVarOne = 1;
  kEnumVarTwo = 2;
};

// - Only use structs for passive objects that carry data, everything else 
// should be a class.
// - Try to use structs over pairs and tuples.
// - Struct names start with capital letter and every new word begins with 
// capital letter.
struct SomeStruct
{
  // Struct data members should be named with all lowercase and _ for seperating 
  // words.
  int struct_var;
}

#endif // PROJECTSTRUCTURE_MODULEA_A_H_ 
