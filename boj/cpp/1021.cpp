#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m, cnt = 0;
vector<int> v;
deque<int> q;

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) { q.push_back(i); }
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
}

int index(int num) {
  for (int i = 0; i < q.size(); i++) {
    if (num == q[i]) { return i; }
  }
  return -1;
}

void solve() {
  for (int i = 0; i < m; i++) {
    int idx = index(v.front());
    int right = idx;
    int left = q.size() - idx;

    while (q.front() != v.front()) {
      if (right <= left) {
        int t = q.front();
        q.pop_front();
        q.push_back(t);
        cnt++;
      } else if (left < right) {
        int t = q.back();
        q.pop_back();
        q.push_front(t);
        cnt++;
      }
    }

    q.pop_front();
    v.erase(v.begin());
  }
  cout << cnt << '\n';
}

int main() {
  input();
  solve();
  return 0;
}
