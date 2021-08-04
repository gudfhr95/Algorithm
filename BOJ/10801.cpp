#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, a_score = 0, b_score = 0;
  vector<int> a, b;

  for (int i = 0; i < 10; i++) {
    cin >> n;
    a.push_back(n);
  }

  for (int i = 0; i < 10; i++) {
    cin >> n;
    b.push_back(n);
  }

  for (int i = 0; i < 10; i++) {
    if (a[i] > b[i])
      a_score++;
    else if (a[i] < b[i])
      b_score++;
  }

  if (a_score > b_score)
    cout << 'A';
  else if (a_score < b_score)
    cout << 'B';
  else
    cout << 'D';
}