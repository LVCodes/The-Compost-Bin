/* This driver file is provided by the course professor
* and none of the code here is by me or modified by me
* * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <fstream>
#include <string>
#include "storytokenizer.h"
using namespace std;

const string INPUT_FILE = "input.txt";

int main()
{
  string line, story;

  //Open input.txt for reading
  ifstream in(INPUT_FILE);
  if (!in.is_open())
  {
    cout << "Couldn't open " << INPUT_FILE << " for reading!\n";
    return 1;
  }

  //Read in the story from input.txt
  getline(in, line);
  while (in && line != "</html>")
  {
    story += line + '\n';
    getline(in, line);
  }

  //Construct the StoryTokenizer object
  StoryTokenizer st(story);

  //Iterate through all of the passages in the story
  int pass = 0;
  while (st.hasNextPassage())
  {
    //Use the PassageToken to construct a PassageTokenizer
    PassageToken ptok = st.nextPassage();
    PassageTokenizer pt(ptok.getText());

    //Iterate through all of the parts of the passage
    pass++;
    cout << "Passage " << pass << ":  " << endl;
    while (pt.hasNextPart())
    {
      PartToken stok = pt.nextPart();
      switch (stok.getType())
      {
      case LINK:
        cout << "  Link:  ";
        break;
      case SET:
        cout << "  Set:  ";
        break;
      case GOTO:
        cout << "  Go-to:  ";
        break;
      case IF:
        cout << "  If:  ";
        break;
      case ELSEIF:
        cout << "  Else-if:  ";
        break;
      case ELSE:
        cout << "  Else:  ";
        break;
      case BLOCK:
        cout << "  Block:  ";
        break;
      case TEXT:
        cout << "  Text:  ";
        break;
      default:
        cout << "  Unknown token:  ";
      }
      cout << stok.getText() << endl;
    }
  }

  return 0;
}
