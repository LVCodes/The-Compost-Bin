/* Lauren Vogel    COP3331     Summer 2020
 *
 * Part 2 of this project has code to break down the passages that was
 * tokenized in Part 1 into their constituent components. Like Part 1,
 * this part is also individual.
 * The different parts of this project build on one another so code for
 * this part cannot be completed without a functioning StoryTokenizer.
 *
 *The goal for this part is to write a pair of classes to tokenize the
 *passages in interactive fiction stories. The “main” class for the part
 *PassageTokenizer, will take in the text of a passage in an interactive
 *fiction story (e.g., from the getText method of PassageToken), and will
 *break the input up into PartToken objects, each of which represent an
 *important section of the passage. The code should be able to recognize
 *a total of 8 different kinds of part tokens: links, commands, blocks,
 *and text, and there are 5 different commands to recognize: go-to, set,
 *if, else-if, and else. These tokens will be described in more detail.
 *
 *     Part Tokens:
 *In order to correctly interpret each passage in a story, it needs to
 *be able to separate out the different parts of that passage. The
 *PassageTokenizer class should have a string constructor that accepts a
 *string containing the body of the passage, and it should implement two
 *member function, nextPart and hasNextPart. Similar to StoryTokenizer,
 *nextPart should return a token (a PartToken) representing each part of
 *the passage in turn, while hasNextPart should indicate if the passage
 *has another part to return. Like PassageTokens, PartTokens should have
 *a getText member function, along with an appropriate constructor, but
 *they should also have a getType member function, that returns the token’s
 *type (LINK, GOTO, SET, IF, ELSEIF, ELSE, BLOCK, or TEXT). An invalid
 *PartToken (e.g., one returned by nextPart when hasNextPart is false)
 *should return an empty string as its text and TEXT as its type.
 *
 *     Links:
 *A link in the body of a passage will be surrounded by double brackets:
 *[[ and ]]. A PartToken containing a link should return a string containing
 *the brackets and whatever is between them as its text.
 *
 *     Commands:
 *Commands in Harlowe are denoted by an open parenthesis followed by a
 *single word and a colon. The IF interpreter should support 5 different
 *commands, (go-to:, (set:, (if:, (else-if:, and (else:. In all cases, the
 *text of the PartToken (returned by getText) should begin at the open
 *parenthesis and end at the corresponding close parenthesis. Not every
 *parenthesis in the story represents a command (authors sometimes use
 *parenthetical statements to clarify the story or indicate action). The
 *PassageTokenizer should not treat parentheses any differently than other
 *text unless they are part of one of the five commands should be recognized.
 *
 *     Blocks:
 *Blocks are the parts of a passage that follow if, else if, or else commands
 *and denote what should happen when the given condition is true. The text of
 *a block will start with the first open bracket [ after an if, else if, or
 *else command, and it ends with the matching close bracket ]. An input file
 *may have some white space between the if command and its corresponding block
 *the code should ignore this white space, as the block must be the next token
 *after an if, else if, or else command. Furthermore, every if, else if, or else
 *command must be followed by a block, and a block can only appear after an if,
 *else if, or else command. For example, if the first character of a passage was
 *[, this character could be part of a link or the text of the passage, but it
 *cannot start a block. One important feature of blocks is that they may contain
 *other features inside them, such as links, commands, text, or even other blocks.
 *As a result, it needs to be very careful when matching brackets so that it
 *connects the bracket that starts a block to the correct bracket that ends it,
 *not just the first end bracket that appears.For this part of the project, the
 *code does not need to process anything inside of a block. A block should be a
 *single PartToken, even if it contains links or commands inside.
 *
 *     Text:
 *Text is a part of a passage containing ordinary text to be displayed. Text
 *tokens should contain all of the characters in the passage text that do not
 *belong to a command, link, or block (including new lines and other white space).
 *If the text in a passage contains HTML features (e.g., <a> tags or symbols like
 *&quot;), the code should just treat these as ordinary text; it won't need to do
 *any HTML processing. Also, there should never be two text tokens in a row; it
 *should combine all characters of uninterrupted text into a single token.
 *
 *Compile with g++
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __PASSAGETOKENIZER_H_
#define __PASSAGETOKENIZER_H_
#include "parttoken.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PassageTokenizer{

public:
    PassageTokenizer(const string&);
    PartToken nextPart();
    bool hasNextPart();

private:
    string passage;
    size_t partIndex;
    vector<PartToken> parts;


};


#endif // __PASSAGETOKENIZER_H_
