#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> a, b;
  int a_score = 0, b_score = 0, n;
  char lastWinner = 'D';

  for (int i = 0; i < 10; i++) {
    cin >> n;
    a.push_back(n);
  }

  for (int i = 0; i < 10; i++) {
    cin >> n;
    b.push_back(n);
  }

  for(int i =0; i<10; i++){
    if(a[i] > b[i]){
      a_score += 3;
      lastWinner = 'A';
    }
    else if (b[i] > a[i]){
      b_score += 3;
      lastWinner = 'B';
    }
    else {
      a_score += 1;
      b_score += 1;
    }
  }

  cout << a_score << ' ' << b_score << '\n';

  if(a_score > b_score){
    cout << 'A';
  }
  else if (a_score < b_score){
    cout << 'B';
  }
  else {
    cout << lastWinner;
  }
}
