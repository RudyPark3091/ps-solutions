#include <iostream>
#include <deque>
using namespace std;

int n;
deque<int> dq;
string cmd;
int num;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> cmd;

    if (cmd.substr(0, 2) == "pu") {
      cin >> num;
      if (cmd.at(5) == 'b') { dq.push_back(num); }
      else { dq.push_front(num); }
    } else if (cmd.substr(0, 2) == "po") {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        if (cmd.at(4) == 'b') {
          cout << dq.back() << '\n';
          dq.pop_back();
        } else {
          cout << dq.front() << '\n';
          dq.pop_front();
        }
      }
    } else if (cmd.substr(0, 2) == "si") {
      cout << dq.size() << '\n';
    } else if (cmd.substr(0, 2) == "em") {
      dq.empty() ? cout << "1\n" : cout << "0\n";
    } else if (cmd.substr(0, 2) == "fr") {
      dq.empty() ? cout << "-1\n" : cout << dq.front() << '\n';
    } else if (cmd.substr(0, 2) == "ba") {
      dq.empty() ? cout << "-1\n" : cout << dq.back() << '\n';
    }
  }

  return 0;
}
