#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<vector<int>, vector<string>> strgroup;
    for (auto str : strs){
      vector<int> char_count(26, 0);
      for (auto c : str) char_count[c-'a']++;
      strgroup[char_count].push_back(str);
    }
    vector<vector<string>> result;
    for (auto kvpair: strgroup){
      result.push_back(kvpair.second);
    }
    return result;
  }
};

// n = 10^4
// m = 100
// vector<int> dict (26);
// map<vector<int>, vector<string>>