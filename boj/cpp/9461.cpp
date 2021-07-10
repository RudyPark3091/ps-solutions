#include <iostream>
using namespace std;

int t, n;
long long arr[102] = {1, 1, 1, };

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n == 0 || n == 1 || n == 2) { cout << arr[n] << '\n'; continue; }
        for (int j = 3; j <= n; j++) { arr[j] = arr[j-3] + arr[j-2]; }
        cout << arr[n-1] << '\n'; ;
    }

    return 0;
}