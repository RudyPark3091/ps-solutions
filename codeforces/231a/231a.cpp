#include <iostream>
using namespace std;

int main() {
  int n;
  int probs = 0;
  int arr[3];

  cin >> n;
  for (int i = 0; i < n; i++) {
    int yes = 0;
    for (int j = 0; j < 3; j++) {
      cin >> arr[j];
      if (arr[j] == 1)
        yes++;
    }
    if (yes >= 2)
      probs++;
  }

  cout << probs << '\n';

  return 0;
}
