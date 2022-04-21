#include "passagetokenizer.h"
#include<iostream>
using namespace std;
const string openLink = "[[";
const string closeLink = "]]";
const string openGoto = "(go-to:";
const string openSet = "(set:";
const string openIf = "(if:";
const string openElseIf = "(else-if:";
const string openElse = "(else:";
const string openBlock = "[";
const string openText = "";
const string closeCommand = ")";
const string closeBlock = "]";

//Takes the vector 'starts' and returns the type cast of the
//index with the minimum value
//Basically so you know if you have a link, goto, block, etc.
tokentype_t minType(const vector<size_t>& starts){

    size_t temp = 0; //but only when in reference to the index u weak
    for(size_t i = 0; i < starts.size(); i++)
        if(starts[i] < starts[temp])
            temp = i;

    return static_cast<tokentype_t>(temp);
}

//uhhhhhhhhhh maYBe useful later
/*void parseBlock(const string& passage, vector<PartToken>& parts, size_t startIndex, size_t endIndex){

    vector<size_t> starts(8, string::npos); //8 size_t elements of vector set to big ass NPOS good fuckin luck laddy
    size_t startOffset;
    string currString;
//do i look like i know what html is


         while(endIndex != string::npos && startIndex != string::npos)
         {
                starts.at(static_cast<size_t>(LINK)) = passage.find(openLink, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(SET)) = passage.find(openSet, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(GOTO)) = passage.find(openGoto, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(IF)) = passage.find(openIf, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(ELSEIF)) = passage.find(openElseIf, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(ELSE)) = passage.find(openElse, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(BLOCK)) = passage.find(openBlock, (startIndex == 0 ? 0 : startIndex+1));
                tokentype_t currType = minType(starts);
                startIndex = starts.at(static_cast<size_t>(currType));

                //prevent final iteration from being inserted into passages
                //as she is not-good.com
                if (startIndex == string::npos)
                    break;
                if(currType == LINK)
                    endIndex = passage.find(closeLink, startIndex+1);
                else if(currType == BLOCK)
                    endIndex = passage.find(closeBlock, startIndex+1);
                else
                    endIndex = passage.find(closeCommand, startIndex+1);

                switch (currType){
                    case LINK:
                        startOffset = openLink.size();
                        break;
                    case GOTO:
                        startOffset = openGoto.size();
                        break;
                    case SET:
                        startOffset = openSet.size();
                        break;
                    case IF:
                        startOffset = openIf.size();
                        break;
                    case ELSEIF:
                        startOffset = openElseIf.size();
                        break;
                    case ELSE:
                        startOffset = openElse.size();
                        break;
                    case BLOCK:
                        startOffset = openBlock.size();
                        break;
                    case TEXT:
                        startOffset = openText.size();
                        break;

                }

                currString = passage.substr(startIndex+startOffset, endIndex-(startIndex+startOffset));
                //Ensure that first iteration does not create infinite loop
                if (startIndex == 0 || currType == LINK)
                    startIndex++;
                if(currType == LINK)
                    endIndex++;
                //emplace_back is like push_back but cooler and more fun
                //but not generally ideal, we got a special case up in this bitch
                parts.emplace_back(PartToken(currString, currType));

                if(currType == BLOCK)
                    parseBlock(currString, parts, startIndex, endIndex);
         }

}  */ //Damn we gonna deal wit this bitch laTER
//numOB is number of open brackets encountered in str string
size_t getMatchingBracket(const string& str, size_t currIndex = 0, size_t numOB = 0){

    if(currIndex >= str.size()) return 0;

    if(str.at(currIndex) == ']')
    {
        if(numOB == 0) return currIndex;

        else return getMatchingBracket(str, currIndex+1, numOB-1);
    }

    else if(str.at(currIndex) == '[') return getMatchingBracket(str, currIndex+1, numOB+1);

    else return getMatchingBracket(str, currIndex+1, numOB);
}


PassageTokenizer::PassageTokenizer(const string& passage){

    this->passage = passage;//referring to the MEMBER in the class sPECIFICALLY
                            //You aint makin a new one named passage NOno
    partIndex = 0;
    vector<size_t> starts(8, string::npos); //8 size_t elements of vector set to big ass NPOS good luck laddy
    size_t startIndex = 0;
    size_t endIndex = 0;
    size_t startOffset;
    string currString;
//do i look like i know what html is


         while(endIndex != string::npos && startIndex != string::npos)
         {
                starts.at(static_cast<size_t>(LINK)) = passage.find(openLink, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(SET)) = passage.find(openSet, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(GOTO)) = passage.find(openGoto, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(IF)) = passage.find(openIf, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(ELSEIF)) = passage.find(openElseIf, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(ELSE)) = passage.find(openElse, (startIndex == 0 ? 0 : startIndex+1));
                starts.at(static_cast<size_t>(BLOCK)) = passage.find(openBlock, (startIndex == 0 ? 0 : startIndex+1));
                //damn twunk abouta put a tunreryveternary in another ternary
                starts.at(static_cast<size_t>(TEXT)) = (endIndex+1 == passage.size() ? string::npos :
                                                        endIndex == 0 ? endIndex : endIndex+1);
                tokentype_t currType = minType(starts);
                startIndex = starts.at(static_cast<size_t>(currType));

                //prevent final iteration from being inserted into passages
                //as she is not-good.com
                if (startIndex == string::npos)
                    break;
                if(currType == LINK)
                    endIndex = passage.find(closeLink, startIndex+1);
                else if(currType == BLOCK)
                    endIndex = getMatchingBracket(passage.substr(startIndex+1)) + startIndex+1;
                else if(currType == TEXT)
                {
                    //kinda out there
                    //definitly doing her own damn thing
                    //setting text to the max value in order to guarantea that
                    //minType returns ANYTHING other than TEXT
                    starts.at(static_cast<size_t>(TEXT)) = string::npos;
                    tokentype_t nextType = minType(starts);
                    endIndex = starts.at(static_cast<size_t>(nextType));
                }

                else
                    endIndex = passage.find(closeCommand, startIndex+1);
                switch (currType){
                    case LINK:
                        startOffset = openLink.size();
                        break;
                    case GOTO:
                        startOffset = openGoto.size();
                        break;
                    case SET:
                        startOffset = openSet.size();
                        break;
                    case IF:
                        startOffset = openIf.size();
                        break;
                    case ELSEIF:
                        startOffset = openElseIf.size();
                        break;
                    case ELSE:
                        startOffset = openElse.size();
                        break;
                    case BLOCK:
                        startOffset = openBlock.size();
                        break;
                    case TEXT:
                        startOffset = openText.size();
                        break;

                }

                currString = passage.substr(startIndex+startOffset, endIndex-(startIndex+startOffset));
                //Ensure that first iteration does not create infinite loop
                if (startIndex == 0 || currType == LINK)
                    startIndex++;
                if(currType == LINK)
                    endIndex++;
                if(currType == BLOCK)
                    startIndex = endIndex;
                //emplace_back is like push_back but cooler and more fun
                //but not generally ideal, we got a special case up in this bitch
                parts.emplace_back(PartToken(currString, currType));
         }

}




PartToken PassageTokenizer::nextPart(){

    PartToken temp = parts.at(partIndex);
    partIndex++;
    return temp;
}


bool PassageTokenizer::hasNextPart(){

    if(partIndex >= parts.size())
        return false;
    return true;
    //oR u coulda done
    //return partIndex < parts.size();
}
