/*
* Driver provided by professor of the course
* and was not created or modified by the group.
*/
#include <string>
#include <iostream>
#include "story.h"
using namespace std;

const string FILENAME = "if.html";

int main()
{
  Story* story = new Story(FILENAME);
  story->play();

  delete story;
  return 0;
}
