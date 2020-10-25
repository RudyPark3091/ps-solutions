#include <iostream>
using namespace std;

string number(string color) {
  if (color == "black")
    return "0";
  else if (color == "brown")
    return "1";
  else if (color == "red")
    return "2";
  else if (color == "orange")
    return "3";
  else if (color == "yellow")
    return "4";
  else if (color == "green")
    return "5";
  else if (color == "blue")
    return "6";
  else if (color == "violet")
    return "7";
  else if (color == "grey")
    return "8";
  else if (color == "white")
    return "9";
}

int main() {
  string res = "";
  string one, two, three;

  cin >> one >> two >> three;
  res += number(one) + number(two);

  for (int i = 0; i < stoi(number(three)); i++)
    res += '0';

  if (res[0] == '0' && res[1] == '0') {
    cout << 0 << '\n';
  } else if (res[0] == '0' && res[1] != '0'){
    cout << res.substr(1) << '\n';
  } else {
    cout << res << '\n';
  }
  return 0;
}
