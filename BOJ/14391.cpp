#include <iostream>

using namespace std;

int N, M;

char paper[4][5];
int pos[4][4];

int getResult() {
  int result = 0;

  for (int y = 0; y < N; y++) {
    string temp = "0";
    for (int x = 0; x < M; x++) {
      if (pos[y][x] == 1) {
        result += stoi(temp);
        temp = "0";
      } else {
        temp += paper[y][x];
      }
    }

    result += stoi(temp);
  }

  for (int x = 0; x < M; x++) {
    string temp = "0";
    for (int y = 0; y < N; y++) {
      if (pos[y][x] == 0) {
        result += stoi(temp);
        temp = "0";
      } else {
        temp += paper[y][x];
      }
    }

    result += stoi(temp);
  }

  return result;
}

void getPos(int b) {
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if ((b & (1 << (y * M + x))) == 0)
        pos[y][x] = 0;
      else
        pos[y][x] = 1;
    }
  }
}

int tear(int b) {
  getPos(b);
  return getResult();
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> paper[i];
  }

  int result = -987654321;
  for (int i = 0; i < (1 << (N * M)); i++) {
    result = max(result, tear(i));
  }
  cout << result;
}