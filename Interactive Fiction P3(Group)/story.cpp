// Group Members:
//                   Mabel Sugar-Langewisch
//                   Lauren Vogel
//                   Darshan Vala
/*
* Compile with g++ *.cpp -o if
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include "story.h"
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

//LAUREN
Story::Story(string filename) {
    ifstream input(
            filename.c_str()); //is important to function constructor correctly (make sure it isn't the default constructor)
    string story, line;
    getline(input, line);
    while (input && line != "</html>") {
        story += line + '\n';
        getline(input, line);
    }
    input.close();
    StoryTokenizer st(story);
    size_t i = 0;
    while (st.hasNextPassage()) {
        Passage nextPass = st.nextPassage();
        passages.push_back(nextPass);
        nameToPassage.insert({nextPass.getName(), nextPass});
    }
}

//LAUREN
void Story::play() {
    string passageName = passages.at(0).play(vars);
    while (passageName != "") {
        passageName = nameToPassage.at(passageName).play(vars);
    }
}


//LAUREN  & MABEL & DARSHAN
Token::Token(TokenType type, string text) {
    this->type = type;
    this->text = text;

    // have to move token text parsing logic to constructor so anyone using a token can access the items they
    // need directly. for example, when interacting with a link we may need to get the text directly, or get the
    // target directly
    switch (type) {

        //MABEL
        case TEXT : {
            break;
        }

            //MABEL
        case LINK : {
            string startBrackets = "[[";
            string endingBrackets = "]]";
            string between = "-&gt;";
            if (text.find(between) == -1) //-1 means is no
            {
                //substring to get rid of starting and ending bracket
                //get rid of [[kjnikjnkj]]

                //finds starting
                int start = text.find(startBrackets) + startBrackets.length();
                //finds end
                int end = text.find(endingBrackets);
                //len of the part wanted
                int length = end - start;

                string linkText = text.substr(start, length);
                this->linkText = linkText;
                this->linkTarget = linkText;
            } else {
                int split = text.find(between);

                /*first text*/
                //finds starting
                int start1 = text.find(startBrackets) + startBrackets.length();
                //len of the part wanted
                int length1 = split - start1;
                string linkText1 = text.substr(start1, length1);

                /*second text*/
                int end2 = text.find(endingBrackets);
                int start2 = text.find(between) + between.length();
                //len of the part wanted
                int length2 = end2 - start2;
                string linkTex2 = text.substr(start2, length2);

                this->linkText = linkText1;
                this->linkTarget = linkTex2;
            }

            break;
        }

            //MABEL
        case GOTO: {
            string gotoOpen = "(go-to: ";
            string partToRemove = "&quot;";

            //finds starting position
            int start = text.find(partToRemove) + partToRemove.length();
            //finds end position
            int end = text.find(gotoOpen) + gotoOpen.length() + start;

            //len of the part wanted
            int length = end - start;

            string gotoText = text.substr(start, length);

            this->goToTarget = gotoText;
            break;
        }

            //MABEL
        case SET: {
            string setOpen = "$";
            string closeParenthesis = ")";

            string setOpen2 = " ";

            if (text.find(" to ") == -1) {
                setOpen2 = " is ";
            } else {
                setOpen2 = " to ";
            }

            /*first*/
            //finds starting
            int start1 = text.find(setOpen) + setOpen.length();
            int end1 = text.find(setOpen2);
            //len of the part wanted
            int length1 = end1 - start1;
            string setText1 = text.substr(start1, length1);

            /*second */
            int start2 = text.find(setOpen2) + setOpen2.length();
            int end2 = text.find(closeParenthesis);
            int length2 = end2 - start2;
            string setText2 = text.substr(start2, length2);

            this->setVariable = setText1;
            this->setValue = (setText2 == "true" ? true : false);  //LAUREN ARE YOU PROUD?? LOL
                                                                   //VERY! We live laugh love for ternary <3

            break;
        }

            //DARSHAN
        case IF: {

            string ifOpen = "$";
            string closeParenthesis = ")";
            string ifOpen2 = " is ";


            /*first*/
            //finds starting
            int start1 = text.find(ifOpen) + ifOpen.length();
            int end1 = text.find(ifOpen2);
            //len of the part wanted
            int length1 = end1 - start1;
            string ifText1 = text.substr(start1, length1);

            /*second */
            int start2 = text.find(ifOpen2) + ifOpen2.length();
            int end2 = text.find(closeParenthesis);
            int length2 = end2 - start2;
            string ifText2 = text.substr(start2, length2);

            this->ifVariable = ifText1;
            this->ifValue = (ifText2 == "true" ? true : false);
            break;

        }

            //DARSHAN
        case ELSEIF: {

            int dollar = (text.find(" $"));// beginning of variable
            int space = text.find("is ");
            int par = text.find(")");
            int brack = text.find("[");


            if (dollar == -1) // checks if $ is there or not
            {
//                cout << " not valid" << endl;
            } else {
                string variable = text.substr(dollar + 1, space - dollar - 2); // $variable
                int value = text.find("is");
                value = value + 3; // takes it to f or t

                if (text[value] == 'f') // checks if value is an f or t
                {
                    string val = "false";
                    this->ifVariable = variable;
                    this->setValue = false;
                } else if (text[value] == 't') {
                    string val = "true";
//                    cout << "Else-if:  " << "var=" << variable << ", " << "value=" << val << endl;
                    this->ifVariable = variable;
                    this->setValue = true;
                } else {
//                    cout << "not f or t" << endl;
//                    cout << value << endl;
                }
                break;
            }

        }

            //DARSHAN
        case ELSE: {
//            cout << "Else" << endl;

            break;
        }

            //MABEL
        case BLOCK: {
//
//            cout << "START BLOCK" << endl;
//
//            // printing a block token involves printing all the inside tokens of the block sequentially
//            for (Token t : this->tokens) //re-used loop that LAUREN wrote
//                t.print(); // iterate this.tokens and call
//
//            cout << "END BLOCK" << endl;
            break;
        }

        default: {
//            cout << "Error!" << endl;
        }
    }

}


