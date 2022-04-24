#ifndef _STORYTOKENIZER_H
#define _STORYTOKENIZER_H

#include <string>

using namespace std;
enum TokenType {
    LINK = 1,
    GOTO = 2,
    SET = 3,
    IF = 4,
    ELSEIF = 5,
    ELSE = 6,
    BLOCK = 7,
    TEXT = 8
};

//get the name and text
class PassageToken {
private:
    string passage;
public:
    PassageToken(string passage);

    string getText() const;

    string getName() const;
};


class PartToken {
private:
    string part;
public:
    PartToken(string part);

    string getText();

    TokenType getType();


};


class PassageTokenizer {
private:
    TokenType previousType; //added
    string passage;
    int position;

public:

    PassageTokenizer(string passage);

    bool hasNextPart();

    PartToken nextPart();

};


class StoryTokenizer {

private:

    //variables to store the body and starting position
    string story;
    int startPos;

public:

    StoryTokenizer(string storyString);

    bool hasNextPassage();

    PassageToken nextPassage();

};

#endif

