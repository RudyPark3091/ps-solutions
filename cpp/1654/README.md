## Problem
[acmicpc.net/problem/1654]   
   
## Example
input ->   
4 11   
802   
743   
457   
539   
   
output ->   
200   
   
## Logic
입력 받은 전선의 길이들 중 최댓값을 end값으로 잡는다.   
start값은 1로 잡는다.   
만약 start 와 end의 middle값으로 전선을 잘랐을때 나오는 전선의 갯수가 입력받은 n보다 크다면 자르는 전선의 길이를 더 늘린다.   
잘랐을때 나오는 전선의 갯수가 n보다 작다면 전선의 길이를 줄인다.   
이 과정을 반복하며 나오는 전선의 길이의 최댓값을 계산한다.   
   
## Source Code
``` cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long res;
long long arr[10000];

void input() {
  cin >> k >> n;
  for (int i = 0; i < k; i++) {
    cin >> arr[i];
  }
}

void solve(long long a, long long b) {
  long long mid = 0;

  while (a <= b) {
    mid = (a + b) / 2;
    bool flag = false;
    int cnt = 0;

    for (int i = 0; i < k; i++) {
      cnt += arr[i] / mid;
    }

    if (cnt < n) {
      b = mid - 1;
    } else {
      if (res < mid)
        res = mid;
      a = mid + 1;
    }
  }

  cout << res << '\n';
}

int main() {
  input();
  solve(1, *max_element(arr, arr + k));

  return 0;
}
```

[acmicpc.net/problem/1654]: https://acmicpc.net/problem/1654
