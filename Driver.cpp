#include <string>
#include <iostream>
using namespace std;

#include "Child.h"
#include "Parent.h"

/// @brief Driver code for Parent and Child
/// @return Whether the code executed successfully
int main() {
    // Generate an array of children and initialise a parent with it
    int test_count = 10;
    Child* test_children = new Child[test_count];

    for (int i = 0; i < test_count; i++) {
        string name = "Child #" + to_string(i);
        test_children[i] = Child(name);

    }

    Parent test_parent = Parent(test_children, test_count);

    // Move elements from array A to B
    test_parent.A_to_B("Child #5");
    test_parent.A_to_B("Child #1");

    // Attempt to move the same element twice
    test_parent.A_to_B("Child #5");

    // Move elements from array A to B
    test_parent.A_to_B("Child #0");
    test_parent.A_to_B("Child #3");
    test_parent.A_to_B("Child #2");

    // Move element from array B to A
    test_parent.B_to_A("Child #3");

    // Attempt to move element that is not in B
    test_parent.B_to_A("Child #9");

    // Create a new child and add it to array B
    Child new_child = Child("Child #X");
    test_parent.add_to_B(new_child);

    // Move elment from array B to A
    test_parent.B_to_A("Child #X");

    // Print  arrays A and B
    test_parent.print_A();
    test_parent.print_B();

    return 0;
}