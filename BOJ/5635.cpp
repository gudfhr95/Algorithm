#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Birth {
  int date;
  int month;
  int year;
};

bool cmp(pair<string, Birth> &a, pair<string, Birth> &b) {
  if (a.second.year > b.second.year)
    return true;
  else if (a.second.year == b.second.year) {
    if (a.second.month > b.second.month)
      return true;
    else if (a.second.month == b.second.month) {
      if (a.second.date > b.second.date)
        return true;
      else
        return false;
    } else
      return false;
  } else
    return false;
}

int main() {
  int n;
  vector<pair<string, Birth>> students;

  string name;
  Birth b;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> name >> b.date >> b.month >> b.year;
    students.push_back({name, b});
  }

  sort(students.begin(), students.end(), cmp);

  cout << students.front().first << endl << students.back().first;

  return 0;
}