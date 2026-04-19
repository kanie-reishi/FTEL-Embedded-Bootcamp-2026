/*
 * Problem: 225. Implement Stack using Queues
 * Link: https://leetcode.com/problems/implement-stack-using-queues/
 * Difficulty: Easy
 * 
 * Description:
 * Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
 * 
 * Time Complexity: O(N) for push operation as we rotate the queue. O(1) for pop, top, and empty.
 * Space Complexity: O(N) where N is the number of elements to store in the queue.
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

class MyStack {
std::queue<int> queue;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int size = queue.size();
        queue.push(x);
        for(int i = 0;i < size;i ++){
            queue.push(queue.front());
            queue.pop();
        }
    }
    
    int pop() {
        int temp = queue.front();
        queue.pop();
        return temp;
    }
    
    int top() {
        return queue.front();
    }
    
    bool empty() {
        return queue.empty();
    }
};

/*
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


// Local Testing
int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    cout << "Output: " << obj->pop() << " (Expected: 1)" << endl;
    return 0;
}
