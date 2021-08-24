#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, n;
  vector<int> students;

  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> n;

    auto it = students.begin() + (students.size() - n);

    students.insert(it, i);
  }

  for (const auto &elem : students) {
    cout << elem << ' ';
  }
}
