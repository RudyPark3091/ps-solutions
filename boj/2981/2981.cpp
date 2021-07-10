#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];
int res[100];

int main() {
    int n, gcd;
    int cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    sort(arr, arr + n);

    gcd = arr[1] - arr[0];
    for (int i = 2; i < n; i++) { gcd = __gcd(arr[i] - arr[i-1], gcd); }

    for (int i = 1; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            res[cnt++] = i;
            if (i != gcd / i) { res[cnt++] = gcd / i; }
        }
    }
    sort(res, res + cnt);
    for (int i = 1; i < cnt; i++) { cout << res[i] << ' '; }

    return 0;
}