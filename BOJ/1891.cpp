#include <cmath>
#include <iostream>

using namespace std;

int d;

pair<long, long> getPos(string n) {
  long x = 0, y = 0;

  for (int i = 0; i < n.length(); i++) {
    if (n[i] == '1') {
      x += pow(2, d - 1 - i);
    } else if (n[i] == '3') {
      y += pow(2, d - 1 - i);
    } else if (n[i] == '4') {
      x += pow(2, d - 1 - i);
      y += pow(2, d - 1 - i);
    }
  }

  return {x, y};
}

string getResult(pair<long, long> pos) {
  long width = pow(2, d);

  if (pos.first >= width || pos.second >= width || pos.first < 0 ||
      pos.second < 0) {
    return "-1";
  }

  string result = "";
  for (int n = d - 1; n >= 0; n--) {
    width = pow(2, n);
    if (pos.first < width && pos.second < width) {
      result += '2';
    } else if (pos.first >= width && pos.second < width) {
      result += '1';
      pos.first -= width;
    } else if (pos.first < width && pos.second >= width) {
      result += '3';
      pos.second -= width;
    } else {
      result += '4';
      pos.first -= width;
      pos.second -= width;
    }
  }

  return result;
}

int main() {
  string n;
  long x, y;

  cin >> d >> n >> x >> y;

  pair<long, long> pos = getPos(n);
  pos.first += x;
  pos.second -= y;

  cout << getResult(pos);
}