#include <iostream>
using namespace std;

int n, m;
int res;
long long max_height = 0;
int arr[1000000];

void input() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (max_height < arr[i])
      max_height = arr[i];
  }
}

void solve(long long a, long long b) {
  long long mid = 0;

  while (a <= b) {
    mid = (a + b) / 2;
    long long len = 0;

    for (int i = 0; i < n; i++) {
      if (arr[i] > mid)
        len += arr[i] - mid;
    }

    if (len < m) {
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
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  input();
  solve(1, max_height);

  return 0;
}
