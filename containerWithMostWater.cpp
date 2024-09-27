#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int maxWater = 0;

    while (l < r){
      maxWater = max(maxWater, (r-l)* min(height[l], height[r]));
      if (height[l] < height[r]) l++;
      else r--;
    }
    return maxWater;
  }
};


// water in container [i, j] = min(height[i], height[j]) * (j - i)
// brutal force O(n^2)
// two ptr 
// So if there l and r ptr l at 0 l at height.size()-1
// we can get a size of current container
// we want size increase -> -> Monotonicity Increment? decrement? -> greedy

// idx: 0 1 2 3 4 5 6
// hgh: 1 9 2 3 5 7 8
//      l           r -> current size is length X min(height) = 7 * 1
// so for searching other optins, we have to reduce lengh  -size
// so ensure it can still +size, we need +height (+min(h[i], h[j]))
// we can move (a) l -> or (b) move r <- both -length the same amount (-1)
// we choose the move that has relatively bigger height