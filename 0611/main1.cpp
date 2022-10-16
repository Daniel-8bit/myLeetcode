#include <iostream>
#include <set>

using namespace std;

int main()
{
    multiset<int> mset{1,10,9, 8, 43, 14, 16, 16};
    for (auto& item : mset) {
        cout << item << endl;
    }

    cout << "###############" << endl;

    multiset<int>::iterator low = mset.lower_bound(45);

    if (low == mset.end()) {
        cout << "out bound!" << endl;
    }

    cout << *low << endl;
    return 0;

}