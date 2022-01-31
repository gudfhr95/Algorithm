#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  queue<int> progresses_queue;
  int deploy_sum;

  for (int i = 0; i < progresses.size(); ++i) {
    progresses_queue.push(i);
  }

  while (true) {
    if (progresses_queue.size() == 0) {
      break;
    }

    for (int i = progresses_queue.front(); i <= progresses_queue.back(); ++i) {
      progresses[i] += speeds[i];
    }

    deploy_sum = 0;
    if (progresses[progresses_queue.front()] >= 100) {
      while (progresses_queue.size() != 0) {
        if (progresses[progresses_queue.front()] < 100) {
          break;
        }
        progresses_queue.pop();
        deploy_sum++;
      }
      answer.push_back(deploy_sum);
    }
  }

  return answer;
}