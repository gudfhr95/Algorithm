#include <iostream>

using namespace std;

int votes[2] = {
    0,
};

int main() {
  float N;
  int s;

  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> s;
    votes[s]++;
  }

  if (votes[0] > (N / 2)) {
    cout << "Junhee is not cute!";
  } else {
    cout << "Junhee is cute!";
  }

  return 0;
}