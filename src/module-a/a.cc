// a.cc
//==============================================================================
// Author: Carl Larsson
// Creation date: 2024-09-09
// Last modified: 2024-09-18 by Carl Larsson
// Description: Example .cc file used for example file structure and Google C++ 
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
// - Use // to create comments.
// - The use of the "using" directive to remove the need to write the namespace 
// name is FORBIDDEN!
// - Try to keep as small and local scope as possible, if a class, enum, struct 
// or similar is only to be used in this .cc file, then it can be declared here,
// otherwise have it in the .h file.
// - Minimize whitespaces. whitespaces should be used to sepate two thoughts. Do 
// not start or end with whitespaces. Avoid using more than one whitespaces, 
// never use more than two.
// - Each line of text must be 80 or less characters long.


// - If this file needs something from other_header_needed.h then it should be 
// included, even if it already is included in a.h. This goes for all 
// inclusions. What this means is that you should not rely on transistive 
// inclusions.
// - Headers should be included in the order of: related headers, C system 
// headers, C++ standard library headers, other libraries headers, and then 
// finally projects headers.
// - Alphabetical ordering should be used internally to each category.
// - Always have a empty line between each category.
// - Only use <> for includes when the library requires it.

// - Related .h file, related maybe because we are for example implementing or 
// testing the stuff from a.h.
// - Avoid forward declerations, instead include the headers you need (see a.h).
// - Project headers should be included as decendents of the src directory of 
// the project.
#include "module-a/a.h"

// Example C system header.
#include <unistd.h>

// Example C++ standard library header.
#include <algorithm>

// Other libraries .h files.
#include "other_header_needed.h"

// Projects .h files.
#include "somewhere/some_project_header.h"


// Always try to place code in namespaces.
// Do not use inline namespaces.
// Name should be unique names and based on project name and possibly path.
// namespace names are all lowercase with _ for word seperation.
// Project name
namespace project_structure
{
// Path
namespace module_a
{

// The contents of namespaces should not be indented.
...

// Function names begin with capital letter and have capital letter for each
// new word.
void SomeFunction();

// - Using the class, enum and struct from a.h, and avoiding forward decleration 
// since they were declared in a.h and then just included (from a.h) for use 
// here.
DoSomething(SomeClass);
DoSomethingElse(SomeEnum, SomeStruct);

...

} // namespace module_a
} // namespace project_structure


// - Write short and focused functions please!
// - If TempFunc does not need to be referenced outside of this file, then use 
// static (EXCEPT IF IT IS AN .h FILE!). Essentially, just try to use static 
// unless a global scope is required. Note that this is only the case if 
// namespaces is not used.
// - Non-optional input parameters should usually be values or const references.
// - Non-optional output or input/output parameters should be references (which 
// can not be null).
// - Try to use std::optional for optional by-value inputs. And use const 
// pointer when the non-optional form would have used a reference.
// - Use non-const pointer for optional outputs and optional input/output 
// parameters.
// - Try to have the parameter order be: inputs, input/ouputs, outputs.
// - Default arguments are allowed on non-virtual functions when the default is 
// guaranteed to always have the same value.
// - Every function should have a comment preceeding it explaining what it does 
// and how to use it. Also describe inputs and outputs. Additionally, for 
// pointer argumtents it should be described it they can be null and what 
// happens if they are.
// - Function names begin with capital letter and have capital letter for each
// new word.
static int TempFunc(int some_other_input,const *some_input, 
    int *some_input_output, void *some_output)
{
  // - Local variables should be initialized in the decleration.
  // - Variables should be declared as close to the place where they will be 
  // used as possible.
  // - DO NOT USE STATIC LOCAL VARIABLES!
  // - DO NOT USE SHORT, LONG OR LONG LONG!
  int var = 3;
  // - DO NOT use cast formats like: (int)x unless it is to void.
  // - Use C++ style casts like: static_cast<float>(double_value) or brace 
  // initialization like int64_t{1}.
  DoSomething(int64_t{var});

  // Always write floating-point with radix point and digits on both sides.
  float some_float = 1.0f;
  // DO NOT USE LONG DOUBLE!
  double some_double = -0.5L;
  double some_other_double = 1000.0e6;

  // - If a pointer is suppossed to not point to anything, or it is the end of 
  // list or similar, then use nullptr (also use it to check if pointer points 
  // to something).
  int *int_pointer = nullptr;
  // And if it is char, then use '\0'.

  // No spaces around period or arrow.
  x  = r->y;

  // Use sizeof(varname), not sizeof(type).
  SomeClass data;
  memset(&data, 0, sizeof(data));

  // - Variables needed for: if, for, while statements should be attempted to be 
  // declared and initialized in those statements. UNLESS IT IS AN OBJECT!
  // - A single space should be used to separate looping and branching 
  // statements and their component/condition/iteration specifier.
  // - Single space after each semicolon (;).
  // - Increment using ++i formand and decrement using the --i format.
  for (int i = 0; i < 100; ++i)
  {
    // DO NOT DECLARE VARIABLES IN LOOPS!
    ...
  }

  // while (condition); is not allowed.
  // Instead do:
  while (condition) {};
  // or
  while (condition) continue;

  // Switching statements must have a default case.
  switch (var) 
  {
    case 0;
    {
      ...
    }
    default:
    {
      ...
    }
  }

  // - Use return values over output parameters.
  // - Preferably return by value, if you can not, then return by reference. 
  // Avoid returning a raw pointer, unless it can be null.
  return something;
}
