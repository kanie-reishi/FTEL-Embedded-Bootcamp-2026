/*
 * Problem: 977. Squares of a Sorted Array
 * Link: https://leetcode.com/problems/squares-of-a-sorted-array/
 * Difficulty: Easy
 * 
 * Description:
 * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 * 
 * Time Complexity: O(N) where N is the size of the array, using a two-pointer approach to merge squares.
 * Space Complexity: O(N) allocated exclusively for the solution output array.
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
    vector<int> sortedSquares(vector<int>& nums) {
        int right = nums.size() - 1;
        int left = 0;
        vector<int> output;
        if(abs(nums[right]) < abs(nums[left])){
            output.push_back(nums[left]*nums[left]);
            left ++;
        } else {
            output.push_back(nums[right]*nums[right]);
            right --;
        }
        while(left <= right){
            if(abs(nums[right]) < abs(nums[left])){
                output.push_back(nums[left]*nums[left]);
                left ++;
            } else {
                output.push_back(nums[right]*nums[right]);
                right --;
            }
        }
        reverse(output.begin(), output.end());
        return output;
    }
};


// Local Testing
int main() {
    Solution solution;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> res = solution.sortedSquares(nums);
    cout << "Output: ";
    for(int n : res) cout << n << " ";
    cout << "\n(Expected: 0 1 9 16 100)" << endl;
    return 0;
}
