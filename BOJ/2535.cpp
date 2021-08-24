#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int N, country, number, score;
  vector<pair<int, pair<int, int>>> participants;
  unordered_map<int, int> countries;

  cin >> N;

  while (N--) {
    cin >> country >> number >> score;
    participants.push_back({score, {country, number}});
  }

  sort(participants.begin(), participants.end(), greater<>());

  int count = 0;
  for (const auto &elem : participants) {
    if (count >= 3) break;

    if (countries[elem.second.first] >= 2) continue;

    printf("%d %d\n", elem.second.first, elem.second.second);
    countries[elem.second.first]++;
    count++;
  }
}
