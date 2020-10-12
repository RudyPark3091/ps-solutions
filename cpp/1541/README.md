## Problem
acmicpc.net/problem/1541   
   
## Example
input ->   
55-50+40   
   
output ->   
-35
   
## Logic Flow
이 문제는 간단히 식을 읽어가다 '-'가 나왔을 때 다음 '-'가 나오기 전까지 괄호를 쳐주면 되는 문제다.   
문제의 수는 모두 양수이고 연산은 +와 -만 존재하므로, 결과를 최소로 만들기 위해서는 이전 결과에 최대한 큰 값을 빼주면 된다.   
문자열 형태로 입력받은 식을 순회한다.   
'-'을 만나면 다음 연산자가 나오기 전까지의 문자열을 정수자료형으로 고친다.   
다음 연산자가 '-'라면 결과값에 현재까지의 정수값을 빼주고, '+'라면 정수값에 더한다.   
만약 '-'을 만난 뒤 식의 끝에 도달하면 결과값에 현재까지의 정수값에 더한값을 빼고 종료한다.   
결과값을 출력한다.   
이때 다른 언어에서 제공하는 split()과 같은 효과를 위해 istringstream클래스를 사용했다.   
   
## Source Code
``` cpp
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string sik;
int res = 0;
bool first = false;
vector<string> arr;

void input() {
  cin >> sik;

  if (sik.at(0) == '-') {
    first = true;
  }

  istringstream st(sik);
  string buf;
  while(getline(st, buf, '-')) {
    arr.push_back(buf);
  }
}

void solve() {
  string buf;

  for (int i = 0; i < arr.size(); i++) {
    istringstream st(arr[i]);
    int sum = 0;

    while (getline(st, buf, '+')) {
      sum += stoi(buf);
    }
    
    if (!first && i == 0) {
      res += sum;
    } else {
      res -= sum;
    }
  }

  cout << res << '\n';
}
  
int main() {
  input();
  solve();

  return 0;
}
```
   
## Review
이 문제에서 istringstream을 처음 사용해보았다.   
조만간 정리해야겠다.   