#include <string>
#include <iostream>
using namespace std;

#include "Child.h"

/// @brief Parameterless constructor for child
Child::Child(): Child("Unnamed") {};

/// @brief Parametered constructor for child
/// @param name Te child's name
Child::Child(string name): name(name) {}