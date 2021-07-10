#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, num;
vector<int> lcs;

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> num;
    if (lcs.empty() || num > lcs.back()) {
      lcs.push_back(num);
    } else {
      *lower_bound(lcs.begin(), lcs.end(), num) = num;
    }
  }

  cout << lcs.size() << '\n';
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  solve();

  return 0;
}
