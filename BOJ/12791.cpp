#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, string>> ALBUM = {
    {1967, "DavidBowie"},
    {1969, "SpaceOddity"},
    {1970, "TheManWhoSoldTheWorld"},
    {1971, "HunkyDory"},
    {1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
    {1973, "AladdinSane"},
    {1973, "PinUps"},
    {1974, "DiamondDogs"},
    {1975, "YoungAmericans"},
    {1976, "StationToStation"},
    {1977, "Low"},
    {1977, "Heroes"},
    {1979, "Lodger"},
    {1980, "ScaryMonstersAndSuperCreeps"},
    {1983, "LetsDance"},
    {1984, "Tonight"},
    {1987, "NeverLetMeDown"},
    {1993, "BlackTieWhiteNoise"},
    {1995, "1.Outside"},
    {1997, "Earthling"},
    {1999, "Hours"},
    {2002, "Heathen"},
    {2003, "Reality"},
    {2013, "TheNextDay"},
    {2016, "BlackStar"}};

int main() {
  int Q, S, E;

  cin >> Q;

  while (Q--) {
    cin >> S >> E;

    vector<pair<int, string>> result;

    for (int i = S; i <= E; i++) {
      for (const auto &elem : ALBUM) {
        if (elem.first == i) {
          result.push_back(elem);
        }
      }
    }

    cout << result.size() << '\n';
    for (const auto &elem : result) {
      cout << elem.first << ' ' << elem.second << '\n';
    }
  }
}