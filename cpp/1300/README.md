## Problem
[acmicpc.net/problem/1300]   
   
## Example
input ->   
3   
7   
   
output ->   
6   
   
## Logic
이 문제는 2차원배열을 초기화하고 일차원배열로 만들어 정렬한 뒤에 탐색하는 방법으로는 굳이 따져보지 않아도 시간초과가 날 것이라 생각된다.   
이분 탐색을 사용해서 문제를 해결하는 방법을 생각할 수 있다.   
k번째 수는 2차원배열에 중복된 수가 존재하기 때문에 k보다 클 수 없다.   
따라서 start는 1, end는 k로 잡는다.   
이때 mid값보다 작은 i * j값의 개수가 mid와 동일한 값이 정답이라 할 수 있다.   
2차원배열의 첫번째 행에서 k보다 작거나 같은 수의 개수는 총 k개라고 할 수 있다.   
두번째 행에서 k보다 작거나 같은 수는 2 * 1, 2 * 2, 2 * 3 ... 이므로 첫번째 행의 개수에 2를 나눈 `k / 2`개라고 할 수 있다.   
마찬가지로 세번째 행에서 k보다 작거나 같은 수는 `k / 3`이고, n번째 행에서의 개수는 `k / n`개가 된다.   
따라서 이분 탐색에서 검사할 mid값보다 작은 값들을 n행까지 더해준 값을 기준으로 start값 또는 end값을 조정한다.   
이때, n의 값이 `mid / (행 index)`보다 작은 경우에는 행의 모든 숫자가 mid값보다 작으므로 n을 더해주는 것에 주의한다.   
여타 이분 탐색 문제와 같이 mid값에 대해 `mid / (행 index)`보다 작은 숫자들의 개수의 합이 문제에서 주어진 k보다 작다면 start값에 `mid + 1`을, 크다면 end값에 `mid - 1`을 대입한 후 반복한다.   
   
## Source Code
``` cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int res;

void solve(int a, int b) {
  int mid = 0;
  int cnt = 0;
  int res = 0;
  
  while (a <= b) {
    mid = (a + b) / 2;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += min(mid / i, n);
    }

    if (cnt < k) {
      a = mid + 1;
    } else {
      b = mid - 1;
      res = mid;
    }
  }

  cout << res << '\n';
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  solve(1, k);

  return 0;
}
```
   
[acmicpc.net/problem/1300]: https://acmicpc.net/problem/1300
