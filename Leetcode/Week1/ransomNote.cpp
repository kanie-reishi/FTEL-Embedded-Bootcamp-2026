/*
 * Problem: 383. Ransom Note
 * Link: https://leetcode.com/problems/ransom-note/
 * Difficulty: Easy
 * 
 * Description:
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed 
 * by using the letters from magazine and false otherwise.
 * Each letter in magazine can only be used once in ransomNote.
 * 
 * Thought Process:
 * We can use a hash map (or an array of size 26 for lowercase English letters) to count 
 * the occurrences of each character in the magazine. Then, we iterate through the 
 * ransomNote string and decrement the count for each character. If we ever need a 
 * character that isn't available (count <= 0), we can't construct the note.
 * 
 * Time Complexity: O(M + N) where M is the length of magazine and N is the length of ransomNote.
 * Space Complexity: O(K) where K is the number of unique characters in the magazine (at most 26).
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazineHash;

        // Count available letters in the magazine
        for (char c : magazine) {
            magazineHash[c]++;
        }
        
        // Try to construct the ransom note
        for (char c : ransomNote) {
            if (magazineHash[c] <= 0) {
                return false;
            }
            magazineHash[c]--;
        }
        
        return true;
    }
};

// Local Testing
int main() {
    Solution solution;
    
    // Test Case 1
    string ransom1 = "a", magazine1 = "b";
    cout << "Input: ransomNote = \"" << ransom1 << "\", magazine = \"" << magazine1 << "\"\n";
    cout << "Output: " << (solution.canConstruct(ransom1, magazine1) ? "true" : "false") << " (Expected: false)\n\n";

    // Test Case 2
    string ransom2 = "aa", magazine2 = "ab";
    cout << "Input: ransomNote = \"" << ransom2 << "\", magazine = \"" << magazine2 << "\"\n";
    cout << "Output: " << (solution.canConstruct(ransom2, magazine2) ? "true" : "false") << " (Expected: false)\n\n";

    // Test Case 3
    string ransom3 = "aa", magazine3 = "aab";
    cout << "Input: ransomNote = \"" << ransom3 << "\", magazine = \"" << magazine3 << "\"\n";
    cout << "Output: " << (solution.canConstruct(ransom3, magazine3) ? "true" : "false") << " (Expected: true)\n";

    return 0;
}