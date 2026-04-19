/*
 * Problem: 739. Daily Temperatures
 * Link: https://leetcode.com/problems/daily-temperatures/
 * Difficulty: Medium
 * 
 * Description:
 * Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
 * 
 * Time Complexity: O(N) where N is the number of temperatures, since each temperature is pushed and popped from the monotonic stack at most once.
 * Space Complexity: O(N) to store the monotonic stack representing the indices.
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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> s;
        int cur;
        for(int i = 0;i < temperatures.size();i ++){
            while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                cur = s.top();
                s.pop();
                ans[cur] = i - cur;
            }
            s.push(i);
        }
        return ans;
    }
};


// Local Testing
int main() {
    Solution solution;
    vector<int> temps = {73,74,75,71,69,72,76,73};
    vector<int> res = solution.dailyTemperatures(temps);
    cout << "Output: ";
    for(int t : res) cout << t << " ";
    cout << endl;
    return 0;
}
