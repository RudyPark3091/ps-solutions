#include <iostream>
#include <queue>
using namespace std;

int n;
string cmd;
int num;
queue<int> q;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> cmd;

    if (cmd.substr(0, 2) == "pu") {
      cin >> num;
      q.push(num);
    }
    else if (cmd.substr(0, 2) == "po") {
      if (q.empty()) { cout << -1 << '\n'; }
      else {
        int t = q.front();
        q.pop();
        cout << t << '\n';
      }
    }
    else if (cmd.substr(0, 2) == "si") { cout << q.size() << '\n'; }
    else if (cmd.substr(0, 2) == "em") {
      if (q.empty()) { cout << 1 << '\n'; }
      else { cout << 0 << '\n'; }
    }
    else if (cmd.substr(0, 2) == "fr") {
      if (q.empty()) { cout << -1 << '\n'; }
      else { cout << q.front() << '\n'; }
    }
    else if (cmd.substr(0, 2) == "ba") {
      if (q.empty()) { cout << -1 << '\n'; }
      else { cout << q.back() << '\n'; }
    }
    else {
      cout << i << ' ' << cmd << '\n';
    }
  }

  return 0;
}
