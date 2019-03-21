// Matt Raymond
// raymo116@mail.chapman.edu
// 2270559
// CPSC 350

#include <iostream>
#include <fstream>
#include <string>

#include "checker.h"

using namespace std;

int main(int argc, char const *argv[])
{
    // Stream to open file from
    ifstream currentFile;
    // Takes filepath from the commandline
    string filepath = "";
    // Current user input
    string input;
    // Whether the main loop is running
    bool running = true;
    // Whether the program is error free
    bool errorFree = true;

    filepath = (argv[1]==NULL)?"":argv[1];

    while(running){
        currentFile.open(filepath, ifstream::in);

        // while the file doesn't exist
        while(!currentFile.good()){
            cout << "That was not a valid input. Please try again." << endl;
            currentFile.close();
            getline(cin, filepath);
            currentFile.open(filepath, ifstream::in);
        }

        // Runs the cycle and determines if there was an error
        errorFree = checker::cycle(currentFile);

        while(errorFree){
            cout << "Would you like to continue?\n1) Yes\n2) No" << endl;
            getline(cin, input);
            if(input == "1"){
                cout << "Please enter a filepath:" << endl;
                getline(cin, filepath);
                break;
            }
            else if(input == "2"){
                running = false;
                break;
            }
            else
                cout << "That was not a valid input. Please try again" << endl;
        }
        // If there's a mistake
        if(!errorFree) break;
    }

    return 0;
}
