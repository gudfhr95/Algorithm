#include <string>
#include <vector>

using namespace std;

int getDistance(int a[2], int b[2]) {
  return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

string solution(vector<int> numbers, string hand) {
  string answer = "";
  int left_pos[2] = {3, 0};
  int right_pos[2] = {3, 2};

  for (int i = 0; i < numbers.size(); ++i) {
    if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
      answer += "L";
      left_pos[0] = (numbers[i] - 1) / 3;
      left_pos[1] = (numbers[i] - 1) % 3;
    } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
      answer += "R";
      right_pos[0] = (numbers[i] - 1) / 3;
      right_pos[1] = (numbers[i] - 1) % 3;
    } else {
      int pos[2];
      if (numbers[i] == 0) {
        pos[0] = 3;
        pos[1] = 1;
      } else {
        pos[0] = (numbers[i] - 1) / 3;
        pos[1] = (numbers[i] - 1) % 3;
      }

      int left_distance = getDistance(left_pos, pos);
      int right_distance = getDistance(right_pos, pos);

      if (left_distance < right_distance) {
        answer += "L";
        left_pos[0] = pos[0];
        left_pos[1] = pos[1];
      } else if (left_distance == right_distance) {
        if (hand == "left") {
          answer += "L";
          left_pos[0] = pos[0];
          left_pos[1] = pos[1];
        } else {
          answer += "R";
          right_pos[0] = pos[0];
          right_pos[1] = pos[1];
        }
      } else {
        answer += "R";
        right_pos[0] = pos[0];
        right_pos[1] = pos[1];
      }
    }
  }
  return answer;
}