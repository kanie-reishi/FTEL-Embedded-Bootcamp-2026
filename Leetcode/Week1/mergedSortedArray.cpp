/*
 * Problem: 88. Merge Sorted Array
 * Link: https://leetcode.com/problems/merge-sorted-array/
 * Difficulty: Easy
 * 
 * Description:
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
 * and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * The final sorted array should not be returned by the function, but instead be stored 
 * inside the array nums1. To accommodate this, nums1 has a length of m + n.
 * 
 * Thought Process:
 * To achieve optimal time and space complexity, iterate backward from the end of nums1.
 * Compare the largest unmerged elements from nums1 and nums2, and place the larger element
 * at the very end of the num1 array. This prevents overwriting elements in nums1 that 
 * haven't been processed yet.
 * 
 * Time Complexity: O(m + n) as we iterate once across all elements.
 * Space Complexity: O(1) by updating the array in place.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 && n > 0) {
            if(nums1[m - 1] >= nums2[n - 1]) {
                nums1[m + n - 1] = nums1[m - 1];
                m -= 1;
            } else {
                nums1[m + n - 1] = nums2[n - 1];
                n -= 1;
            }
        }
        
        // If there are still elements in nums2, copy them over
        // (Elements remaining in nums1 are already in the correct place)
        if(n > 0) {
            for(int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
        }
    }
};

// Local Testing
int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> nums1_1 = {1, 2, 3, 0, 0, 0}; 
    int m1 = 3;
    vector<int> nums2_1 = {2, 5, 6}; 
    int n1 = 3;
    
    solution.merge(nums1_1, m1, nums2_1, n1);
    
    cout << "Output: [";
    for(int i = 0; i < nums1_1.size(); i++) {
        cout << nums1_1[i] << (i < nums1_1.size() - 1 ? ", " : "");
    }
    cout << "] (Expected: [1, 2, 2, 3, 5, 6])\n";

    return 0;
}