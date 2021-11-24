#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct student {
  string name;
  int korean, english, math;
};

bool cmp(const student &a, const student &b) {
  if (a.korean != b.korean) {
    return a.korean > b.korean;
  }

  if (a.english != b.english) {
    return a.english < b.english;
  }

  if (a.math != b.math) {
    return a.math > b.math;
  }

  return a.name < b.name;
}

int main() {
  int N;

  cin >> N;

  vector<student> students(N);

  for (int i = 0; i < N; i++) {
    cin >> students[i].name >> students[i].korean >> students[i].english >>
        students[i].math;
  }

  sort(students.begin(), students.end(), cmp);

  for (const auto &student : students) {
    cout << student.name << '\n';
  }
}