#include <iostream>
#include <string>
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

void checker::cycle(string testString)
{
    int lineNumber = 1;
    int current = -1; // Allows for preincrementing
    Stack<char> mainStack;
    char currentInputChar;
    char tempStackChar;

    while(true)
    {
        if(++current >= testString.length())
            break;

        currentInputChar = testString[current];

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
                cout << "Error #1" << endl; // too many closing
                break;
            }
            // Checks to make sure that there aren't too many opening delimiters
            else if((current == testString.length()-1)&&(mainStack.top>0))
            {
                cout << "Error #3" << endl; // too many opening
                break;
            }
            // Removes from stack if correct closing
            if(mainStack.peek() == compliment(currentInputChar))
                mainStack.pop();
            // If it's the wrong closing delimiter
            else
            {
                cout << "Error #2" << endl; // wrong closing delimiter
                break;
            }
        }
    }
}