//MABEL
void Token::setTokens(vector<Token> tokens) {
    this->tokens = tokens;
}

string Token::getText() {
    return text;
}

TokenType Token::getType() {
    return type;
}

string Token::getLinkText() {
    return linkText;
}

string Token::getLinkTarget() {
    return linkTarget;
}

string Token::getGoToTarget() {
    return goToTarget;
}

string Token::getSetVariable() {
    return setVariable;
}

bool Token::getSetValue() {
    return setValue;
}

string Token::getIfVariable() {
    return ifVariable;
}

bool Token::getIfValue() {
    return ifValue;
}

vector<Token> Token::getTokens() {
    return tokens;
}

//LAUREN and MABEL
Passage::Passage(PassageToken ptok) {
    name = ptok.getName();
    PassageTokenizer pt(ptok.getText());
    this->tokens = this->extractTokens(ptok.getText()); //Mabel added this

}


string Passage::play(unordered_map<string, bool> &vars) {
    // handle variables for this passage
    vector<Token> setTokens = getTokensByType(SET);
    for (int set = 0; set < setTokens.size(); set++) {
        // insert or replace
        vars.emplace(setTokens.at(set).getSetVariable(), setTokens.at(set).getSetValue()).first->second = setTokens.at(
                set).getSetValue();
    }

    // handle command tokens maybe relating to vars map
    vector<Token> links = processTokens(this->tokens, vars);

    // display ordered list of links
    if (links.size() == 0) {
        return "";
    }
    cout << endl << "Select a link number:" << endl;
    for (int link = 0; link < links.size(); link++) {
        cout << (link + 1) << ". " << links.at(link).getLinkText() << endl;
    }

    int chosenLink;
    cin >> chosenLink;

    Token link = links.at(chosenLink - 1);
    string target = link.getLinkTarget();

    // handle GOTO tokens which immediately change the passage
    vector<Token> goToTokens = getTokensByType(GOTO);
    for (int goTo = 0; goTo < goToTokens.size(); goTo++) {
        // if there are more than one we only return with the first
        return goToTokens.at(goTo).getGoToTarget();
    }

    return target;

}


