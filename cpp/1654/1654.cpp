#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long res;
long long arr[10000];

void input() {
  cin >> k >> n;
  for (int i = 0; i < k; i++) {
    cin >> arr[i];
  }
}

void solve(long long a, long long b) {
  long long mid = 0;

  while (a <= b) {
    mid = (a + b) / 2;
    int cnt = 0;

    for (int i = 0; i < k; i++) {
      cnt += arr[i] / mid;
    }

    if (cnt < n) {
      b = mid - 1;
    } else {
      if (res < mid)
        res = mid;
      a = mid + 1;
    }
  }

  cout << res << '\n';
}

int main() {
  input();
  solve(1, *max_element(arr, arr + k));

  return 0;
}
