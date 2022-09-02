#include <string>
#include <iostream>
using namespace std;

#include "Child.h"

// Constructors
Child::Child(): Child("Unnamed") {};
Child::Child(string name): name(name) {}

Child Child::operator=(Child child) {
    return Child(name = child.name);
}