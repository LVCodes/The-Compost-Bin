
 Project Rubric:

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
