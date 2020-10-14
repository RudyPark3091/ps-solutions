#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n;
char cmd[11];
int num;
queue<int> q;

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", &cmd);
    char c[2] = {cmd[0], cmd[1]};

    if (c == "pu") {
      scanf("%d", &num);
      q.push(num);
    }
    else if (c == "po") {
      if (q.empty()) { printf("-1"); }
      else {
        int t = q.front();
        q.pop();
        printf("%d\n", t);
      }
    }
    else if (c == "si") { printf("%d\n", (int) q.size()); }
    else if (c == "em") {
      if (q.empty()) { printf("1"); }
      else { printf("0"); }
    }
    else if (c == "fr") {
      if (q.empty()) { printf("-1"); }
      else { printf("%d\n", q.front()); }
    }
    else if (c == "ba") {
      if (q.empty()) { printf("-1"); }
      else { printf("%d\n", q.back()); }
    }
    else {
      printf("%s\n", &c);
    }
  }

  return 0;
}
