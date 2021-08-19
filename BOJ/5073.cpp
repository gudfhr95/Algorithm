#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b, c;

  while (true) {
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0) break;

    vector<int> triangle = {a, b, c};
    sort(triangle.begin(), triangle.end(), greater<>());

    if (triangle[0] >= triangle[1] + triangle[2])
      cout << "Invalid\n";
    else if (triangle[0] == triangle[1] && triangle[1] == triangle[2])
      cout << "Equilateral\n";
    else if (triangle[0] == triangle[1] || triangle[1] == triangle[2] ||
             triangle[0] == triangle[2])
      cout << "Isosceles\n";
    else
      cout << "Scalene\n";
  }
}