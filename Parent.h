#ifndef PARENT_H
#define PARENT_H

#include <string>
using namespace std;

#include "Child.h"

class Parent {
    public:
        // Constructors
        Parent();
        Parent(Child* initial_children, int count);

        // Data members
        Child* array_A;
        Child* array_B;
        int A_count;
        int B_count;

        // Member functions
        void A_to_B(string name);
        void B_to_A(string name);

        void print_A();
        void print_B();

        // Helper functions
        void add_to_A(Child child);
        void add_to_B(Child child);

        void remove_from_A(int index);
        void remove_from_B(int index);

};
#endif // PARENT_H