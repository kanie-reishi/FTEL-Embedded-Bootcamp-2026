/*
 * Problem: 561. Array Partition
 * Link: https://leetcode.com/problems/array-partition/
 * Difficulty: Easy
 * 
 * Description:
 * Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized.
 * 
 * Time Complexity: O(N) where N is the number of elements. The current code uses a bucket sort approach bounded by the value range.
 * Space Complexity: O(1) since the bucket size is constant.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int bucket[20001] = {0};
        for(int x = 0;x < nums.size();x ++){
            bucket[nums[x] + 10000] += 1;
        }
        int res = 0;
        bool flag = true;
        for(int i = 0;i < 20001;i ++){
            while(bucket[i] != 0){
                if(flag == true){
                    res = res + i - 10000;
                }
                flag = !flag;
                bucket[i] -= 1;
            }
        }
        return res;
    }
};


// Local Testing
int main() {
    Solution solution;
    vector<int> nums = {1,4,3,2};
    cout << "Output: " << solution.arrayPairSum(nums) << " (Expected: 4)" << endl;
    return 0;
}
