#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main()
{
    int count = 5;

    Stack<char> tester(2);

    for (int i = 0; i < count; ++i)
        tester.push('a'+i);

    for (int i = 0; i < count; ++i)
        cout << tester.pop() << endl;

    return 0;
}
