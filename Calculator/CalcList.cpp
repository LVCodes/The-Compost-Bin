/* Lauren Vogel     COP4530     Fall 2020
 * This will implement a linked list based arithmetic
 * calculator. The calculator will be able to perform
 * addition, subtraction, multiplication, and division.
 * The calculator will keep a running total of the
 * operations completed, the number of operations
 * completed, and what those operations were. The
 * calculator will also have an "undo" function for
 * removing the last operation. The calculator will
 * also be able to output a string of the operations
 * completed so far with fixed precision.
 * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "CalcList.hpp"
#include <iomanip>
#include <sstream>
#include <iostream>

CalcList :: CalcList(){
    head = nullptr;
    currTotal = 0;
    length = 0;
}

void CalcList :: newOperation(const FUNCTIONS func, const double operand){

    if(func == DIVISION && operand == 0)
        throw runtime_error("Divison by 0");

    length++;
    node* newOp = new node;
    newOp->op = func;
    newOp->numLHS = currTotal;
    newOp->numRHS = operand;
    newOp->next = head;
    head = newOp;


    switch (func){
        case ADDITION:
            currTotal += operand; //operand is "numRHS"
            break;
        case SUBTRACTION:
            currTotal -= operand;
            break;
        case MULTIPLICATION:
            currTotal *= operand;
            break;
        case DIVISION:
            currTotal /= operand;
            break;
        default:
            break;
    }

}


void CalcList :: removeLastOperation(){

    if(head == nullptr)
        throw runtime_error("Can't remove from empty list.");

    length--;
    node* temp = head;
    head = head->next;

    switch (temp->op){
        case ADDITION:
            currTotal -= temp->numRHS;
            break;
        case SUBTRACTION:
            currTotal += temp->numRHS;
            break;
        case MULTIPLICATION:
            if(temp->numRHS == 0)
                currTotal = temp->numLHS;
            else
                currTotal /= temp->numRHS;
            break;
        case DIVISION:
            currTotal *= temp->numRHS;
            break;
        default:
            break;
    }
    delete temp;

}


string CalcList :: toString(unsigned short precision) const{

    ostringstream output;
    node* ptr = head;
    output << setprecision(precision) << fixed;


    for(int i = length; i > 0; i--, ptr = ptr->next){
        output << i << ": " << ptr->numLHS
               << (ptr->op == ADDITION ? "+" : ptr->op == SUBTRACTION ? "-" :
                   ptr->op == MULTIPLICATION ? "*" : "/") << ptr->numRHS << "="
               << (ptr->op == ADDITION ? (ptr->numLHS + ptr->numRHS) : ptr->op == SUBTRACTION ?
                   (ptr->numLHS - ptr->numRHS) : ptr->op == MULTIPLICATION ? (ptr->numLHS * ptr->numRHS) :
                   (ptr->numLHS / ptr->numRHS)) << "\n";
    }
  return output.str();
}

//Lets not cause a memory leak today I guess
CalcList :: ~CalcList(){
    if(head != nullptr){
        node* prev = head;
        for(node* curr = head->next; curr != nullptr; prev = curr, curr = curr->next)
            delete prev;
        delete prev;
    }
}
