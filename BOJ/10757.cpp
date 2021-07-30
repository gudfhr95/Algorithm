#include <iostream>

using namespace std;

void add_diff(string A, string B) {
  int max_size = A.size();
  int min_size = B.size();

  int result1[max_size - min_size + 1];
  int result2[min_size];
  int a, b, temp;
  int flag = 0;

  for (int i = (min_size - 1); i >= 0; --i) {
    a = A.at(max_size - min_size + i) - '0';
    b = B.at(i) - '0';
    temp = a + b + flag;
    if (temp >= 10) {
      flag = 1;
      result2[i] = temp - 10;
    } else {
      flag = 0;
      result2[i] = temp;
    }
  }

  for (int i = (max_size - min_size - 1); i >= 0; --i) {
    a = A.at(i) - '0';
    temp = a + flag;
    if (temp >= 10) {
      flag = 1;
      result1[i] = temp - 10;
    } else {
      flag = 0;
      result1[i] = temp;
    }
  }

  if (flag == 1) {
    cout << 1;
  }

  for (int i = 0; i < max_size - min_size; ++i) {
    cout << result1[i];
  }
  for (int i = 0; i < min_size; ++i) {
    cout << result2[i];
  }
}

void add_same(string A, string B) {
  int size = A.size();

  int result[size + 1];
  int a, b, temp;
  int flag = 0;

  for (int i = (size - 1); i >= 0; --i) {
    a = A.at(i) - '0';
    b = B.at(i) - '0';
    temp = a + b + flag;
    if (temp >= 10) {
      flag = 1;
      result[i] = temp - 10;
    } else {
      flag = 0;
      result[i] = temp;
    }
  }

  if (flag == 1) {
    cout << 1;
  }

  for (int i = 0; i < size; ++i) {
    cout << result[i];
  }
}

int main() {
  string A, B;
  cin >> A >> B;

  if (A.size() == B.size()) {
    add_same(A, B);
  } else {
    if (A.size() > B.size()) {
      add_diff(A, B);
    } else {
      add_diff(B, A);
    }
  }

  return 0;
}