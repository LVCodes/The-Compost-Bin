#ifndef __CALCLIST_H_
#define __CALCLIST_H_
#include "CalcListInterface.hpp"
using namespace std;

struct node {
    node* next;
    FUNCTIONS op;
    double numLHS, numRHS;
};

class CalcList : public CalcListInterface {
public:
    CalcList();
    double total() const{
        return currTotal;
    }
    void newOperation(const FUNCTIONS func, const double operand);
    void removeLastOperation();
    string toString(unsigned short precision) const;
    ~CalcList();

private:
    node* head;
    double currTotal;
    size_t length;

};


#endif // __CALCLIST_H_
