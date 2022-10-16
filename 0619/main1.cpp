#include <iostream>

using namespace std;

int main()
{
    enum class Week {
        Fri = 5,
        Sat = 6
    };

    cout << Week::Fri << endl;
    // int* p = &Fri;
    // cout << *p << endl;
    return 0;
}