#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  int finished = 0;
  int bridge_weight = 0;
  int truck_index = 0;
  queue<int> passing;

  while (true) {
    if (passing.size() == bridge_length) {
      bridge_weight -= passing.front();
      if (passing.front() != 0) finished++;
      passing.pop();
    }
    if (truck_weights[truck_index] + bridge_weight <= weight) {
      passing.push(truck_weights[truck_index]);
      bridge_weight += truck_weights[truck_index];
      truck_index++;
    } else {
      passing.push(0);
    }

    answer++;
    if (finished == truck_weights.size()) {
      break;
    }
  }
  return answer;
}