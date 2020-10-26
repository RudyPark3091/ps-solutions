#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int n;
ll b;
vector<vector<ll>> mat;
vector<vector<ll>> res;

void input() {
  cin >> n >> b;
  for (int i = 0; i < n; i++) {
    vector<ll> v;
    for (int j = 0; j < n; j++) {
      ll t;
      cin >> t;
      v.push_back(t);
    }
    mat.push_back(v);
  }
}

vector<vector<ll>> mat_mul(vector<vector<ll>> a, vector<vector<ll>> b) {
  vector<vector<ll>> ret = a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll tmp = 0;
      for (int k = 0; k < n; k++) {
        tmp += (a[i][k] % 1000) * (b[k][j] % 1000) % 1000;
      }
      ret[i][j] = tmp % 1000;
    }
  }
  return ret;
}

vector<vector<ll>> solve(vector<vector<ll>> a, long long b) {
  vector<vector<ll>> ret;
  for (int i = 0; i < n; i++) {
    vector<ll> t;
    for (int j = 0; j < n; j++) {
      if (i == j)
        t.push_back(1);
      else
        t.push_back(0);
    }
    ret.push_back(t);
  }

  while (b > 0) {
    if (b % 2 == 1) {
      ret = mat_mul(ret, a);
    }
    a = mat_mul(a, a);
    b /= 2;
  }
  return ret;
}

int main() {
  input();
  res = solve(mat, b);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << res[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
