//
// Created by Mabel Sugar-Langewisch on 2020-06-09.
//

#include "storytokenizer.h"
#include <iostream>
#include <string.h>
#include <string>
#include <vector>


using namespace std;

///// StoryTokenizer START//////
bool StoryTokenizer::hasNextPassage() {

    //a next passage exist when
    if (story.find("<tw-passagedata", startPos) != -1) {
        return true;
    }

    return false;
}

PassageToken StoryTokenizer::nextPassage() {

    //getting starting position
    int sPosition = story.find("<tw-passagedata", startPos);
    string close = "</tw-passagedata>";

    //getting the ending position
    int ePosition = story.find(close) + close.length();

    //getting the length of the string between the open and close tags
    int length = ePosition - sPosition;
    string pass = story.substr(sPosition, length);

    //plus one to get the start of the next body
    startPos = sPosition + 1;

    return PassageToken(pass);
}

StoryTokenizer::StoryTokenizer(string storyString) {
    //storing the string
    story = storyString;
    startPos = 0;
}

/////PASSAGE TOKEN START//////
string PassageToken::getText() const {

    string open = ">";
    int sPosition = passage.find(open) + open.length();

    string close = "</tw-passagedata>";
    int ePosition = passage.find(close);


    //getting the length of the string to use it in substr
    int length = ePosition - sPosition;

    //pass has the body of the text
    string pass = passage.substr(sPosition, length);

    return string(pass);
}

string PassageToken::getName() const {

    string beforeName = "name=\"";

    string afterName = " tags=\"\"";

    int positionS = passage.find(beforeName) + beforeName.length();

    int positionE = passage.find(afterName) - 1;

    //getting length of the name to use in substr
    int size = positionE - positionS;

    //obtained has the name of the passage
    string obtained = passage.substr(positionS, size);

    return string(obtained);
}


PassageToken::PassageToken(string storyPassage) {
    passage = storyPassage;
}

/////PASSAGE TOKENIZER START//////
PassageTokenizer::PassageTokenizer(string ptokenizer) {
    previousType = TEXT;
    passage = ptokenizer;
    position = 0;

}

bool PassageTokenizer::hasNextPart() {
    if (passage.length() != position) {
        return true;
    } else {
        return false;
    }
}

