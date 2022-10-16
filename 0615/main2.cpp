#include <iostream>

#define SQR(x) (x * x)

int main()
{
    int a = 3;
    int b = 2;
    std::cout << SQR(a + b) << endl;
    return 0;
}