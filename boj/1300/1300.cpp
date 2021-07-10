#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int res;

void solve(int a, int b) {
  int mid = 0;
  int cnt = 0;
  int res = 0;
  
  while (a <= b) {
    mid = (a + b) / 2;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += min(mid / i, n);
    }

    if (cnt < k) {
      a = mid + 1;
    } else {
      b = mid - 1;
      res = mid;
    }
  }

  cout << res << '\n';
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  solve(1, k);

  return 0;
}
