/*
 * Problem: 179. Largest Number
 * Link: https://leetcode.com/problems/largest-number/
 * Difficulty: Medium
 * 
 * Description:
 * Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
 * Since the result may be very large, so you need to return a string instead of an integer.
 * 
 * Time Complexity: O(N log N) where N is the number of items. Sorting the array takes O(N log N).
 * Space Complexity: O(N) to hold string representations of the numbers for sorting and concatenation.
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
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(int x : nums){
            s.push_back(to_string(x));
        }
        std::sort(s.begin(), s.end(), [](string &a, string &b){
            return a + b > b + a;
        });
        if(s[0] == "0"){
            return "0";
        }
        string res = "";
        for (string &str: s){
            res += str;
        }
        return res;
    }
};


// Local Testing
int main() {
    Solution solution;
    vector<int> nums = {10,2};
    cout << "Output: " << solution.largestNumber(nums) << " (Expected: 210)" << endl;
    return 0;
}
