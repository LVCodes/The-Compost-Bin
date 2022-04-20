/*Do I LOOK LIKE I know how HTML works AT ALL? *crying in newbie programmer* */

#include "storytokenizer.h"
#include <iostream>
#include <string>
#include <vector>

PassageToken::PassageToken(string name, string passage)
{
        //make sure this siLlY liTTLe compiler doesnt mix up name and passage
        //hold two different values in two different spots bIctH
        this->name = name;
        this->passage = passage;

}

string PassageToken::getName() const
{
        //does she need to know how to read HTML?
        //Do I need to read HTML
        //Do I LOOK like
        // I can read HTML
        //I probably dont have to touch the HTML but I feel like she
        //is hovering and it makin me nerbus
        return name;
} 

string PassageToken::getText() const
{
        //gotta kick this passage to story() and hasNextPassage() to make sure is bein stored
        return passage;//???? not quite sweetie try again
}


StoryTokenizer::StoryTokenizer(string story)
{
        index = 0;
        const string openChevron = "<tw-passagedata ";
        const string start = "name=";
        const string closeChevron = "</tw-passagedata>";
        size_t startIndex = 0;
        size_t endIndex = 0;
        //scan the string till story do be parsed
        while(endIndex != string::npos && startIndex != string::npos)
        {
                startIndex = story.find(openChevron, startIndex);
                //prevent final iteration from being inserted into passages
                //as she is not-good.com
                if (startIndex == string::npos)
                        break;
                startIndex = story.find(start, startIndex);
                //find start quote
                startIndex = story.find("\"", startIndex);
                //find end quote
                endIndex = story.find("\"", startIndex+1);
                name = story.substr(startIndex+1, endIndex-(startIndex+1));
                startIndex = story.find(">", startIndex);
                endIndex = story.find(closeChevron, startIndex);
                passage = story.substr(startIndex+1, endIndex-startIndex-1);
                //emplace_back is like push_back but cooler and more fun
                //but not generally ideal, we got a special case up in this bitch
                passages.emplace_back(PassageToken(name, passage));
        }

}
PassageToken StoryTokenizer::nextPassage()
{
        PassageToken current = passages.at(index);
        index++;
        return current; //Excuse the fuck out of me what in the flying fuCK is happening
}

bool StoryTokenizer::hasNextPassage() const
{
        //could also be
        //if (passages.size() > index) return true;
        //else return false;
        return passages.size() > index;
}
