#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

void input() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    q.push(i+1);
  }
}

void solve() {
  cout << '<';
  while (!q.empty()) {
    for (int i = 0; i < k-1; i++) {
      int t = q.front();
      q.pop();
      q.push(t);
    }
    if (q.size() == 1) {
      cout << q.front() << ">\n";
      q.pop();
    } else {
      cout << q.front() << ", ";
      q.pop();
    }
  }
}

int main() {
  input();
  solve();
  return 0;
}
