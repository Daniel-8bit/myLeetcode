#include <iostream>

using namespace std;
bool func1()
{
    cout << "func1" << endl;
    return false;
}

bool func2()
{
    cout << "func2" << endl;
    return true;
}
int main()
{
    func1()&&func2();
    cout << "=====================" << endl;
    func2()&&func1();
    cout << "=====================" << endl;
    func1()||func2();
    return 0;
}