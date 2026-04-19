/*
 * Problem: 150. Evaluate Reverse Polish Notation
 * Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * Difficulty: Medium
 * 
 * Description:
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation. Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
 * 
 * Time Complexity: O(N) where N is the number of tokens. Each token is processed exactly once using a stack.
 * Space Complexity: O(N) to store the operands in the stack.
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

// Required for isdigit
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        int a, b, strToInt;
        for(int i = 0;i < tokens.size();i ++){
            if(tokens[i] == "+"){
                if(s.size() < 2){
                    // catch error
                    return NULL;
                }
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a + b);
            } else if(tokens[i] == "-"){
                if(s.size() < 2){
                    // catch error
                    return NULL;
                }
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a - b);
            } else if(tokens[i] == "*"){
                if(s.size() < 2){
                    // catch error
                    return NULL;
                }
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                s.push(a * b);
            }else if(tokens[i] == "/"){
                if(s.size() < 2){
                    // catch error
                    return NULL;
                }
                b = s.top();
                s.pop();
                a = s.top();
                s.pop();
                if(b == 0){
                    // Catch 0 division
                    return NULL;
                }
                s.push(a / b);
            } else {
                strToInt = std::stoi(tokens[i]);
                s.push(strToInt);
            }
        }
        return s.top();
    }
};


// Local Testing
int main() {
    Solution solution;
    vector<string> tokens = {"2","1","+","3","*"};
    cout << "Output: " << solution.evalRPN(tokens) << " (Expected: 9)" << endl;
    return 0;
}
