#ifndef __PARTTOKEN_H_
#define __PARTTOKEN_H_
#include <string>
using namespace std;


enum tokentype_t{LINK, GOTO, SET, IF, ELSEIF, ELSE, BLOCK, TEXT};
//EA SPORTS
//ITS IN THE GAME
class PartToken{

public:
    PartToken();
    PartToken(const string&, const tokentype_t);
    string getText();
    tokentype_t getType();

private:
    string text;
    tokentype_t type;
};

#endif // __PARTTOKEN_H_
