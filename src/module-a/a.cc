// a.cc
//==============================================================================
// Author: Carl Larsson
// Creation date: 2024-09-09
// Last modified: 2024-09-09 by Carl Larsson
// Description: Example .cc file structure and Google C++ style guide, it is only meant to be used as a template. All functions and variables are dummy and the contents of this file should in no way been seen as a reflection of a real file.
// License: See LICENSE file for license details.
//==============================================================================

// Headers should be included in the order of: related headers, C system headers, C++ standard library headers, other libraries headers, and then finally projects headers.
// Alphabetical ordering should be used internally to each category.
// Always have a empty line between each category.
// Only use <> for includes when the library requires it.
// If this file needs something from OtherHeaderNeeded.h then it should be included, even if it already is included in a.h. This goes for all inclusions. What this means is that you should not rely on transistive inclusions.

// Try to only use C++ libraries, what I mean with this is to use cstddef over stddef.h.
// Do not use type deduction.
// Avoid macros.
// Avoid Run-time type information (RTTI).
// Do not use exceptions.
// If using inheritance, make it public.
// Normal indent should be 2 spaces, 4 spaces is used for when wrapping (like for example wrapping condition or arguments).

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
#include "SomeProjectHeader.h"

// The use of the "using" directive to remove the need to write the namespace name is FORBIDDEN!

// Always try to place code in namespaces
// Do not use inline namespaces
// Name should be unique names and based on project name and possibly path.
// namespace names are all lowercase with _ for word seperation.
namespace project_structure
{
namespace module_a
{
// The contents of namespaces should not be indented.
// Function names begin with capital letter and have capital letter for each new word.
void SomeFunction();
} // namespace module_a
} // namespace project_structure

// A class's API must specify whether the class is copyable, move-only, or neither.
// Class names start with capital letter and every new word begins with capital letter.
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
  // 7. All other functions (static and non static member functions, and friend functions)
  // 8. All other data members (static and non static)
  // public, protected and private keywords should only be indented 1 space (NOT TAB!).
 public:
 // Class data members should be named with all lowercase and _ for seperating words and on _ in the end.
  const int class_var_;
 // Classes data members which are part of a test fixture class (defined in a .cc file) can be protected if using Google Test.
 protected:
  char class_char_;
 // Classes data members should be private unless they are constants.
 private:
  void class_private_;
}

// Enums are named just like constants.
// Enums begin with lower case k and then each new word begins with capital letter. 
enum MyEnum 
{
  kEnumVarOne = 1;
  kEnumVarTwo = 2;
};

// Only use structs for passive objects that carry data, everything else should be a class.
// Try to use structs over pairs and tuples
// Struct names start with capital letter nad every new word begins with capital letter.
struct SomeStruct
{
  // Struct data members should be named with all lowercase and _ for seperating words.
  int struct_var;
}

// Avoid static variables, and if you can not, then use it only for simple variables like the int bellow.
// Try to have globals be constant if possible using constexpr. 
// Const should come before int.
// Constants start with a k and then capital letter at the beginning of each new word.
constexpr int kTempVar = 5;

// Global variables should have comment describing what they are, what they are used for, and why they need to be global.
// Vaiables are all lowercase with _ for word seperation.
int global_var = 1;

// Write short and focused functions please!
// If TempFunc does not need to be referenced outside of this file, then use static (EXCEPT IF IT IS AN .h FILE!). Essentially, just try to use static unless a global scope is required.
// Note that this is only the case if namespaces is not used.
// Non-optional input parameters should usually be values or const references.
// Non-optional output or input/output parameters should be references (which can not be null).
// Try to use std::optional for optional by-value inputs. And use const pointer when the non-optional form would have used a reference.
// Use non-const pointer for optional outputs and optional input/output parameters.
// Try to have the parameter order be: inputs, input/ouputs, outputs.
// Default arguments are allowed on non-virtual functions when the default is guaranteed to always have the same value.
// Every function should have a comment preceeding it explaining what it does and how to use it. Also describe inputs and outputs. Additionally, for pointer argumtents it should be described it they can be null and what happens if they are.
static int TempFunc()
{
  // Local variables should be initialized in the decleration.
  // Variables should be declared as close to the place where they will be used as possible
  // DO NOT USE STATIC LOCAL VARIABLES!
  // DO NOT USE SHORT, LONG OR LONG LONG!
  int var = 3;
  // DO NOT use cast formats like: (int)x unless it is to void.
  // Use C++ style casts like: static_cast<float>(double_value) or brace initialization like int64_t{1}.
  DoSomething(int64_t{var});

  // Always write floating-point with radix point and digits on both sides
  float SomeFloat = 1.0f;
  // DO NOT USE LONG DOUBLE!
  double SomeLong = -0.5L;
  double SomeDouble = 1000.0e6;
  // Minimize whitespaces. whitespaces should be used to sepate two thoughts. Do not start or end with whitespaces. Avoid using more than one whitespaces, never use more than two.

  // If a pointer is suppossed to not point to anything, or end of list or similar, then use nullptr (also use it to check if pointer points to something).
  int* int_pointer = nullptr;
  // And if it is char, then use '\0'.

  // No spaces around period or arrow
  x  = r->y;

  // Use sizeof(varname), not sizeof(type).
  SomeClass data;
  memset(&data, 0, sizeof(data));

  // Each line of text must be 80 or less characters long.

  // variables needed for: if, for, while statements should be declared and initialized in those statements.
  // UNLESS IT IS AN OBJECT!
  // A single space should be used to separate looping and branching statements and their component/condition/iteration specifier.
  // Single space after each semicolon (;).
  // Increment using ++i formand and decrement using the --i format.
  for (int i = 0; i < 100; ++i)
  {
    // DO NOT DECLARE VARIABLES IN LOOPS!
  }

  // while (condition); is not allowed
  // Instead do:
  while (condition) {};
  // or
  while (condition) continue;

  // Switching statements must have a default case
  switch (var) 
  {
    case 0;
    {
      // ...
    }
    default:
    {
      // ...
    }
  }

  // Use return values over output parameters
  // Preferably return by value, if you can not, then return by reference. Avoid returning a raw pointer, unless it can be null.
  return something;
}
