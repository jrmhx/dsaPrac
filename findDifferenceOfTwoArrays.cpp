#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<int> a1, a2;
    unordered_set<int> s1, s2;

    for (auto it=nums1.begin(); it<nums1.end();it++) s1.insert(*it);
    for (auto it=nums2.begin(); it<nums2.end();it++) s2.insert(*it);

    for_each(s1.begin(), s1.end(), [&s2, &a1](int num){
      if(s2.find(num) == s2.end()) a1.push_back(num);
    });

    for_each(s2.begin(), s2.end(), [&s1, &a2](int num){
      if(s1.find(num) == s1.end()) a2.push_back(num);
    });

    vector<vector<int>> ans = {a1, a2};
    return ans;
  }
};