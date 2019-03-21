#include <iostream>
#include <string>
#include <fstream>

#include "checker.h"
#include "GenStack.h"

using namespace std;

// Takes in a character and tells if it's a forward delimiter, returns a bool
bool checker::forward(char currentChar){
    // Open delimiters
    char openD[] = {'(', '{', '['};
    return boolCheck(currentChar, openD);
}

// Takes in a character and tells if it's a reverse delimiter, returns a bool
bool checker::reverse(char currentChar){
    // Closed delimeters
    char closeD[] = {')', '}', ']'};
    return boolCheck(currentChar, closeD);
}

// Takes in a character and returns the compliment of that character if it's a delimiter
char checker::compliment(char currentChar){
    switch (currentChar){
        case '(':
            return ')';
        case ')':
            return '(';
        case '[':
            return ']';
        case ']':
            return '[';
        case '{':
            return '}';
        case '}':
            return '{';
    }
    return currentChar;
}

// Takes in a filestream, checks for errors, and returns a bool for the error/lack thereof
bool checker::cycle(ifstream& currentStream){
    int lineNumber = 1;
    // Where delimiters will be stored
    GenStack<char> mainStack;
    // Character being evaluated
    char currentInputChar;
    bool error = false;

    while(!error){
        currentInputChar = currentStream.get();
        if(currentInputChar == '\n') lineNumber++;

        // Adds to stack if opening
        if(forward(currentInputChar))
            mainStack.push(currentInputChar);
        // Checks if closing
        else if(reverse(currentInputChar)){
            // Checks to make sure there aren't more closing than opening
            if(mainStack.isEmpty()){
                message(EOF, currentInputChar, lineNumber);
                error = true;
            }
            // Removes from stack if correct closing
            else if(mainStack.peek() == compliment(currentInputChar))
                mainStack.pop();
            // If it's the wrong closing delimiter
            else{
                message(compliment(mainStack.peek()), currentInputChar, lineNumber);
                error = true;
            }
        }
        // Checks to make sure that there aren't too many opening delimiters
        else if((currentInputChar == EOF)&&(mainStack.top>(-1))){
            message(compliment(mainStack.peek()), currentInputChar, lineNumber);
            error = true;
        }
    }
    currentStream.close();
    if(!error){
        cout << "No errors" << endl;
        return true;
    }
    return false;
}

// Takes in an expected character, a received character, and the line number and prints the error message
void checker::message(char charE, char charR, int lineNum){
    string expected = "EOF";
    string received = "EOF";

    if(charE!=EOF) expected = charE;
    if(charR!=EOF) received = charR;

    cout << "Was expecting \"" << expected << "\", received \"" << received << "\" instead. Line " << lineNum << endl;
}

// Takes in a character and an array of characters and checks to see if the character is in the array
bool checker::boolCheck(char currentChar, char *cA){
    for(int i=0; i < 3; ++i)
        if(currentChar == cA[i])
            return true;
    return false;
}
