#include <iostream>
using namespace std;

string a, b;
int _a[10002], _b[10002], s[10002], c = 0;

int main() {
  cin >> a >> b;
  for (int i = 0; i < a.length(); i++) {
    _a[a.length() -1 - i] = (int)a[i] - 48;
  }
  for (int i = 0; i < b.length(); i++) {
    _b[b.length() -1 - i] = (int)b[i] - 48;
  }

  for (int i = 0; i < max(a.length(), b.length()); i++) {
    s[i] = _a[i] + _b[i] + c;
    c = 0;
    if (s[i] >= 10) {
      c = 1;
      s[i] -= 10;
    }
  }

  if (c == 1) cout << 1;
  for (int i = max(a.length(), b.length())-1; i >= 0; i--) {
    cout << s[i];
  }
  cout << endl;

  return 0;
}
