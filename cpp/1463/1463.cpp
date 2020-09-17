#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000001] = {0, 0, 1, 1,};

int main() {
    cin >> n;

    for (int i = 4; i <= n; i++) {
        if (i % 2 != 0 && i % 3 != 0) { arr[i] = arr[i-1] + 1; }
        else if (i % 3 != 0) { arr[i] = min(arr[i/2], arr[i-1]) + 1; }
        else if (i % 2 != 0) { arr[i] = min(arr[i/3], arr[i-1]) + 1; }
        else { arr[i] = min(arr[i-1], min(arr[i/2], arr[i/3])) + 1; }
    }

    cout << arr[n] << '\n';
    return 0;
}