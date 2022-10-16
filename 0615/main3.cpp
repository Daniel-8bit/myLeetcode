#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    const int* b = &a;
    const int& c = *b;
    a = 1;
    cout << *b << endl;
    return 0;
}