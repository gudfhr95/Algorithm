#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  int max = -987654321;
  int min = 987654321;
  int temp;
  vector<int> arr = {};

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &temp);
    arr.push_back(temp);
  }

  for (int i = 0; i < arr.size(); ++i) {
    if (arr.at(i) > max) {
      max = arr.at(i);
    }
    if (arr.at(i) < min) {
      min = arr.at(i);
    }
  }

  printf("%d %d\n", min, max);
}