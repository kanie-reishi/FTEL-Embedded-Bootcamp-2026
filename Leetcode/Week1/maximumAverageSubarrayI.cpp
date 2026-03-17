/*
 * Problem: 643. Maximum Average Subarray I
 * Link: https://leetcode.com/problems/maximum-average-subarray-i/
 * Difficulty: Easy
 * 
 * Description:
 * You are given an integer array nums consisting of n elements, and an integer k.
 * Find a contiguous subarray whose length is equal to k that has the maximum average value 
 * and return this value. Any answer with a calculation error less than 10^-5 will be accepted.
 * 
 * Thought Process:
 * A classic sliding window problem. First, calculate the sum of the first k elements.
 * Then, slide the window by subtracting the element that is left behind and adding the new element.
 * Update the maximum average accordingly.
 * 
 * Time Complexity: O(N) where N is the size of the array.
 * Space Complexity: O(1) since we are only using variables to store current and max sums.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = k - 1;
        int sum = 0;
        
        // Initial window sum
        for(int t = i; t <= j; t++) {
            sum += nums[t];
        }
        
        double max_avg = sum / (double)k;
        i += 1;
        j += 1;
        
        // Slide the window
        while(j < nums.size() && i <= j) {
            sum = sum + nums[j] - nums[i - 1];
            if(sum / (double)k > max_avg) {
                max_avg = sum / (double)k;
            }
            i++;
            j++;
        }
        
        return max_avg;
    }
};

// Local Testing
int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << "Input: nums = [1, 12, -5, -6, 50, 3], k = 4\n";
    cout << "Output: " << solution.findMaxAverage(nums1, k1) << " (Expected: 12.75)\n\n";

    return 0;
}