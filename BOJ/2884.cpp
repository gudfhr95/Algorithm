#include <iostream>

using namespace std;

int main() {
  int hour, minute;

  cin >> hour >> minute;

  if (minute - 45 < 0) {
    if (hour - 1 < 0) {
      cout << 23 << " " << 60 - (45 - minute);
    } else {
      cout << hour - 1 << " " << 60 - (45 - minute);
    }
  } else {
    cout << hour << " " << minute - 45;
  }

  return 0;
}