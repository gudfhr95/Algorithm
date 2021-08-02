#include <iostream>

using namespace std;

int main() {
  string jaehwan, doctor;

  cin >> jaehwan >> doctor;

  if (jaehwan.length() >= doctor.length())
    cout << "go";
  else
    cout << "no";
}