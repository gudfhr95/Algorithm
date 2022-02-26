#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participants, vector<string> completions) {
  unordered_map<string, int> map;

  for (auto &completion : completions) {
    ++map[completion];
  }

  for (auto &participant : participants) {
    --map[participant];
  }

  for (auto &pair : map) {
    if (pair.second < 0) {
      return pair.first;
    }
  }
}