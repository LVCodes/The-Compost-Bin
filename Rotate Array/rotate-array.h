/* This header file was provided by the professor
 * of this course to guide the construction of the
 * source code to be built. None of the code in
 * this header file is mine or modified by me.
 * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __ROTATE_ARRAY_H
#define __ROTATE_ARRAY_H

#include <iostream>
using namespace std;

const int DEFAULT_CAPACITY = 8;

//Class for storing an extensible array
//of ints that can rotate
class RotatableArray
{
  friend ostream& operator<<(ostream&, const RotatableArray&);
private:
  int* data;
  int size;
  int capacity;
public:
  //Default constructor
  //Creates an empty RotatableArray
  RotatableArray();

  //Copy and move constructors and assignment
  RotatableArray(const RotatableArray&);
  RotatableArray(RotatableArray&&);
  RotatableArray& operator=(const RotatableArray&);
  RotatableArray& operator=(RotatableArray&&);
  //Destructor
  ~RotatableArray();

  //Basic getters
  int getSize() const { return size; }
  int getCapacity() const { return capacity; }

  //Adding, removing, and accessing elements
  void push_back(int);
  int pop_back();
  int& operator[](int);
  int operator[](int) const;

  //Array rotation
  //Positive argument:  rotate right
  //Negative argument:  rotate left
  void rotate(int);
};

//Print function
//Separates elements with spaces
//May add extra space at the end
ostream& operator<<(ostream&, const RotatableArray&);

#endif
