#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>, int> row_map;
    int result = 0;
    int n = grid.size();
    for(auto row : grid) row_map[row] += 1;
    for(int i = 0; i < n; i++){
      vector<int> col;
      for (int j = 0; j < n; j++){
        col.push_back(grid[j][i]);
      }
      result += row_map[col];
    }
    return result;
  }
};


// brute force O(n^2) for a n * n matrix
// didnt memorize the row/col that we checked before

// result = 0
// umap<row, count>
// work through cols, result += umap[col]
// vector is comparable (element wise) but not hashable by default.