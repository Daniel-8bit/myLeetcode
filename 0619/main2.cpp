#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> res{1, 2, 3, 4, 5, 6};
    for ( vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}