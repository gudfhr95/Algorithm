#include <cstdio>
#include <stack>

using namespace std;

int n;
int a[500000];

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  stack<int> s;
  stack<int> c;

  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int h = a[i];
    int cnt = 1;

    while (!s.empty()) {
      if (s.top() <= a[i]) {
        ans += (long long)c.top();

        if (s.top() == a[i]) {
          cnt += c.top();
        }

        s.pop();
        c.pop();
      } else {
        break;
      }
    }

    if (!s.empty()) {
      ans += 1LL;
    }

    s.push(h);
    c.push(cnt);
  }

  printf("%lld\n", ans);

  return 0;
}