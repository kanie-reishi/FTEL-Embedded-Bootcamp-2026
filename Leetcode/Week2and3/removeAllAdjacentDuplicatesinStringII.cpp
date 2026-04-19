/*
 * Problem: 1209. Remove All Adjacent Duplicates in String II
 * Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
 * Difficulty: Medium
 * 
 * Description:
 * You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together. We repeatedly make k duplicate removals on s until we no longer can.
 * 
 * Time Complexity: O(N) where N is string length, achieved by processing each char in one pass using a stack.
 * Space Complexity: O(N) memory consumed internally for the stack storing char and counts.
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
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        for(char c : s){
            if(!st.empty() && st.back().first == c){
                st.back().second++;
            } else {
                st.push_back({c, 1});
            }
            if(st.back().second == k){
                st.pop_back();
            }
        } 
        string res = "";
        for (auto &[c, count] : st){
            res.append(count, c);
        }
        return res;
    }
};


// Local Testing
int main() {
    Solution solution;
    string s = "abcd";
    cout << "Output: " << solution.removeDuplicates(s, 2) << " (Expected: abcd)" << endl;
    return 0;
}
