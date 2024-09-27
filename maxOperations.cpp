#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> visit;

    int op = 0;
    for (auto it = nums.begin(); it < nums.end(); it++){
      if (visit.find(k - *it) != visit.end() && visit[k - *it] > 0){
        op++;
        // remove this pair of nums
        visit[k - *it] --;
      } else if (visit.find(*it) != visit.end()){
        visit[*it] ++;
      } else {
        visit[*it] = 1;
      }
    }
    return op;
  }
};


// its a search for all possible ways question -> cut branch
// hash map (unordered_map)
// similar to 2Sum
// differences: 2Sum unordered_map is <val, idx>
//              here we dont need idx, but the count matters 
// (how many time we saw this val -> how many op)