/* Over the course of the semester we were tasked with developing an
 * interpreter for interactive fiction in multiple parts. Interactive
 * fiction (IF) is a text-based medium where a reader is given passages
 * of text interspersed with choices. It resembles the “Choose Your Own
 * Adventure” books that were once popular.
 *
 * This first part of the project asks that we write code to parse out
 * the different passages in a work of interactive fiction.
 *
 * This first part of the project is individual, later parts will be
 * done with a partner. Using good coding style is very important as a
 * result because the different parts of this project build on one another.
 *
 *     Background Information:
 * Reading in and interpreting text (or parsing), is a common problem in
 * Computer Science. Generally, the first step in parsing input is to
 * tokenize the input. Tokenizing input involves breaking it down into
 * smaller chunks (tokens), which can then be analyzed and annotated.
 * Tokenization organizes the input clearly to make parsing or interpreting
 * the input easier. For exceptionally complex input, this tokenization process
 * can be multi-level, with one tokenizer breaking the initial input into coarse
 * tokens that are then fed into another tokenizer to be broken down into
 * smaller tokens.
 *
 *     Specifications:
 * The goal of part 1 is to write a pair of classes to tokenize the passages
 * in interactive fiction stories. The “main” class, StoryTokenizer, should take
 * the text of an interactive fiction story stored in an HTML file, and it is
 * expected to break the input up into PassageToken objects, each of which
 * should represent one passage in the IF story.
 *
 *     Passage Tokens:
 * As stated, interactive fiction works are divided into passages, which
 * are analogous to to a chapter in a novel. Passages are denoted in HTML
 * using the <tw-passagedata> tag. The code should expect each passage to start
 * with <tw-passagedata ...> and end with </tw-passagedata>, and the body of
 * the passage will be between these two tags. The opening tag
 * (<tw-passagedata ...) will specify some attributes of the passage. Out of the
 * attributes given in the file, we are only interested in the name attribute,
 * which is an important attribute for understanding how the passages in an IF
 * story are connected together.
 * Ex:
 * <tw-passagedata pid="1" name="start" tags="" location="100,100">
 *   The body of the passage will be here.
 * </tw-passagedata>
 *
 * The StoryTokenizer class should have two member functions: hasNextPassage and
 * nextPassage. The nextPassage function should return PassageToken objects
 * representing the passages in the story. The first time it’s called, it should
 * return a token with the first passage; the second time, a token for the second
 * passage, etc.
 * The hasNextPassage function, should return whether the story has another passage
 * and should the code call nextPassage again, or if all the passages have already
 * been returned. StoryTokenizer should also have a constructor that accepts a string
 * containing the story to tokenize (i.e., the contents of the HTML file).
 * The PassageToken class is simpler. It should have two member functions, getName
 * and getText, as well as an appropriate constructor. The getName member function
 * should return the name of the passage, that appears as an attribute in the starting
 * <tw-passagedata> tag. In the example passage above, getName should return “start”.
 * The getText member function should return the body of the passage (all of the text
 * between the starting tag <tw-passagedata ...> and the ending tag </tw-passagedata>).
 * In the example above, this function would return “The body of the passage will be
 * here.”, with newline characters before and after. An invalid PassageToken (e.g., the
 * return result of nextPassage when there are no more passages) should return an empty
 * string for its name and text. The arguments of the constructor and the data members
 * of PassageTokens are flexible, as a PassageToken will only be constructed by the
 * StoryTokenizer.
 *
 *     Error Handling:
 * Code will only be tested on valid input, so it does not need to be robust to reading
 * errors in its input.
 *
 *     Implementing Code:
 * A main function has been provided and will read in a story from input.txt and use
 * StoryTokenizer and PassageToken classes to break down that story into its constituent
 * passages. Tokenizer should appropriately ignore any text in the input file that is not
 * part of a passage.
 *
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
