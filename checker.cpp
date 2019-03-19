#include <iostream>
#include <string>
#include <fstream>

#include "checker.h"
#include "stack.h"

using namespace std;

bool checker::forward(char currentChar)
{
    char openD[] = {'(', '{', '['};
    for(int i=0; i < 3; ++i)
        if(currentChar == openD[i])
            return true;
    return false;
}

bool checker::reverse(char currentChar)
{
    char closeD[] = {')', '}', ']'};
    for(int i=0; i < 3; ++i)
        if(currentChar == closeD[i])
            return true;
    return false;
}

char checker::compliment(char currentChar)
{
    switch (currentChar)
    {
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

bool checker::cycle(ifstream& currentStream)
{
    int lineNumber = 1;
    int current = -1; // Allows for preincrementing
    Stack<char> mainStack;
    char currentInputChar;
    char tempStackChar;
    bool error = false;

    while(currentStream.good() && !error)
    {
        currentInputChar = currentStream.get();

        if(currentInputChar == '\n') lineNumber++;

        // Adds to stack if opening
        if(forward(currentInputChar))
            mainStack.push(currentInputChar);
        // Checks if closing
        else if(reverse(currentInputChar))
        {
            // Checks to make sure there aren't too many closing delimiters
            if(mainStack.isEmpty())
            {
                message(EOF, currentInputChar, lineNumber);
                error=true;
            }
            // Removes from stack if correct closing
            else if(mainStack.peek() == compliment(currentInputChar))
                mainStack.pop();
            // If it's the wrong closing delimiter
            else
            {
                message(compliment(mainStack.peek()), currentInputChar, lineNumber); // wrong closing delimiter
                error=true;
            }
        }
        // Checks to make sure that there aren't too many opening delimiters
        else if((currentInputChar == EOF)&&(mainStack.top>(-1)))
        {
            message(compliment(mainStack.peek()), currentInputChar, lineNumber); // too many opening
            error=true;
        }
    }
    currentStream.close();
    if(!error)
    {
        cout << "No errors" << endl;
        return true;
    }
    return false;
}

void checker::message(char charE, char charR, int lineNum)
{
    string expected = "EOF";
    string received = "EOF";

    if(charE!=EOF) expected = charE;
    if(charR!=EOF) received = charR;

    cout << "Was expecting \"" << expected << "\", received \"" << received << "\" instead. Line " << lineNum << endl;
}
