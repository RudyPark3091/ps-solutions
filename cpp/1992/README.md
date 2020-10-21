## Problem
[acmicpc.net/problem/1992]   
   
## Example
input ->   
8   
11110000   
11110000   
00011100   
00011100   
11110000   
11110000   
11110011   
11110011   
   
output ->   
((110(0101))(0011)1(0001))   
   
## Logic
이 문제는 [2630번 문제]의 응용 버전이다.   
2630번과 다른 점은 번호가 주어질 때 띄어쓰기가 없고, 숫자의 개수를 세는 것이 아닌 숫자를 문자열의 형태로 나타내 출력해야하는 것이다.   
주어진 숫자를 괄호 안에 압축해서 나타내는데, 규칙이 있다.   
만약 영역 내의 숫자가 압축이 된다면 괄호 없이, 압축되지 않으면 한번 더 괄호 안에 넣어서 나타낸다.   
이를 재귀함수의 형태로 나타낸 소스 코드는 다음과 같다.   
   
## Source Code
``` cpp
#include <iostream>
using namespace std;

int n;
int arr[64][64];
string res;

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j++) { arr[i][j] = s.at(j) - 48; }
  }
}

void solve(int size, int dx, int dy) {
  if (size == 1) {
    res += arr[dx][dy] + 48;
    return;
  }

  int nx = dx + size / 2;
  int ny = dy + size / 2;
  
  bool flag = true;
  for (int i = dx; i < dx + size; i++) {
    for (int j = dy; j < dy + size; j++) {
      if (arr[i][j] != arr[dx][dy]) { flag = false; }
    }
  }
  if (flag) {
    res += arr[dx][dy] + 48;
    return;
  }

  res += '(';
  solve(size / 2, dx, dy);
  solve(size / 2, dx, ny);
  solve(size / 2, nx, dy);
  solve(size / 2, nx, ny);
  res += ')';
}

int main() {
  input();
  solve(n, 0, 0, 0);

  cout << res << '\n';
  return 0;
}
```
   
## Review
문제의 조건에도 주어져 있듯 주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이다.   
(0)으로 출력하게 하여 제출해 한번에 AC를 받지 못했다.   
문제의 조건을 잘 확인하자.   

[acmicpc.net/problem/1992]: [acmicpc.net/problem/1992] 
[2630번 문제]: [acmicpc.net/problem/2630]
