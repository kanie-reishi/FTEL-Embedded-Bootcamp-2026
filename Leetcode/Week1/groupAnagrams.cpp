/*
 * Problem: 49. Group Anagrams
 * Link: https://leetcode.com/problems/group-anagrams/
 * Difficulty: Medium
 * 
 * Description:
 * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
 * typically using all the original letters exactly once.
 * 
 * Thought Process:
 * Two strings are anagrams if and only if their sorted versions are identical.
 * We can use a hash map where the key is the sorted version of the string, and the value 
 * is a list of all strings from the input that match that sorted key.
 * Finally, we extract all the grouped lists from the map's values to form the result.
 * 
 * Time Complexity: O(N * K log K) where N is the number of strings, and K is the maximum length of a string.
 * Space Complexity: O(N * K) to store the grouped anagrams in the hash map and the result array.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        
        // Group strings by their sorted version
        for(auto s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        
        // Extract the grouped anagrams
        for(auto x : mp) {
            ans.push_back(x.second);
        }
        
        return ans;
    }
};

// Local Testing
int main() {
    Solution solution;
    
    // Test Case 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result1 = solution.groupAnagrams(strs1);
    
    cout << "Output: [\n";
    for(const auto& group : result1) {
        cout << "  [";
        for(int i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"" << (i < group.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }
    cout << "]\n";

    return 0;
}