PartToken PassageTokenizer::nextPart() {

    string linkOpen = "[[";
    string setOpen = "(set:";
    string gotoOpen = "(go-to:";
    string elseOpen = "(else:";
    string ifelseOpen = "(if-else:";
    string ifOpen = "(if:";
    string blockOpen = "[";

    // in some cases the previous token type indicates the next one should be considered a block
    // this handles some cases where after one of those known types we would otherwise find '[[[...]]]' being
    // interpreted as a link instead of a block
    bool expectingBlockNext = false;
    if (previousType == ELSE || previousType == ELSEIF || previousType == IF) {
        expectingBlockNext = true;
    }
    string result;

    if (!expectingBlockNext && linkOpen.compare(passage.substr(position, linkOpen.length())) == 0) {
        string endTag = "]]";
        int endPosition = passage.find(endTag, position) + endTag.length();

        //length of the total string (starting tag + text + close tag)
        int stringLength = endPosition - position;

        result = passage.substr(position, stringLength);

        //finding next starting postitio
        position = endPosition;

    } else if (setOpen.compare(passage.substr(position, setOpen.length())) == 0) {

        string endTag = ")";
        int endPosition = passage.find(endTag, position) + endTag.length();

        //length of the total string (starting tag + text + close tag)
        int stringLength = endPosition - position;

        result = passage.substr(position, stringLength);

        //finding next starting postitio
        position = endPosition;
    } else if (gotoOpen.compare(passage.substr(position, gotoOpen.length())) == 0) {
        string endTag = ")";
        int endPosition = passage.find(endTag, position) + endTag.length();

        //length of the total string (starting tag + text + close tag)
        int stringLength = endPosition - position;

        result = passage.substr(position, stringLength);

        //finding next starting postitio
        position = endPosition;
    } else if (elseOpen.compare(passage.substr(position, elseOpen.length())) == 0) {
        string endTag = ")";
        int endPosition = passage.find(endTag, position) + endTag.length();

        //length of the total string (starting tag + text + close tag)
        int stringLength = endPosition - position;

        result = passage.substr(position, stringLength);

        //finding next starting postitio
        position = endPosition;
    } else if (ifelseOpen.compare(passage.substr(position, ifelseOpen.length())) == 0) {
        string endTag = ")";
        int endPosition = passage.find(endTag, position) + endTag.length();

        //length of the total string (starting tag + text + close tag)
        int stringLength = endPosition - position;

        result = passage.substr(position, stringLength);

        //finding next starting postitio
        position = endPosition;
    } else if (elseOpen.compare(passage.substr(position, elseOpen.length())) == 0) {
        string endTag = ")";
        int endPosition = passage.find(endTag, position) + endTag.length();

        //length of the total string (starting tag + text + close tag)
        int stringLength = endPosition - position;

        result = passage.substr(position, stringLength);

        //finding next starting postitio
        position = endPosition;
    } else if (ifOpen.compare(passage.substr(position, ifOpen.length())) == 0) {
        string endTag = ")";
        int endPosition = passage.find(endTag, position) + endTag.length();

        //length of the total string (starting tag + text + close tag)
        int stringLength = endPosition - position;

        result = passage.substr(position, stringLength);

        //finding next starting postitio
        position = endPosition;
    } else if (blockOpen.compare(passage.substr(position, blockOpen.length())) == 0) {

        string endTag = "]";

        //keep track of the open and clsing []
        // look ahead and count open brackets until we find an equal number of closing brackets
        // looking the first open bracket and the last open bracket
        int nextOpenBraketPosition = passage.find(blockOpen, position + 1) + blockOpen.length();
        int nextClosingBraketPosition = passage.find(endTag, position) + endTag.length();

        while (nextOpenBraketPosition != 0 && nextOpenBraketPosition < nextClosingBraketPosition) {
            nextOpenBraketPosition = passage.find(blockOpen, nextOpenBraketPosition) + blockOpen.length();
            nextClosingBraketPosition = passage.find(endTag, nextClosingBraketPosition) + endTag.length();
        }

        int endPosition = nextClosingBraketPosition;

        //length of the total string (starting tag + text + close tag)
        int stringLength = endPosition - position;

        result = passage.substr(position, stringLength);

        //finding next starting postitio
        position = endPosition;
    } else {
        vector<string> myarray;
        int lowestTagPosition = passage.length();

        myarray.push_back(linkOpen);
        myarray.push_back(setOpen);
        myarray.push_back(gotoOpen);
        myarray.push_back(elseOpen);
        myarray.push_back(ifelseOpen);
        myarray.push_back(ifOpen);
        myarray.push_back(blockOpen);

        for (int i = 0; i < myarray.size(); i++) {
            //find the string for the starting postion
            //first intance of item in passage
            int firstPositiom = passage.find(myarray[i], position);

            //the lowest one is the starting position
            if ((firstPositiom != -1) && (firstPositiom < lowestTagPosition)) {
                lowestTagPosition = firstPositiom;
            }
        }

        result = passage.substr(position, lowestTagPosition - position);
        position = lowestTagPosition;
    }

    PartToken token = PartToken(result);

    // the current type becomes the 'previous' type
    previousType = token.getType();

    //returns the link
    return token;

}


/////PART TOKEN START//////
PartToken::PartToken(string part) {

    this->part = part;
}

string PartToken::getText() {

    return part;
}

TokenType PartToken::getType() {

    string blockSurroundingLink = "[[[";
    string link = "[[";
    string set = "(set:";
    string goTo = "(go-to:";
    string else_o = "(else:";
    string ifelse = "(if-else:";
    string if_o = "(if:";
    string block = "[";

    if (blockSurroundingLink.compare(part.substr(0, blockSurroundingLink.length())) == 0) {
        return BLOCK;
    } else if (link.compare(part.substr(0, link.length())) == 0) {
        return LINK;
    } else if (set.compare(part.substr(0, set.length())) == 0) {
        return SET;
    } else if (goTo.compare(part.substr(0, goTo.length())) == 0) {
        return GOTO;
    } else if (else_o.compare(part.substr(0, else_o.length())) == 0) {
        return ELSE;
    } else if (ifelse.compare(part.substr(0, ifelse.length())) == 0) {
        return ELSEIF;
    } else if (if_o.compare(part.substr(0, if_o.length())) == 0) {
        return IF;
    } else if (block.compare(part.substr(0, block.length())) == 0) {
        return BLOCK;
    } else {
        return TEXT;
    }
}
