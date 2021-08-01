#include <iostream>

using namespace std;

int DATE[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string DAY[7] = {"Thursday", "Friday",  "Saturday", "Sunday",
                 "Monday",   "Tuesday", "Wednesday"};

int main() {
  int month, day;
  int diff = 0;

  cin >> day >> month;

  for (int i = 0; i < month - 1; i++) {
    diff += DATE[i];
  }
  diff += day - 1;

  cout << DAY[diff % 7];
}