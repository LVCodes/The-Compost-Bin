// Group Members:
//                   Mabel Sugar-Langewisch
//                   Lauren Vogel
//                   Darshan Vala
/*
* This is the final part of the multi-part project where it
* becomes a group project. This meant we had to share our code
* from previous parts with each other and decide what portions
* we wanted to puzzle-piece together from each of our individual
* parts.
*
* Guidelines:
*
* In this part of the project, the group will finish implementing
* the code for the interpreter. The driver file is given and that
* will initialize a Story object with the file if.html and call
* its play() function, which should all the user to experience the
* story described in if.html.
*
*
* Specifications:
*
* This section details the various components of an interactive
* fiction story. These sections will also detail how these parts
* should act and connect together to form a story. Implementation
* for this project should support the features described below.
*
*
* The Interpreter:
*
* IF interpreter should start by opening the file if.html and
* reading in the story data. We may assume that the input does not
* contain any syntax or logical errors (e.g., testing a variable in
* an (if:) command before it has been (set:)). Once it has
* constructed objects to represent the structure of the story, the
* interpreter should start by displaying the first passage defined
* in if.html. When displaying a passage, the program should execute
* all commands appropriately and properly display all links. Note
* the interpreter will need to keep track of the variables that have
* been defined, as well as their values. It should use an
* unordered_map data member for this purpose
* (#include <unordered_map>); you do not need to define a specialized
* class to match variables to their values. We will cover
* unordered_maps more when we discuss the Standard Template Library in
* class. After displaying a passage, the interpreter should print out
* a numbered list of all links in the passage, and prompt the reader to
* select one. When displaying a passage, the program should execute any
* commands that appear in that passage appropriately and properly
* display all links (see Section below). After displaying the passage,
* the interpreter should print out a numbered list of all links in the
* passage and prompt the reader to select one. This list should start
* numbering at 1; e.g.,
* 1. Take the red pill
* 2. Take the blue pill
* Once the reader has selected a link, the interpreter should display
* the corresponding passage (see Links section below). This should
* continue until the reader reaches a passage with no links, at which
* point the interpreter should terminate.
*
*
* Passages:
*
* Interactive fiction works are divided into passages, which appear
* in the <tw-passagedata> tags in the HTML file. Each passage will
* start with <tw-passagedata ...> and will end with </tw-passagedata>.
* In addition to starting with <tw-passagedata, the opening tag will
* specify some attributes, like pid, name, tags, and location, and the
* body of the passage will be between the opening and closing tags.
* Example passage:
* <tw-passagedata pid="1" name="start" tags="" location="100,100">
* The body of the passage will be here.
* </tw-passagedata>
* The interpreter only needs to pay attention to the name attribute of
* each passage, the other attributes can be safely ignored. In the body
* of a passage, there are 3 different types of things to deal with: text,
* links, and commands. When a passage is being displayed, text should
* appear as typed (including spacing), however, links will display
* differently than they appear in the input file, and commands can cause
* a variety of different things to happen.
*
*
* Links:
*
* Links in the body will be denoted by double brackets: [[ and ]]. Links
* are treated differently depending on whether or not they contain the
* characters -&gt;. A link that doesn’t contain these characters should
* appear in the text without the double brackets, and this link should be
* presented to the reader as an option to further the story after the
* passage has displayed. When selected, the link should display the passage
* with the name that matches the link text.
* A link that contains the characters -&gt; should display as the characters
* to the left of -&gt;; however, it should link to the passage whose name
* matches the characters to the right of the -&gt;.
* Example links:
* [[Simple]]
* Displays as “Simple”; links to passage named “Simple”
* [[Take the blue pill-&gt;Bad dream?]]
* Displays as “Take the blue pill”; links to passage named “Bad dream?”
*
*
* Commands:
*
* Commands are denoted by a single word and a colon immediately after an
* open parenthesis. The IF interpreter should support 5 different commands:
* (go-to:, (set:, (if:, (else-if:, and (else:.
*
* Go-to command:
* The go-to command should cause the program to immediately change to the
* given passage. Any other text, commands, or links that appear after the
* go-to command should be ignored, and any links before the go-to can be
* safely ignored, as though the reader had selected the given passage as
* their choice. The name of the passage to go to will appear between two
* copies of &quot;.
* Example go-to command:
* When a passage is being displayed, text should appear as typed (including
* spacing), however, links will display differently than they appear in the
* input file, and commands can cause a variety of different things to happen.
*
*
* Links:
*
* Links in the body will be denoted by double brackets: [[ and ]]. Links are
* treated differently depending on whether or not they contain the characters
* -&gt;. A link that doesn’t contain these characters should appear in the
* text without the double brackets, and this link should be presented to the
* reader as an option to further the story after the passage has displayed.
* When selected, the link should display the passage with the name that matches
* the link text. A link that contains the characters -&gt; should display as
* the characters to the left of -&gt;; however, it should link to the passage
* whose name matches the characters to the right of the -&gt;.
* Example links:
* [[Simple]]
* Displays as “Simple”; links to passage named “Simple”
* [[Take the blue pill-&gt;Bad dream?]]
* Displays as “Take the blue pill”; links to passage named “Bad dream?”
*
*
* Commands:
*
* Commands are denoted by a single word and a colon immediately after an
* open parenthesis. Your IF interpreter should support 5 different commands:
* (go-to:, (set:, (if:, (else-if:, and (else:.
*
* Go-to command:
* The go-to command should cause the program to immediately change to the
* given passage. Any other text, commands, or links that appear after the go-
* to command should be ignored, and any links before the go-to can be safely
* ignored, as though the reader had selected the given passage as their choice.
* The name of the passage to go to will appear between two copies of &quot;.
* Example go-to command:
* (go-to: &quot;start&quot;)
* Continues the story with the passage named “start”, as though the reader had
* selected a link leading to this passage.
*
* Set command:
* The (set: command allows the IF author to define and set the value of a
* variable. Note that the (set: command will never display any text; however, it
* will execute any time a passage containing it is displayed. Variables that do
* not exist are created, while variables that do exist are updated. While the full
* specification for Harlowe allows for three different types of variables (numeric,
* string, and Boolean), you should treat all variables as Boolean. The first word
* after the colon in the (set: command will be a variable name, which always starts
* with $. The second will be the keyword to, and the third will be the assigned
* value (true or false).
* Example set command:
* (set: $ateCake to true)
* Stores true as the value of the $ateCake variable
*
*
* If/Else if/Else:
*
* The (if:, (else-if:, and (else: commands act much like they do in C++. The (if:
* and (else-if: commands will be followed by a variable, the key-word is, and a
* value to test the variable against, followed by the closing parenthesis.
* (else:) has no condition. The blocks that if, else-if, and else apply to are
* denoted by brackets []. Note that links and other commands (including other (if:
* commands) maybe embedded in these blocks. While PassageTokenizer extracts blocks
* as a single token, you can create another PassageTokenizer to parse the contents
* of the block.
* When displaying a passage with an (if: command, the contents of the associated
* block will only be displayed if the condition of the if statement is true. Blocks
* associated with (else-if: commands will only be displayed while Harlowe allows
* much more sophisticated versions of this syntax, including arithmetic operations
* (+, −, etc.), relational operators (<, <, etc.), and logical connectives (and, or,
* not), we will only support simple assignments to Boolean variables.
* if the previous (if: and (else-if: conditions were false and the condition for
* this command is true, while blocks associated with (else:) commands will only be
* displayed if the preceding (if: and (else-if: conditions have failed.
* Example if command:
* (if: $ateCookie is false)[You’re still a bit hungry.]
* (else-if: $ateCake is false)[You sigh contentedly.]
* (else:)[You feel ill.]
*
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
