/*
 * Auto generated with firestarter-cli by @rudy3091
 * https://github.com/rudy3091/firestarter-cli
 */

#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<string, int, int, int> data;

int n;
data arr[100'001];

void setup() {
  string name;
  int g, y, s;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> name >> g >> y >> s;
    arr[i] = { name, g, y, s };
  }
}

bool cmp(data a, data b) {
  int ga = get<1>(a);
  int ya = get<2>(a);
  int sa = get<3>(a);

  int gb = get<1>(b);
  int yb = get<2>(b);
  int sb = get<3>(b);

  if (ga == gb) {
    if (ya == yb) {
      if (sa == sb) {
        string na = get<0>(a);
        string nb = get<0>(b);

        for (int i = 0; i < min(na.length(), nb.length()); i++) {
          if (na[i] != nb[i]) return na[i] < nb[i];
        }
        return false;
      } else return sa > sb;
    } else return ya < yb;
  } else return ga > gb;
}

void solve() {
  stable_sort(arr, arr + n, cmp);
  for (int i = 0; i < n; i++) {
    cout << get<0>(arr[i]) << '\n';
  }
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	setup();
	solve();

	return 0;
}
