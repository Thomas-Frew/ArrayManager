#include <string>
#include <iostream>
using namespace std;

#include "Child.h"
#include "Parent.h"

Parent::Parent(Child* initial_children, int count) {
    // Initialise our arrays
    array_A = new Child[count];
    array_B = new Child[0];

    // Import our initial children into array A
    for (int i = 0; i < count; i++) {
        array_A[i] = initial_children[i];
    }

    // Begin tracking the number of elements in each array
    A_count = count;
    B_count = 0;
}

void Parent::A_to_B(string name) {
    for (int i = 0; i < A_count; i++) {
        
        // If we find a match for the search name...
        if (array_A[i].name == name) {
            Child child = array_A[i];

            cout << name << " was moved from A to B." << endl;

            // Add the child to B
            add_to_B(child);

            // Remove the child from A
            remove_from_A(i);

            return;
        }
    }

    cout << name << " was not found." << endl;
}

void Parent::B_to_A(string name) {
    for (int i = 0; i < B_count; i++) {
        
        // If we find a match for the search name...
        if (array_B[i].name == name) {
            Child child = array_B[i];

            cout << name << " was moved from B to A." << endl;

            // Add the child to B
            add_to_A(child);

            // Remove the child from A
            remove_from_B(i);

            return;
        }
    }

    cout << name << " was not found." << endl;
}

void Parent::print_A() {
    cout << "Array A:" << endl;

    for (int i = 0; i < A_count; i++) {
        cout << "A[" << i << "]: " << array_A[i].name << endl;
    }
}

void Parent::print_B() {
    cout << "Array B:" << endl;

    for (int i = 0; i < B_count; i++) {
        cout << "B[" << i << "]: " << array_B[i].name << endl;
    }
}

void Parent::add_to_B(Child child) {
    Child* temporary = new Child[B_count + 1];

    int i = 0;
    for (; i < B_count; i++) {
        temporary[i] = array_B[i];
    }

    delete[] array_B;

    array_B = temporary;
    array_B[i] = child;

    B_count++;
}

void Parent::add_to_A(Child child) {
    Child* temporary = new Child[A_count + 1];

    int i = 0;
    for (; i < A_count; i++) {
        temporary[i] = array_A[i];
    }

    delete[] array_A;

    array_A = temporary;
    array_A[i] = child;

    A_count++;
}

void Parent::remove_from_A(int index) {
    for (int i = index; i < A_count - 1; i++) {
        array_A[i] = array_A[i+1];            
    }
    
    A_count--;
}

void Parent::remove_from_B(int index) {
    for (int i = index; i < B_count - 1; i++) {
        array_B[i] = array_B[i+1];            
    }
    
    B_count--;
}