#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
  // 1단계
  for (int i = 0; i < new_id.length(); ++i) {
    new_id[i] = tolower(new_id[i]);
  }
  // 2단계
  string temp = "";
  for (int i = 0; i < new_id.length(); ++i) {
    if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
      temp += new_id[i];
      continue;
    }
    if (new_id[i] >= 48 && new_id[i] <= 57) {
      temp += new_id[i];
      continue;
    }
    if (new_id[i] >= 97 && new_id[i] <= 122) {
      temp += new_id[i];
      continue;
    }
  }
  new_id = temp;
  // 3단계
  temp = "";
  bool flag = false;
  for (int i = 0; i < new_id.length(); ++i) {
    if (new_id[i] == '.') {
      if (flag) {
        continue;
      } else {
        temp += new_id[i];
        flag = true;
      }
    } else {
      temp += new_id[i];
      flag = false;
    }
  }
  new_id = temp;
  // 4단계
  if (new_id[0] == '.') {
    new_id = new_id.substr(1, new_id.length());
  }
  if (new_id[new_id.length() - 1] == '.') {
    new_id = new_id.substr(0, new_id.length() - 1);
  }
  // 5단계
  if (new_id.length() == 0) {
    new_id += 'a';
  }
  // 6단계
  if (new_id.length() >= 16) {
    new_id = new_id.substr(0, 15);
  }
  if (new_id[new_id.length() - 1] == '.') {
    new_id = new_id.substr(0, new_id.length() - 1);
  }
  // 7단계
  if (new_id.length() <= 2) {
    while (new_id.length() < 3) {
      new_id += new_id[new_id.length() - 1];
    }
  }
  return new_id;
}