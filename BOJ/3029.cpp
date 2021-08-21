#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string s, string delim) {
  vector<string> result;
  size_t prev = 0, cur;
  string substring;

  cur = s.find(delim);
  while (cur != string::npos) {
    substring = s.substr(prev, cur - prev);
    result.push_back(substring);
    prev = cur + 1;
    cur = s.find(delim, prev);
  }
  substring = s.substr(prev, cur - prev);
  result.push_back(substring);

  return result;
}

int convertToSecond(vector<string> time) {
  return (stoi(time[0]) * 3600) + (stoi(time[1]) * 60) + stoi(time[2]);
}

void printHour(int sec) {
  int hour = sec / 3600;
  int minute = (sec % 3600) / 60;
  int second = sec % 60;

  printf("%02d:%02d:%02d", hour, minute, second);
}

int main() {
  string s, e;
  vector<string> start, end;

  cin >> s >> e;
  start = split(s, ":");
  end = split(e, ":");

  int startSec = convertToSecond(start);
  int endSec = convertToSecond(end);

  int time;
  if (endSec > startSec)
    time = endSec - startSec;
  else if (endSec == startSec)
    time = 24 * 3600;
  else
    time = endSec - startSec + (24 * 3600);

  printHour(time);
}
