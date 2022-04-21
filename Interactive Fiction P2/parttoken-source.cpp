#include "parttoken.h"
#include <iostream>
#include <string>
using namespace std;

string PartToken::getText(){

    return text;
}

tokentype_t PartToken::getType(){

    return type;
}

PartToken::PartToken(){
    //is should be stoopid empty
    //put some stuff ofr text or somethin
    text = "";
}

PartToken::PartToken(const string& text, const tokentype_t type){
    //also should be sTOOPOID simple
    //dont over think her
    this->text = text;
    this->type = type;
}

