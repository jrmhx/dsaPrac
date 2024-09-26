#include <vector>
#include <unordered_map>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result;
    auto visit = new std::unordered_map<int, int>(); // memorize index and val when we walk thro nums
    int length = nums.size();
    for (int i = 0; i < nums.size(); i++){
      // check if we have target - nums[i]
      if (visit->find(target-nums[i]) != visit->end()){ // find a sol
        result.push_back(i);
        result.push_back((*visit)[target-nums[i]]);
      }
      (*visit)[nums[i]] = i; // visit is a pointer
      // or visit->operator[](nums[i]) = i;

    }
    delete visit;
    return result;
  }
};