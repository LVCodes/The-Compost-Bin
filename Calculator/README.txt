We were asked to implement a linked list based arithmetic calculator.
The calculator will be able to perform addition, subtraction, multiplication, and division. The
calculator will keep a running total of the operations completed, the number of operations
completed, and what those operations were. The calculator will also have an "undo" function for
removing the last operation. The calculator will also be able to output a string of the operations
completed so far with fixed precision.
The calculator has to be implemented using a singly, doubly, or circularly linked list. The C++ Standard Library Lists and/or other sources to implement the linked list are not allowed. The calculator has to implement at least four methods:

-double total() const
This method returns the current total of the CalcList. Total should run as a constant time
operation. The program should not have to iterate through the entire list each time the total is
needed.
-void newOperation(const FUNCTIONS func, const double operand)
Adds an operation to the CalcList and creates a new total. The operation alters total by using
the function with the operand. Example: newOperation(ADDITION, 10) => adds 10 to the
total.
-void removeLastOperation()
Removes the last operation from the calc list and restores the previous total.
-std::string toString(unsigned short precision) const
Returns a string of the list of operations completed so far formatted with a fixed point precision.
The form of the string should strictly be: "(step): (totalAtStep)(Function)(operand) = (newTotal)
\n".
Example: toString(2) => "3: 30.00*1.00=30.00\n2: 10.00+20.00=30.00\n1:
0.00+10.00=10.00\n"
This project includes an abstract class for the CalcList from which to inherit. The abstract class
(CalcListInterface) contains the pure virtual version of all the required methods. This file also
includes a typedef of an enum used for the four arithmetic functions called FUNCTIONS. This project is to be tested using the Catch2 (https://github.com/catchorg/Catch2) test framework.
This framework only requires that a program include the header to run the test file. The test file
that will be used is included. This project also contains the Catch2 header.
Required files:
PP1Test.cpp, catch.hpp, CalcListInterface.hpp, CalcList.hpp (Your Code), CalcList.cpp (Your
Code)
