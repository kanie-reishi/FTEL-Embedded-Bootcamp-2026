/*
 * Problem: 217. Contains Duplicate
 * Link: https://leetcode.com/problems/contains-duplicate/
 * Difficulty: Easy
 * 
 * Description:
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 * 
 * Time Complexity: O(N) where N is the number of elements in the array. We iterate through the array once.
 * Space Complexity: O(N) due to the use of a hashmap to store the frequency of the elements.
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
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for(int num : nums){
            if(hashmap[num] >= 1){
                return true;
            }
            hashmap[num] ++;
        }
        return false;
    }
};


// Local Testing
int main() {
    Solution solution;
    vector<int> nums = {1,2,3,1};
    cout << "Output: " << (solution.containsDuplicate(nums) ? "true" : "false") << " (Expected: true)" << endl;
    return 0;
}
