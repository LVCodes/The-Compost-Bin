
This project will be implementing an interpreter for a programming language called GritVM. GritVM will read in a file of code written in this specific GVM language, run the instructions, and be able to return the results held in the GritVM object’s memory. The GritVM has two variables that contain its memory: a NodeList that contains the instructions and a Vector that contains the data. There will also be a single variable called the accumulator. The accumulator stores the results of various operations as an intermediate. The accumulator is an implicit operand for all mathematical calculations. Below is an example of some private members for the GritVM.
std::vector<long> dataMem;
std::list<Instruction> instructMem;
std::list<Instruction>::iterator currentInstruct;
STATUS machineStatus;
long accumulator;

This project permits the use of C++ Standard Template Library version of the Vector and List. We must use these STL data types for GritVM. The GritVM can only operate on long data types, so that is the only data type needed for the machine data. We will be responsible for programming in the functionality of the following instructions in the implementation of GritVM. Notice that the memory management functions match the Vector ADT nearly identically. DM represents data memory:

CLEAR   Accumulator Functions   CLEAR   Set the accumulator to 0
AT   DM Management functions   AT X   Sets the accumulator to the value at DM[X], A = DM[X]
SET   Set DM management functions   SET X   Sets the DM[X] to the value in the accumulator DM[X] = A
INSERT   DM management functions   INSERT X   Insert in DM at location X the value in the accumulator
ERASE   DM management functions   ERASE X   Erases location X in the DM
ADDCONST   Accumulator maths with a constant   ADDCONST C   Adds C to the accumulator value A = A + C
SUBCONST   Accumulator maths with a constant   SUBCONST C   Subtracts C from the accumulator A = A - C
MULCONST   Accumulator maths with a constant   MULCONST C   Multiplies C to the accumulator value A = A * C
DIVCONST   Accumulator maths with a constant   DIVCONST C   Divides C from the accumulator value A = A / C
ADDMEM   Accumulator maths with a memory location   ADDMEM X   Adds DM[X] to accumulator value A = A + DM[X]
SUBMEM   Accumulator maths with a memory location   SUBMEM X   Subtracts DM[X] from accumulator A = A - DM[X]
MULMEM   Accumulator maths with a memory location   MULMEM X   Multiplies DM[X] to accumulator A = A * DM[X]
DIVMEM   Accumulator maths with a memory location   DIVMEM X   Divides DM[X] from the accumulator value A = A / DM[X]
JUMPREL   Instruction jump functions   JUMPRELY   Goes forward/back Y instructions from the current instruction (can be negative)
JUMPZERO   Instruction jump function   JUMPNZEROY   Goes forward/back Y instructions from from the current instruction (can be negative) if accumulator is not zero. Otherwise just move forward 1 from current instruction
NOOP   Misc functions   NOOP   Perform no operation. Counts as an instruction but does nothing
HALT   Misc functions   HALT   Stop the GritVM and switch status to HALTED
OUTPUT   Misc functions   OUTPUT   Output accumullator to std::cout
CHECKMEM   Misc functions   CHECKMEM Z   Checks to make sure DM is of at least size Z. If not, switch status to ERRORED

The primary flow of the machine should be as follows:
• When created, the GritVM sets the accumulator to 0, and it's status to WAITING
• A program is loaded into the GritVM object by filename (by the load method)
• If the machine status is anything other than WAITING, return the current status
• If the GritVM cannot read a file, the method throws an exception
• Each line of the file is read in and parsed into its proper instruction and argument
• If the instruction is not recognized, change the machine status to ERRORED and return
• If the line is blank or starts with a #, then skip that line (it is a comment or white space)
• Add that instruction to the instructMem list• If the instructMem size is 0 set the status to WAITING,
• Otherwise, set it to READY
• Copy the vector passed into the load method to the dataMem vector
• Return the current status
• If a GritVM object is READY receiving a call to the run method, then the instructions can be evaluated
• Otherwise, return the current status
• Evaluate the current instruction
• After evaluation, move the current instruction forward the proper amount
• 1 for regular instructions
• Y for jumps if a jump is triggered (where Y != 0, if Y is 0, set status to ERRORED and return run method)
• Set status to HALTED if the last instruction was HALT or the last instruction has been reached
• Return the current status

Things in GritVMBase hpp/cpp
Also provided in the base class files are the enums that define the various stats and instructions for the GritVM. There is an instruction struct for holding an instruction, and it’s argument. There are also five helper methods given. All of these methods are provided in the namespace GVMHelper.

There are two opportunities for extra credit on this project.
The first is to write a program in the GVM language that calculates the minimum number of moves for a Towers of Hanoi (TOH) solution. The memory layout of the program after halting should be [N, Result] where N was the number of disks passed into the program and Result is the minimum number of steps. Try to reverse engineering other GVM programs to get the TOH program working.
The second opportunity is to write your own custom implementation of the list and vector used for the GritVM. It will have to be able to convert to and from the Standard Template Versions of the list and vector when taking in or outputting instruction/data memory.

The project files should be:
• GritVM.cpp (Your written GritVM class)
• GritVM.hpp (Your written GritVM class)
• GritVMBase.cpp (The provided base class, enums, structs, and helper functions)
• GritVMBase.hpp (The provided base class, enums, structs, and helper functions)
• PP3Test.cpp (Test file)
• catch.hpp (Catch2 Header)
• altseq.gvm (A Alternating Sequence Program for GritVM)
• sumn.gvm (A Summation Program for GritVM)
• surfarea.gvm (A Surface Area Program for GritVM)
• test.gvm (A Test Program for GritVM)
