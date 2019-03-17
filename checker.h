#ifndef MRJR_CHECKER

#include <iostream>
#include <string>
using namespace std;

class checker
{
public:
    static void cycle(string testString);
private:
    static bool forward(char currentChar);
    static bool reverse(char currentChar);
    static char currentChar(char currentChar);
    static char compliment(char currentChar);
};

#endif
