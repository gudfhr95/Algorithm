#include <iostream>

using namespace std;

int N, M;
int rides[10000];

int main() {
  cin >> N >> M;

  if (N <= M) {
    cout << N;
    return 0;
  }

  for (int i = 0; i < M; i++) {
    cin >> rides[i];
  }

  long long l = 0;
  long long r = 2000000000LL * 1000000LL;
  while (l <= r) {
    long long mid = (l + r) / 2;
    long long begin, end;

    begin = end = 0;

    end = M;
    for (int i = 0; i < M; i++) {
      end += mid / rides[i];
    }

    begin = end;
    for (int i = 0; i < M; i++) {
      if (mid % rides[i] == 0) {
        begin -= 1;
      }
    }

    begin += 1;

    if (N < begin) {
      r = mid - 1;
    } else if (N > end) {
      l = mid + 1;
    } else {
      for (int i = 0; i < M; i++) {
        if (mid % rides[i] == 0) {
          if (N == begin) {
            cout << i + 1;
            return 0;
          }
          begin += 1;
        }
      }
    }
  }
}