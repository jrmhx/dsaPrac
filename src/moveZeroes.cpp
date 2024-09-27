#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int head = 0;

        while (head < nums.size() && nums[head] != 0){
            head++;
        }

        int tail = head + 1;

        while (tail < nums.size() && head < nums.size()){
            if (nums[head]!=0) head++;
            if (nums[tail]==0) tail++;

            if (tail < nums.size() && head < nums.size() && nums[head] == 0 && nums[tail] != 0){
                int temp = nums[head];
                nums[head] = nums[tail];
                nums[tail] = temp;
            }
        }
    }
};