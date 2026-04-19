/*
 * Problem: 1544. Make The String Great
 * Link: https://leetcode.com/problems/make-the-string-great/
 * Difficulty: Easy
 * 
 * Description:
 * Given a string s of lower and upper case English letters. A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where they are the same letter but in different cases. Return the string after making it good.
 * 
 * Time Complexity: O(N) where N is the length of the string, doing a single pass using a stack.
 * Space Complexity: O(N) to store the characters in the stack.
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
    string makeGood(string s) {
        std::stack<char> resStack;
        std::string result = "";
        for(int i = s.length() - 1;i >= 0;i --){
            if(!resStack.empty() && abs(s[i] - resStack.top()) == 32){
                resStack.pop();
            } else {
                resStack.push(s[i]);
            }
        }
        int l = resStack.size();
        for(int i = 0;i < l;i ++){
            result.push_back(resStack.top());
            resStack.pop();
        }
        return result;
    }
};


// Local Testing
int main() {
    Solution solution;
    string s = "leEeetcode";
    cout << "Output: " << solution.makeGood(s) << " (Expected: leetcode)" << endl;
    return 0;
}
