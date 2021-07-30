#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, string delim) {
  vector<string> splited;
  size_t previous = 0, current;
  string substring;

  current = s.find(delim);
  while (current != string::npos) {
    substring = s.substr(previous, current - previous);
    splited.push_back(substring);
    previous = current + 1;
    current = s.find(delim, previous);
  }
  substring = s.substr(previous, current - previous);
  splited.push_back(substring);

  return splited;
}

int main() {
  string current_string, start_string;
  cin >> current_string >> start_string;

  vector<string> current_time = split(current_string, ":");
  vector<string> start_time = split(start_string, ":");

  int current_sum = stoi(current_time[0]) * 3600 + stoi(current_time[1]) * 60 +
                    stoi(current_time[2]);
  int start_sum = stoi(start_time[0]) * 3600 + stoi(start_time[1]) * 60 +
                  stoi(start_time[2]);

  int end_sum;
  if (current_sum < start_sum) {
    end_sum = start_sum - current_sum;
  } else {
    end_sum = 24 * 3600 - current_sum + start_sum;
  }

  printf("%02d:%02d:%02d", end_sum / 3600, (end_sum % 3600) / 60,
         (end_sum) % 60);

  return 0;
}