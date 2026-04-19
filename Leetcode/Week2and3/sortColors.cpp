/*
 * Problem: 75. Sort Colors
 * Link: https://leetcode.com/problems/sort-colors/
 * Difficulty: Medium
 * 
 * Description:
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * 
 * Time Complexity: O(N) using the Dutch National Flag algorithm passing through the items exactly once.
 * Space Complexity: O(1) since the sorting happens securely in-place.
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
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, i = 0;
        while(i <= right){
            if(nums[i] == 0){
                swap(nums[i++], nums[left++]);
            } else if (nums[i] == 2){
                swap(nums[i], nums[right --]);
            } else {
                i ++;
            }
        }
    }
};


// Local Testing
int main() {
    Solution solution;
    vector<int> nums = {2,0,2,1,1,0};
    solution.sortColors(nums);
    cout << "Output: ";
    for(int n : nums) cout << n << " ";
    cout << "\n(Expected: 0 0 1 1 2 2)" << endl;
    return 0;
}
