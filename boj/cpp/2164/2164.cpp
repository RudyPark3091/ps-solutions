#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;

void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) { q.push(i); }
}

void solve() {
  for (int i = 0; i < n - 1; i++) {
    q.pop();
    int t = q.front();
    q.pop();
    q.push(t);
  }
  cout << q.front() << '\n';
}

int main() {
  input();
  solve();
  return 0;
}

