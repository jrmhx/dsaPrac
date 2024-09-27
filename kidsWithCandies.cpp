#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int oldMax = 0;
    vector<bool> result(candies.size());

    oldMax = *max_element(candies.begin(), candies.end());

    transform(candies.begin(), candies.end(), result.begin(), [oldMax, extraCandies](int candy){
      return candy+extraCandies >= oldMax;
    });
    return result;
  }
};