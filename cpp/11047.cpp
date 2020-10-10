#include <iostream>
using namespace std;

int n, k, res;
int arr[100];

void input() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

void solve() {
  int cnt = 0;
  while (k > 0) {
    if (k >= arr[n-1]) {
      cnt++;
      k -= arr[n-1];
    } else {
      n -= 1;
    }
  }
  cout << cnt << '\n';
}

int main() {
  input();
  solve();
  return 0;
}
