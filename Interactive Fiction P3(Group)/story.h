// Group Members:
//                   Mabel Sugar-Langewisch
//                   Lauren Vogel
//                   Darshan Vala


#ifndef PROJECTPART5_STORY_H
#define PROJECTPART5_STORY_H

#include <vector>
#include <unordered_map>
#include "storytokenizer.h"

using namespace std;

class Token;

class Passage {
private:
    //name of the passages
    string name;
    //passages contains an array of tokens
    vector<Token> tokens;

    vector<Token> getTokensByType(TokenType type);

    // returns links within the give token
    vector<Token> processTokens(vector<Token> tokens, unordered_map<string, bool> &vars);

public:
    Passage(PassageToken);


    string play(unordered_map<string, bool> &); //return string matching the name of the
    //nextpassage to be called
    //if no more passages are called, then she returns an empty string
    string getName() {
        return name;
    }

    static vector<Token> extractTokens(string text);
};

class Story {
private:
    vector<Passage> passages;
    // map of passage names to their associated passage
    // recall that these passages are effectively just pointers
    unordered_map<string, Passage> nameToPassage;
    //defined variables and their corresponding values
    unordered_map<string, bool> vars;
public:
    Story(string filename);

    void play();

    /*MABEL!!! Beware of play() she has direct impact on block
     *(who is recursive by nature) so you may have to change
     *the function signature to use her for block!!*/

};


class Token {
private:
    vector<Token> tokens;
    TokenType type;
    string text;
    // either split token into different classes, or have a bunch of class variables for the different types of tokens
    string linkText;
    string linkTarget;
    string goToTarget;
    string setVariable;
    bool setValue;
    string ifVariable;
    bool ifValue;

public:
    Token() {};

    Token(TokenType type, string text);


    void setTokens(vector<Token> tokens);

    vector<Token> getTokens();

    string getText();

    TokenType getType();

    // either split token into different classes, or have a bunch of functions for the different types of tokens
    string getLinkText();

    string getLinkTarget();

    string getGoToTarget();

    string getSetVariable();

    bool getSetValue();

    string getIfVariable();

    bool getIfValue();

};



#endif //PROJECTPART5_STORY_H
