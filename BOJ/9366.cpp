#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T, n;
  vector<int> triangle;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    triangle.clear();

    for (int j = 0; j < 3; j++) {
      cin >> n;
      triangle.push_back(n);
    }

    sort(triangle.begin(), triangle.end());

    printf("Case #%d: ", i);
    if (triangle[0] + triangle[1] <= triangle[2]) {
      printf("invalid!\n");
    } else {
      if (triangle[0] == triangle[1] && triangle[1] == triangle[2])
        printf("equilateral\n");
      else if (triangle[0] == triangle[1] || triangle[0] == triangle[2] ||
               triangle[1] == triangle[2])
        printf("isosceles\n");
      else
        printf("scalene\n");
    }
  }
}