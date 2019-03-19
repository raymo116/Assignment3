#include <iostream>
#include <fstream>
#include <string>
#include "checker.h"

using namespace std;


int main()
{
    ifstream currentFile;
    string filepath = "test.txt";
    string input;
    bool running = true;
    bool errorFree = true;

    while(running)
    {
        currentFile.open(filepath, ifstream::in);

        while(!currentFile.good())
        {
            cout << "That was not a valid input. Please try again." << endl;
            currentFile.close();
            getline(cin, filepath);
            currentFile.open(filepath, ifstream::in);
        }

        errorFree=checker::cycle(currentFile);
        while(errorFree)
        {
            cout << "Would you like to continue?\n1) Yes\n2) No" << endl;
            getline(cin, input);
            if(input == "1")
            {
                cout << "Please enter a filepath:" << endl;
                getline(cin, filepath);
                break;
            }
            else if(input == "2")
            {
                running = false;
                break;
            }
            else
            {
                cout << "That was not a valid input. Please try again" << endl;
            }
        }
        if(!errorFree) break;
    }

    return 0;
}
