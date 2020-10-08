## Problem
두 문자열이 주어졌을 때, Longest Common Subsequence를 구하라
##### 입력: 한 줄에 문자열 하나씩, 문자열의 길이 <= 1000   
##### 출력: LCS의 길이   
   
## Example
input ->   
ACAYKP   
CAPCAK   
   
output ->   
4   
   
## Logic Flow
문자열 둘의 각각의 요소에 대해 고려해야 하므로 이중 For 문을 구성한다.   
그에 따라 LCS의 값을 저장할 2차원 배열 dp를 선언한다.   
1번 문자열의 요소에 대해 2번 문자열을 순회하며 같은 문자가 나오는지 검사한다.   
같은 문자가 나온다면, 2번 문자열에서 검사한 문자 이전까지의 문자열에 대한 LCS의 길이가 하나 증가한다는 뜻이다.   
위의 예시에서 문자열 1의 3번째문자에 대하여 문자열 2를 순회하는 경우 중 문자열 1은 `ACA`, 문자열 2는 `CA`일때를 보면,   
문자열 1에서 `AC`, 문자열 2에서 `C`까지에서 이미 정의된 LCS `C`에 `A`를 덧붙이는 모양새이다.   
따라서 검사한 문자가 같은 경우는 2차원배열 dp의 `[i-1][j-1]인덱스의 값에 1을 더한 값`을 저장한다.   
또한 다른 문자가 나온다면, 1번 문자열의 문자를 포함시켰을 때와 2번 문자열의 문자를 포함시켰을 때 중 더 큰 수를 저장한다.   
위의 예시에서 `ACA`와 `CAP`를 비교하는 경우를 보면 `A`와 `P`는 다른 문자이므로 이 경우에 해당한다.   
이는 `'AC'와 'CAP'의 LCS`, `'ACA'와 'CA'의 LCS`둘 중 더 긴 LSC의 길이를 택하여 배열에 저장한다는 의미이다.   
따라서 검사한 문자가 같은 경우는 2차원배열 dp의 `[i-1][j], [i][j-1]인덱스의 값 중 더 큰값`을 저장한다.   
두 문자열의 LCS 길이를 구하는 것이므로, 이를 반복해 2차원배열 dp의 값을 갱신한 뒤 가장 마지막 값 - `[문자열1길이][문자열2길이] 인덱스의 값` - 을 출력한다.   
   
## Source Code
``` cpp
#include <iostream>
#include <algorithm>
using namespace std;

string str1;
string str2;
int arr[1001][1001];

void input() {
  cin >> str1;
  cin >> str2;
}

void solve() {
  for (int i = 1; i <= str1.length(); i++) {
    for (int j = 1; j <= str2.length(); j++) {
      if (str1.at(i-1) == str2.at(j-1)) {
        arr[j][i] = arr[j-1][i-1] + 1;
      } else {
        arr[j][i] = max(arr[j-1][i], arr[j][i-1]);
      }
    }
  }

  cout << arr[str2.length()][str1.length()] << '\n';
}

int main() {
  input();
  solve();

  return 0;
}
```

