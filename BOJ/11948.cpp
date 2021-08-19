#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int A, B, C, D, E, F, result = 0;

  cin >> A >> B >> C >> D >> E >> F;

  vector<int> science = {A, B, C, D};
  vector<int> social = {E, F};

  sort(science.begin(), science.end(), greater<>());
  sort(social.begin(), social.end(), greater<>());

  for (int i = 0; i < 3; i++) {
    result += science[i];
  }
  result += social[0];

  cout << result;
}