/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int abc[3];
  string s;

  cin >> abc[0] >> abc[1] >> abc[2];
  cin >> s;

  sort(abc, abc + 3);

  for (int i = 0; i < 3; i++) {
    switch (s[i]) {
      case 'A':
        cout << abc[0] << ' ';
        break;
      case 'B':
        cout << abc[1] << ' ';
        break;
      case 'C':
        cout << abc[2] << ' ';
        break;
    }
  }

	return 0;
}
