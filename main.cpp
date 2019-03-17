#include <iostream>
#include <string>
#include "checker.h"

using namespace std;

int main()
{
    string TEST_STRING = "(((\n))";
    checker::cycle(TEST_STRING);

    return 0;
}
