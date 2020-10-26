## Problem
[acmicpc.net/problem/10830]   
   
## Example
input ->    
2 5   
1 2   
3 4   
   
output ->   
69 558   
337 406   
   
## Logic
이 문제는 행렬의 거듭제곱을 빠르게 계산하는 문제이다.   
이 문제 역시 [11401번 문제]와 같이 분할 정복 알고리즘을 이용해 N회의 연산을 logN회로 줄이는 것이 가능하다.   
다만, 이 경우에는 수를 제곱하는 것이 아니라 행렬간의 곱셈이 행해야되는 연산이라는 점이 다르다.   
11401번 문제의 논리를 사용하는데 조금 다른 점이 있다.   
행렬간 곱셈연산을 위해 새로운 함수를 정의하고, 입출력을 위해 `vector<vector>`형태의 행렬을 정의한다.      
또한 제곱 연산을 하는 과정에서 수의 제곱은 1에 다른 수를 곱해줬지만, 행렬의 연산에는 단위행렬 `[[1 , 0] , [0 , 1]]`에 다른 행렬을 곱해준다.   
위 논리를 정리한 코드는 아래와 같다.   
   
다만 주의할 점으로는, 두 번째 입력받는 수인 b는 최대 100,000,000,000으로 int형의 범위를 벗어난다.   
따라서 b는 long long 타입으로 선언해야 하고,   
A^B의 각 원소를 1000으로 나눈 값을 출력해야 하므로 입력이
```
2 1
1000 1000
1000 1000
```
와 같이 들어오면 출력은
```
0 0
0 0
```
이 되어야 함 등이 있다.   
   
## Source Code
``` cpp
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
```

[acmicpc.net/problem/10830]: https://www.acmicpc.net/problem/10830
[11401번 문제]: https://www.acmicpc.net/problem/10830
