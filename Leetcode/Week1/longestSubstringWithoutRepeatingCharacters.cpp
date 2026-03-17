/*
 * Problem: 3. Longest Substring Without Repeating Characters
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Difficulty: Medium
 * 
 * Description:
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * Thought Process:
 * Use a sliding window and a hash map to map characters to their most recent index.
 * Expand the window with right. If the current character is already in the map and 
 * its previous index is within our current window (>= left), we shrink the window 
 * by moving left to lastSeen[c] + 1 to exclude the duplicate.
 * Continuously update the maximum length found so far.
 * 
 * Time Complexity: O(N) where N is the length of the string s.
 * Space Complexity: O(min(N, M)) where M is the size of the alphabet used in s.
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
        unordered_map<char, int> lastSeen;

        for(int right = 0; right < s.length(); right++) {
            char c = s[right];
            
            if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }
            
            maxLength = max(maxLength, right - left + 1);
            lastSeen[c] = right;
        }
        
        return maxLength;
    }
};

// Local Testing
int main() {
    Solution solution;
    
    // Test Case 1
    string s1 = "abcabcbb";
    cout << "Input: \"" << s1 << "\"\n";
    cout << "Output: " << solution.lengthOfLongestSubstring(s1) << " (Expected: 3)\n\n";

    // Test Case 2
    string s2 = "pwwkew";
    cout << "Input: \"" << s2 << "\"\n";
    cout << "Output: " << solution.lengthOfLongestSubstring(s2) << " (Expected: 3)\n";

    return 0;
}