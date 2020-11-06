#include <iostream>
#include <algorithm>
using namespace std;

int n, c;
long long arr[200000];

void input() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

void solve(long long a, long long b) {
  long long mid = 0;
  long long res = 0;

  while (a <= b) {
    mid = (a + b) / 2;
    int cnt = 1;
    int prev = 0;

    for (int i = 1; i < n; i++) {
      if (arr[i] - arr[prev] >= mid) {
        prev = i;
        cnt++;
      }
    }

    if (cnt < c) {
      b = mid - 1;
    } else {
      a = mid + 1;
      res = max(res, mid);
    }
  }

  cout << res << '\n';
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  input();
  sort(arr, arr + n);
  solve(1, arr[n-1] - arr[0]);

  return 0;
}
