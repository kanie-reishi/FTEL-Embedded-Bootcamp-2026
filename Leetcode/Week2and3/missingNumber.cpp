/*
 * Problem: 268. Missing Number
 * Link: https://leetcode.com/problems/missing-number/
 * Difficulty: Easy
 * 
 * Description:
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
 * 
 * Time Complexity: O(N) to iterate and find the missing number.
 * Space Complexity: O(1) beyond the input array as we swap elements in place or use math.
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
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 1){
            if(nums[0] == 0){
                return 1;
            } else {
                return 0;
            }
        }
        nums.push_back(0);
        int n = nums.size();
        for(int i = 0;i < nums.size();i ++){
            nums[nums[i] % n] += n;
        }
        for(int i = 0;i < nums.size();i ++){
            if(nums[i] / n == 0){
                return i;
            }
        }
        if(nums[nums.size() - 1] != n){
            return n;
        } else {
            return 0;
        }
    }
};


// Local Testing
int main() {
    Solution solution;
    vector<int> nums = {3,0,1};
    cout << "Output: " << solution.missingNumber(nums) << " (Expected: 2)" << endl;
    return 0;
}
