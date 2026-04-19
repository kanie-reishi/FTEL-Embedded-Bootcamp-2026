/*
 * Problem: 414. Third Maximum Number
 * Link: https://leetcode.com/problems/third-maximum-number/
 * Difficulty: Easy
 * 
 * Description:
 * Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.
 * 
 * Time Complexity: O(N) where N is the length of the array, tracking the top 3 maximum values simultaneously in a single pass.
 * Space Complexity: O(1) since we only use a small constant number of variables.
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
    int thirdMax(vector<int>& nums) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int thirdMax = INT_MIN;

        int countFirst = 0;
        int countSecond = 0;
        int countThird = 0;
        for(int i = 0;i < nums.size();i ++){
            if((nums[i] == firstMax || nums[i] == secondMax || nums[i] == thirdMax) && (nums[i] != INT_MIN)){
                continue;
            }
            if(firstMax == INT_MIN || nums[i] > firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
                countFirst += 1;
            } else if (secondMax == INT_MIN || nums[i] > secondMax){
                thirdMax = secondMax;
                secondMax = nums[i];
                countSecond += 1;
            } else if (thirdMax == INT_MIN || nums[i] > thirdMax){
                thirdMax = nums[i];
                countThird += 1;
            }
            cout << thirdMax << " " << secondMax << " " << firstMax << "\n";
            cout << countThird << " " << countSecond << " " << countFirst << "\n";
        }
        if((countThird > 0 || (countFirst > 2) || (countSecond + countFirst > 2)) && thirdMax != secondMax){
            return thirdMax;
        } else {
            return firstMax;
        }
    }
};


// Local Testing
int main() {
    Solution solution;
    vector<int> nums = {3,2,1};
    cout << "\nOutput: " << solution.thirdMax(nums) << " (Expected: 1)" << endl;
    return 0;
}
