#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  
  for (int tc = 0; tc < t; tc++) {
    deque<int> q;
    string p;
    bool error = false;
    bool reverse = false;
    int n = 0;

    cin >> p;
    cin >> n;

    string a, buf;
    cin >> a;
    istringstream str(a);

    while (getline(str, buf, ',')) {
      if (buf == "[]") { q.clear(); }
      else if (buf.front() == '[') {
        if (buf.back() == ']') {
          buf.erase(buf.size() - 1);
        }
        q.push_back(stoi(buf.substr(1)));
      }
      else if (buf.back() == ']') { q.push_back(stoi(buf.substr(0, buf.size() -1 ))); }
      else { q.push_back(stoi(buf)); }
    }

    for (int i = 0; i < p.length(); i++) {
      if (p.at(i) == 'R') {
        reverse = !reverse;
      } else if (p.at(i) == 'D') {
        if (q.empty()) {
          cout << "error\n";
          error = true;
          break;
        } else {
          if (reverse) {
            q.pop_back();
          } else {
            q.pop_front();
          }
        }
      }
    }

    if (!error) {
      cout << '[';
      if (!reverse) {
        if (q.size() != 0) {
          for (int i = 0; i < q.size() - 1; i++) { cout << q.at(i) << ','; }
          cout << q.at(q.size() - 1) << "]\n";
        } else {
          cout << "]\n";
        }
      } else {
        if (q.size() != 0) {
          for (int i = q.size() - 1; i > 0; i--) {
            cout << q.at(i) << ',';
          }
          cout << q.at(0) << "]\n";
        } else {
          cout << "]\n";
        }
      }
    }
  }

  return 0;
}