vector<Token> Passage::processTokens(vector<Token> tokens, unordered_map<string, bool> &vars) {
    vector<Token> links;
    // only want to evaluate else if neither if or elseif were true
    bool ifTrue = false;
    bool elseIfTrue = false;
    for (int i = 0; i < tokens.size(); i++) {

        if (tokens.at(i).getType() == IF || tokens.at(i).getType() == ELSE || tokens.at(i).getType() == ELSEIF) {
            vector<Token> moreLinks;
            Token command = tokens.at(i);
            // command tokens give us block
            if (command.getType() == IF) {
                if (vars.find(command.getIfVariable())->second == command.getIfValue()) {
                    ifTrue = true;
                    // block will be the next token after this command token at i
                    moreLinks = processTokens(tokens.at(i + 1).getTokens(), vars);
                }
            } else if (command.getType() == ELSEIF) {
                if (vars.find(command.getIfVariable())->second == command.getIfValue()) {
                    elseIfTrue = true;
                    // block will be the next token after this command token at i
                    moreLinks = processTokens(tokens.at(i + 1).getTokens(), vars);
                }
            } else if (command.getType() == ELSE) {
                if (ifTrue || elseIfTrue) {
                    // do nothing
                } else {
                    // block will be the next token after this command token at i
                    moreLinks = processTokens(tokens.at(i + 1).getTokens(), vars);
                }
                ifTrue = false;
                elseIfTrue = false;
            }
            //need to keep track of the other links inside other tokens
            if (moreLinks.size() > 0) {
                links.insert(links.end(), moreLinks.begin(), moreLinks.end());
            }
        } else if (tokens.at(i).getType() == TEXT) {
            cout << tokens.at(i).getText() << flush;
        } else if (tokens.at(i).getType() == LINK) {
            links.emplace_back(tokens.at(i));
            cout << "\"" << tokens.at(i).getLinkText() << "\"";
        } else if (tokens.at(i).getType() == GOTO) {
            break;
        }
    }
    return links;
}

//LAUREN and MABEL
vector<Token> Passage::extractTokens(string text) {
    vector<Token> tokens;
    PassageTokenizer pt(text); //LAUREN wrote this

    while (pt.hasNextPart()) { //LAUREN wrote this
        PartToken part = pt.nextPart(); //LAUREN wrote this
        Token token = Token(part.getType(), part.getText()); //LAUREN wrote this, Mabel put it in a variable to re-use


        if (part.getType() == BLOCK) {
            // a block is essentially a passage so we can reuse PassageTokenizer
            // first need to remove the leading and trailing tags '[' and ']' as PassageTokenizer does not use them
            string originalBlockText = part.getText();
            string blockToTokenize = originalBlockText.substr(1, originalBlockText.length() - 2);

            // a block may be multiple levels deep, so recursively extract tokens for this block and any inside blocks
            vector<Token> blockTokens = extractTokens(blockToTokenize);
            token.setTokens(blockTokens);
        }

        tokens.emplace_back(token); // LAUREN wrote this
    }

    return tokens;

}

// returns everything before a 'GOTO' token is seen
vector<Token> Passage::getTokensByType(TokenType type) {
    vector<Token> result;

    for (int i = 0; i < this->tokens.size(); i++) {
        if (this->tokens.at(i).getType() == GOTO) {
            break;
        }
        if (this->tokens.at(i).getType() == type) {
            result.emplace_back(this->tokens.at(i));
        }
    }

    return result;
}
