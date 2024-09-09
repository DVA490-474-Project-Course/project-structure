// Headers should be included in the order of: related headers, C system headers, C++ standard library headers, other libraries headers, and then finally projects headers.
// Alphabetical ordering should be used internally to each category.
// Always have a empty line between each category.
// Only use <> for includes when the library requires it.
// If this file needs something from OtherHeaderNeeded.h then it should be included, even if it already is included in a.h. This goes for all inclusions. What this means is that you should not rely on transistive inclusions.

// Try to only use C++ libraries, what I mean with this is to use cstddef over stddef.h.

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
namespace project_structure_module_a_namespace
{
// The contents of whitespaces should not be indented.
// Function names begin with capital letter and have capital letter for each new word.
void SomeFunction();
} // namespace

// Class names start with capital letter and every new word begins with capital letter.
class SomeClass
{
  // Class data members should be named with all lowercase and _ for seperating words and on _ in the end.
  public;
  int class_var_;
}

// Enums are named just like constants.
// Enums begin with lower case k and then each new word begins with capital letter. 
enum MyEnum 
{
  kEnumVarOne = 1;
  kEnumVarTwo = 2;
};

// Struct names start with capital letter nad every new word begins with capital letter.
struct SomeStruct
{
  // Struct data members should be named with all lowercase and _ for seperating words.
  int struct_var;
}

// Avoid static variables, and if you can not, then use it only for simple variables like the int bellow.
// Try to have globals be constant if possible.
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
  int var = 3;
  DoSomething(var);
  // Always write floating-point with radix point and digits on both sides
  float SomeFloat = 1.0f;
  long double SomeLong = -0.5L;
  double SomeDouble = 1000.0e6;

  // Minimize whitespaces. whitespaces should be used to sepate two thoughts. Do not start or end with whitespaces. Avoid using more than one whitespaces, never use more than two.

  // No spaces around period or arrow
  x  = r->y;

  // Each line of text must be 80 or less characters long.

  // variables needed for: if, for, while statements should be declared and initialized in those statements.
  // UNLESS IT IS AN OBJECT!
  // A single space should be used to separate looping and branching statements and their component/condition/iteration specifier.
  // Single space after each semicolon (;).
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
