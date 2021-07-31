#include <iostream>

using namespace std;

int main() {
  string A, Ar = "";
  string B, Br = "";

  cin >> A >> B;

  for (int i = A.length() - 1; i >= 0; --i) {
    Ar += A.at(i);
    Br += B.at(i);
  }

  if (stoi(Ar) > stoi(Br)) {
    cout << Ar;
  } else {
    cout << Br;
  }
}