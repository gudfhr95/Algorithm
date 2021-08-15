#include <iostream>
#include <vector>

using namespace std;

int convertToSeconds(int hour, int min, int sec) {
  return (hour * 3600) + (min * 60) + sec;
}

vector<int> convertToHour(int s) {
  vector<int> result;

  int hour = s / 3600;
  int min = (s % 3600) / 60;
  int sec = s % 60;

  result.push_back(hour);
  result.push_back(min);
  result.push_back(sec);

  return result;
}

int main() {
  int h1, h2, m1, m2, s1, s2;

  for (int i = 0; i < 3; i++) {
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

    int time = convertToSeconds(h2, m2, s2) - convertToSeconds(h1, m1, s1);
    vector<int> hour = convertToHour(time);

    for (const auto &elem : hour) {
      cout << elem << ' ';
    }

    cout << '\n';
  }
}
