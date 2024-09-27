#include <vector>
#include <string>
#include <iostream>

using namespace std;

// try think reverse, moveZeroes and keep the non-zeroes relative order -> move non-zeros


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
                left++;
            }
        }        
    }
};