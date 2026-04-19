/*
 * Problem: 735. Asteroid Collision
 * Link: https://leetcode.com/problems/asteroid-collision/
 * Difficulty: Medium
 * 
 * Description:
 * We are given an array asteroids of integers representing asteroids in a row.
 * For each asteroid, the absolute value represents its size, and the sign represents its direction. Find out the state of the asteroids after all collisions.
 * 
 * Time Complexity: O(N) where N is the number of asteroids. Each asteroid is pushed and popped to the stack at most once.
 * Space Complexity: O(N) in the worst case to store the asteroids in the stack.
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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> s;
        std::vector<int> output;
        for (int i = 0; i < asteroids.size(); i++) {
            if (!s.empty()) {
                if (s.top() > 0 && asteroids[i] < 0) {
                    bool flag = false;
                    while(!s.empty() && s.top() > 0 && s.top() <= abs(asteroids[i])) {
                        if (s.top() == abs(asteroids[i])) {
                            s.pop();
                            flag = true;
                            break;
                        } else {
                            s.pop();
                        }
                    }
                    if(!flag){
                        if(s.empty()){
                            s.push(asteroids[i]);
                        } else if(s.top() < 0){
                            s.push(asteroids[i]);
                        }
                    }
                } else {
                    s.push(asteroids[i]);
                }
            } else {
                s.push(asteroids[i]);
            }
        }
        if(s.empty()){
            return output;
        }
        output.resize(s.size());
        for (int i = output.size() - 1; i >= 0; i--) {
            if(!s.empty()){
                output[i] = s.top();
                s.pop();
            }
        }
        return output;
    }
};


// Local Testing
int main() {
    Solution solution;
    vector<int> asteroids = {5,10,-5};
    vector<int> res = solution.asteroidCollision(asteroids);
    cout << "Output: ";
    for(int a : res) cout << a << " ";
    cout << "\n(Expected: 5 10)" << endl;
    return 0;
}
