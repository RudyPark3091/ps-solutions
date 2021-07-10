#include <iostream>
using namespace std;

int cnt = 0;
char arr[8][8];

int main() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> arr[i][j];
      if ((i + j) % 2 == 0 && arr[i][j] == 'F') { cnt++; }
    }
  }

  cout << cnt << '\n';
  return 0;
}
