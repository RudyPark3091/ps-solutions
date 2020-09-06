#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int k, n;
    int sum = 0;
    vector<int> s;

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> n;
        if (n != 0) s.push_back(n);
        else s.pop_back();
    }

    for (auto i: s) sum += i;
    cout << sum << endl;
    return 0;
}