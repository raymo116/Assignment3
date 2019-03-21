#ifndef MRJR_CHECKER

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class checker
{
public:
    // Takes in a filestream, checks for errors, and returns a bool for the error/lack thereof
    static bool cycle(ifstream& currentStream);
private:
    // Takes in a character and tells if it's a forward delimiter, returns a bool
    static bool forward(char currentChar);
    // Takes in a character and tells if it's a reverse delimiter, returns a bool
    static bool reverse(char currentChar);
    // Takes in a character and returns the compliment of that character if it's a delimiter
    static char compliment(char currentChar);
    // Takes in an expected character, a received character, and the line number and prints the error message
    static void message(char charE, char charR, int lineNum);
    // Takes in a character and an array of characters and checks to see if the character is in the array
    static bool boolCheck(char currentChar, char *cA);
};

#endif
