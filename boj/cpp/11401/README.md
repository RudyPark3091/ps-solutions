## Problem
[acmicpc.net/problem/11401]
   
## Example
input ->   
5 2   
   
output ->   
10   
   
## Logic
이 문제는 N과 K의 범위가 커서 일반적인 방법으로 이항 계수를 구현하면 시간 초과가 나는 문제이다.   
해법의 핵심은 [페르마의 소정리]라고 하는 기법이다.   
페르마의 소정리는 간략히 `a^(p-1) mod p = 1`으로 나타낼 수 있다.   
이때 문제에서 주어진 나누는 수 1,000,000,007은 소수이므로 페르마의 소정리를 이용할 수 있다.   
우리가 구하고자 하는 것은 `(n! / (k! * (n-k)!)) % 1,000,000,007` 이다.   
이때 modulus 연산을 분자에는 분배해줄 수 있지만 분모는 나눗셈이기 때문에 분배가 불가능하다.   
이때 페르마의 소정리에 의해 `(k! * (n-k)!)^1,000,000,006 % 1,000,000,007 = 1`이므로,   
```
(n! / k! * (n-k)!) % 1,000,000,007 = (n! * (k! * (n-k)!)^1,000,000,005) % 1,000,000,007
```
위와 같이 나타낼 수 있다.   
따라서 분모를 곱셈의 형태로 바꿔줬으므로 계산하여 출력하면 된다.   
이때, 거듭제곱을 그대로 계산하면 시간제한에 걸리기 때문에 [분할 정복을 사용한 거듭제곱]을 사용하여야 한다.   
또한, 이 문제에서 1,000,000,005라는 아주 큰 수로 거듭제곱 연산을 하기 때문에 재귀함수를 이용한 분할 정복보다 반복분을 이용한 방법으로 거듭제곱 연산을 구현한다.   
   
## Source Code
```cpp
#include <iostream>
#define DIV 1000000007
#define MUL 1000000005
#define MAX 4000001
using namespace std;

int n, k;
long long arr[MAX] = { 1, 1, };

long long pow(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y % 2 != 0) {
      res *= x;
      res %= DIV;
    }
    x *= x;
    x %= DIV;
    y /= 2;
  }
  return res;
}

long long solve() {
  for (int i = 2; i <= n; i++) {
    arr[i] = (arr[i-1] * i) % DIV;
  }
  long long nFac = arr[n];
  long long kFac = arr[k];
  long long nmkFac = arr[n - k];
  long long rval = pow((kFac * nmkFac) % DIV, MUL);

  return ((nFac % DIV) * (rval % DIV)) % DIV;
}

int main() {
  cin >> n >> k;
  cout << solve() << '\n';
  return 0;
}
```

[acmicpc.net/problem/11401]: https://www.acmicpc.net/problem/11401
[페르마의 소정리]: https://ko.wikipedia.org/wiki/%ED%8E%98%EB%A5%B4%EB%A7%88%EC%9D%98_%EC%86%8C%EC%A0%95%EB%A6%AC
[분할 정복을 사용한 거듭제곱]: https://www.acmicpc.net/problem/1629
