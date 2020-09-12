#include <iostream>
using namespace std;

long long fibarr[41] = {0, 1, };

long long fib(int num) {
    if (num == 0) {
        return 0;
    }
    else if (num == 1) {
        return 1;
    }
    else if (fibarr[num] == 0) {
        fibarr[num] = fib(num-1) + fib(num-2);
    }
    return fibarr[num];
}

int main() {
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n == 0) {
            cout << "1 0" << '\n';
            continue;
        }
        cout << fib(n-1) << ' ' << fib(n) << '\n';
    }

    return 0;
}