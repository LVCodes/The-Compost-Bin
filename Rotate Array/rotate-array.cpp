/* Lauren Vogel    COP 3331    Summer 2020
*
* This project requires developing a class that supports array
* rotation. Rotating an array is an operation where you shift
* all elements of the array some number of positions left or
* right, and elements that are shifted off of the left or right
* end of the array "wrap around" to the right or left end,
* respectively.
*
* For example, if rotating the array [1, 2, 3, 4, 5] to the
* right by 1, we get the array [5, 1, 2, 3, 4]. If we rotate it
* to the left by 2 (or to the right by 3), we get [3, 4, 5, 1, 2].
*
* The rotate function only needs to accept arguments in the range
* -(size - 1) to (size - 1), with negative values indicating a
* left rotation and positive values a right rotation, though it is
* reasonably easy to support larger values using modular arithmetic.
* We can also choose to implement the left and right rotations using
* two different cases. Also, it is recommended to allocate a
* temporary array to perform the rotation; just make sure to free
* memory appropriately afterwards. We are allowed to use the memcpy
* function (in <cstring>, see documentation) to copy array elements
* from one place to another, but for loops will work, as well.
*
* Classes should also support adding an arbitrary number of elements
* to the array via push_back, similar to a vector. To accomplish this,
* the class should have data members that store the size (number of
* elements added) and capacity (allocated size) of the array. When
* pushing back another element, if size == capacity, it should
* allocate an array twice as large as the previous array (and update
* the capacity) and copy the elements in the previous array to the new
* one, before freeing the old array and updating the pointer data
* member to point to the new array. At this point, it can add the new
* element as normal.
*
* The class must also support appropriate copy and move operations,
* as well as a destructor. A full list of required functions and their
* descriptions are:
*
* -RotatableArray(): creates an empty array with capacity = 8
* -RotatableArray(const RotatableArray&): copy constructor; makes a deep
* copy of its argument
* -RotatableArray(RotatableArray&&): move constructor; takes the array
* from its argument
* -RotatableArray& operator=(const RotatableArray&): copy assignment;
* makes a deep copy of its argument
* -RotatableArray& operator=(RotatableArray&&): move assignment; takes
* the array from its argument
* -RotatableArray(): destructor; deallocates the array
* -void push_back(int): adds the given integer to the back of the array,
* doubling the capacity if out of space
* -int pop_back(): removes an element from the array and returns it. If
* array is empty, no change and returns 0.
* -int& operator[](int): returns a reference to the given element of the
* array (no bounds checking required)
* -int operator[](int) const: similar to previous, as an accessor
* -void rotate(int): rotates the array; positive arguments rotate to the
* right, while negative arguments rotate to the left. We may assume the
* argument is in the range -(size - 1) to size - 1.
* -ostream& operator<<(ostream&, const RotatableArray&) **Not a member
* function**: prints the elements of the array, separated by spaces.
* It may print an extra space at the end for convenience
*
*
* Compile with g++
* */

#include "rotate-array.h"
#include <iostream>
using namespace std;

RotatableArray::RotatableArray(){
    size = 0;
    capacity = DEFAULT_CAPACITY;
    data = new int[capacity];//dynamically allocates array of size capacity
}


RotatableArray::RotatableArray(const RotatableArray& copy){

    size = copy.size;
    capacity = copy.capacity;

    data = new int[capacity];
    for(int i = 0; i < size; i++)
        data[i] = copy.data[i];
}


//Do the move constructor
//it will look almost identical to copy
//she just got an extra &&
RotatableArray::RotatableArray(RotatableArray&& move){

    size = move.size;
    capacity = move.capacity;
    data = move.data;
    move.data = nullptr;//set move.data to nullptr so she dont use double team on ur ass
}



RotatableArray& RotatableArray::operator = (const RotatableArray& copy){

    size = copy.size;
    capacity = copy.capacity;

    data = new int[capacity];
    for(int i = 0; i < size; i++)
        data[i] = copy.data[i];

    return *this;
}


//she just got an extra &&
RotatableArray& RotatableArray::operator = (RotatableArray&& move){

    size = move.size;
    capacity = move.capacity;
    data = move.data;
    move.data = nullptr;//set move.data to nullptr so she dont use double team on ur ass

    return *this;
}


RotatableArray::~RotatableArray(){

    delete[] data;
}


void RotatableArray::push_back(int pb){

    if(size < capacity)
        data[size] = pb;
    else {
        capacity *= 2;
        int* temp = new int[capacity];

        for(int i = 0; i < size; i++)
            temp[i] = data[i];
        delete[] data;
        data = temp;
        data[size] = pb;
    }

    size++;
}

int RotatableArray::pop_back(){

    if(size == 0)
        return 0;

    else {
        size--;
        return data[size];
    }
}

int& RotatableArray::operator[](int bracket){

    return data[bracket];
}

int RotatableArray::operator[](int bracket) const{

    return data[bracket];
}

void RotatableArray::rotate(int rot){

    int* temp = new int[capacity];
    if(rot < 0){
        rot *= -1;
        for(int i = rot; i < rot + size; i++)
            temp[i - rot] = data[i % size];
    }

    else {
        for(int i = rot; i < (rot + size); i++)
            temp[i - rot] = data[i % size];

    }

    delete[] data;
    data = temp;
}


ostream& operator<<(ostream& output, const RotatableArray& rot){

    for(int i = 0; i < rot.getSize(); i++)
        output << rot[i] << " ";
    return output;
  //123
}
