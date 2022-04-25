/*
 *Lauren Vogel    COP3331     Summer 2020
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
