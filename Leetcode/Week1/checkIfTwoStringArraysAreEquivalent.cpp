/*
 * Problem: 1662. Check If Two String Arrays are Equivalent
 * Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
 * Difficulty: Easy
 * 
 * Description:
 * Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
 * A string is represented by an array if the array elements concatenated in order forms the string.
 * 
 * Thought Process:
 * Custom iterator approaches allow us to check characters one by one without concatenating the strings directly,
 * which saves memory and avoids creating large intermediate strings.
 * We can traverse character by character across different strings in the array.
 * 
 * Time Complexity: O(N) where N is the total number of characters in all words.
 * Space Complexity: O(M) where M is the size of the array since it copies the vectors in the iterator. (Can be optimized to O(1) with const references).
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CharIterator {
public:
    vector<string> words;
    int wordIndex = 0;
    int charIndex = 0;

    CharIterator(vector<string> wordsArg) { words = wordsArg; }
    
    bool hasNext() { 
        return wordIndex != words.size(); 
    }

    char next() {
        char currChar = words[wordIndex][charIndex++];
        if (charIndex == words[wordIndex].length()) {
            charIndex = 0;
            wordIndex++;
        }
        return currChar;
    }
};

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        CharIterator charIterator1(word1);
        CharIterator charIterator2(word2);
        
        while (charIterator1.hasNext() && charIterator2.hasNext()) {
            if (charIterator1.next() != charIterator2.next()) {
                return false;
            }
        }
        return !charIterator1.hasNext() && !charIterator2.hasNext();
    }
};

// Local Testing
int main() {
    Solution solution;
    
    // Test Case 1
    vector<string> word1_1 = {"ab", "c"};
    vector<string> word2_1 = {"a", "bc"};
    cout << "Test Case 1 Output: " 
         << (solution.arrayStringsAreEqual(word1_1, word2_1) ? "true" : "false") 
         << " (Expected: true)\n";

    // Test Case 2
    vector<string> word1_2 = {"a", "cb"};
    vector<string> word2_2 = {"ab", "c"};
    cout << "Test Case 2 Output: " 
         << (solution.arrayStringsAreEqual(word1_2, word2_2) ? "true" : "false") 
         << " (Expected: false)\n";

    return 0;
}