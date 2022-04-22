/* This driver file was provided by the professor
 * of this course to guide the construction of the
 * source code to be built. None of the code in
 * this driver file is mine or modified by me.
 * * * * * * * * * * * * * * * * * * * * * * * * */
using namespace std;
#include <fstream>
#include "rotate-array.h"

//Tests rotate function
//Also uses constructor, push_back,
//and print function (cout << arr)
int test1()
{
  ofstream out("test1.txt");
  RotatableArray arr;
  for (int i = 0; i < 10; i++)
    arr.push_back(i+1);
  out << "Original array:\n" << arr << endl;
  
  //Test rotation
  arr.rotate(3);
  out << "Rotated by 3:\n" << arr << endl;

  out.close();
  return 0;
}

//Test push_back, pop_back, and operator[]
//Also uses rotate and print function
int test2()
{
  ofstream out("test2.txt");
  RotatableArray arr;
  arr.push_back(1);
  out << "rotate(1) and push_back * 10:\n" << arr << '\n';
  for (int i = 2; i <= 10; i++)
  {
    arr.rotate(1);
    arr.push_back(i);
    out << arr << '\n';
  }

  //Test operator[]
  for (int i = 0; i < arr.getSize(); i++)
    arr[i]--;
  out << "Decrementing every element:\n" << arr << '\n';

  //Test pop_back
  out << "rotate(1) and pop_back() * 10:\n";
  for (int i = 0; i < 10; i++)
  {
    arr.rotate(1);
    arr.pop_back();
    out << arr << '\n';
  }
  out.close();
  return 0;
}

int main()
{
  test1();
  test2();
  return 0;
}
