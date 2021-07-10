#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res = 0;
vector<int> arr;

void input() {
  cin >> n;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    arr.push_back(a);
  }
}

void solve() {
  sort(arr.begin(), arr.end());
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    res += sum;
  }
  cout << res << '\n';
}

int main() {
  input();
  solve();
  return 0;
}
