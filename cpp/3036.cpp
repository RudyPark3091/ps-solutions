#include <iostream>
#include <algorithm>
using namespace std;

int n, gcd;
int arr[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    for (int i = 1; i < n; i++) {
        gcd = __gcd(arr[0], arr[i]);
        cout << arr[0]/gcd << '/' << arr[i]/gcd << '\n';
    }

    return 0;
}