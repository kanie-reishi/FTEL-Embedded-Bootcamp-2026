/*
 * Problem: 1431. Kids With the Greatest Number of Candies
 * Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
 * Difficulty: Easy
 * 
 * Description:
 * There are n kids with candies. You are given an integer array candies, where each candies[i] represents 
 * the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.
 * Return a boolean array result of length n, where result[i] is true if giving the ith kid all the 
 * extraCandies will make them have the greatest number of candies among all the kids, or false otherwise.
 * 
 * Thought Process:
 * 1. Make a first pass through the array to find the maximum number of candies any kid currently has.
 * 2. Make a second pass to check for each kid, if their current candies plus the extraCandies is greater
 *    than or equal to that maximum.
 * 
 * Time Complexity: O(N) where N is the number of kids (two passes through the array).
 * Space Complexity: O(N) to store the output boolean array.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        vector<bool> output(candies.size());
        
        // Find the maximum candies any kid has
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] > max) {
                max = candies[i];
            }
        }
        
        // Check if adding extraCandies meets or exceeds the max
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= max) {
                output[i] = true;
            } else {
                output[i] = false;
            }
        }
        
        return output;
    }
};

// Local Testing
int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> candies1 = {2, 3, 5, 1, 3};
    int extra1 = 3;
    vector<bool> result1 = solution.kidsWithCandies(candies1, extra1);
    
    cout << "Test Case 1 Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << (result1[i] ? "true" : "false") << (i < result1.size() - 1 ? ", " : "");
    }
    cout << "] (Expected: [true, true, true, false, true])\n";

    return 0;
}