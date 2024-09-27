#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> umap;
    unordered_set<int> uset;

    for (auto it=arr.begin(); it!=arr.end(); it++){
      if (umap.find(*it)==umap.end()) umap[*it] = 1;
      else umap[*it] ++;
    }
    for (auto pair : umap){
      if(uset.find(pair.second) != uset.end()){
        return false;
      } else {
        uset.insert(pair.second);
      }
    }
    return true;
  }
};