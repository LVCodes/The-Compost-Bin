/* Lauren Vogel    COP 3331    Summer 2020
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
