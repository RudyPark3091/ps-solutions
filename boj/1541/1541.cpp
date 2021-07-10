#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string sik;
int res = 0;
bool first = false;
vector<string> arr;

void input() {
  cin >> sik;

  if (sik.at(0) == '-') {
    first = true;
  }

  istringstream st(sik);
  string buf;
  while(getline(st, buf, '-')) {
    arr.push_back(buf);
  }
}

void solve() {
  string buf;

  for (int i = 0; i < arr.size(); i++) {
    istringstream st(arr[i]);
    int sum = 0;

    while (getline(st, buf, '+')) {
      sum += stoi(buf);
    }
    
    if (!first && i == 0) {
      res += sum;
    } else {
      res -= sum;
    }
  }

  cout << res << '\n';
}
  
int main() {
  input();
  solve();

  return 0;
}
