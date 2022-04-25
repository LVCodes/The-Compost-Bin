/* Lauren Vogel     COP 3331     Summer 2020
 * Compile with g++
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __STORYTOKENIZER_H
#define __STORYTOKENIZER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PassageToken  //can a ma'am put two classes in a header? imma absolutely try
{
        //friend ostream& operator <<(ostream&, StoryTokenizer);
private:
        string name;
        string passage;
public:
        PassageToken(string name, string passage); //lmao tf
        string getName() const;//get the name so we can track this down
        string getText() const;//SHES gotta read CHEVRON to CHEVRON <tw-passagedata ...> and ending tag </tw-passagedata>


};
//ostream& operator <<(ostream&, StoryTokenizer);

class StoryTokenizer
{
        //friend ostream& operator <<(ostream&, story);
        //proabbly dont need an output stream for reading in text?

private:
        string passage;
        string name;
        vector<PassageToken> passages;
        size_t index;

public:  //high key dont really understand the distingishment between an accessor&constructor and
         //how it relates to const => im gonna be learning fAST
        StoryTokenizer(string); //The constructor whomest stores our fairy tale (this one gotta handle HTML fffffi n uhm)
        bool hasNextPassage() const;  //looks to see if we need to keep callin nextPassage
        PassageToken nextPassage();  //needs to return PassageToken,,,,,  vector it??? usin pushback for each passage token???????
};


#endif
