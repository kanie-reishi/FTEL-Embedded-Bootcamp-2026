/*
 * Problem: 232. Implement Queue using Stacks
 * Link: https://leetcode.com/problems/implement-queue-using-stacks/
 * Difficulty: Easy
 * 
 * Description:
 * Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
 * 
 * Time Complexity: O(1) amortized for pop and peek operations. O(1) for push and empty.
 * Space Complexity: O(N) where N is the number of elements stored in the queue.
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

class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int val = st2.top();
        st2.pop();
        return val;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};

/*
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


// Local Testing
int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    cout << "Output: " << obj->pop() << " (Expected: 1)" << endl;
    return 0;
}
