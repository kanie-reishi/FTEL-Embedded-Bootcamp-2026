/*
 * Problem: 20. Valid Parentheses
 * Link: https://leetcode.com/problems/valid-parentheses/
 * Difficulty: Easy
 * 
 * Description:
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
 * determine if the input string is valid.
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 * 
 * Thought Process:
 * A Stack is the perfect data structure for this problem. As we iterate through
 * the string, we push all opening brackets onto the stack. When we encounter a 
 * closing bracket, we check if the stack is empty (invalid) or if the top of the 
 * stack is the corresponding opening bracket. If it is, we pop it. If not, it's invalid.
 * In the end, a valid string will result in an empty stack.
 * 
 * Time Complexity: O(N) where N is the length of the string.
 * Space Complexity: O(N) in the worst case if the string is all opening brackets.
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for(int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case ')':
                    if (!stack.empty() && stack.top() == '(') {
                        stack.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (!stack.empty() && stack.top() == '{') {
                        stack.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (!stack.empty() && stack.top() == '[') {
                        stack.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    stack.push(s[i]);
            }
        }
        
        return stack.empty();
    }
};

// Local Testing
int main() {
    Solution solution;
    
    // Test Case 1
    string s1 = "()";
    cout << "Input: \"" << s1 << "\"\n";
    cout << "Output: " << (solution.isValid(s1) ? "true" : "false") << " (Expected: true)\n\n";

    // Test Case 2
    string s2 = "()[]{}";
    cout << "Input: \"" << s2 << "\"\n";
    cout << "Output: " << (solution.isValid(s2) ? "true" : "false") << " (Expected: true)\n\n";

    // Test Case 3
    string s3 = "(]";
    cout << "Input: \"" << s3 << "\"\n";
    cout << "Output: " << (solution.isValid(s3) ? "true" : "false") << " (Expected: false)\n";

    return 0;
}