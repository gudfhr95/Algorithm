#include <iostream>
#include <vector>

using namespace std;

int N;
long long B;

vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b) {
  vector<int> row(N);
  vector<vector<int>> matrix(N, row);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      int sum = 0;
      for (int k = 0; k < N; k++) {
        sum += a[y][k] * b[k][x];
      }
      matrix[y][x] = sum % 1000;
    }
  }

  return matrix;
}

vector<vector<int>> pow(vector<vector<int>> a, long long b) {
  if (b == 0) {
    vector<int> row(N);
    vector<vector<int>> matrix(N, row);

    for (int i = 0; i < N; i++) {
      matrix[i][i] = 1;
    }

    return matrix;
  } else if (b == 1) {
    return a;
  } else if (b % 2 == 0) {
    vector<vector<int>> temp = pow(a, b / 2);
    return mult(temp, temp);
  } else if (b % 2 == 1) {
    return mult(a, pow(a, b - 1));
  }
}

int main() {
  cin >> N >> B;

  vector<int> row(N);
  vector<vector<int>> matrix(N, row);
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> matrix[y][x];
    }
  }

  auto result = pow(matrix, B);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cout << result[y][x] % 1000 << ' ';
    }
    cout << '\n';
  }
}