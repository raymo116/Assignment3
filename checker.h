#ifndef MRJR_CHECKER

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class checker
{
public:
    static bool cycle(ifstream& currentStream);
private:
    static bool forward(char currentChar);
    static bool reverse(char currentChar);
    static char currentChar(char currentChar);
    static char compliment(char currentChar);
    static void message(char charE, char charR, int lineNum);

};

#endif
