/*
 * Problem: 237. Delete Node in a Linked List
 * Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
 * Difficulty: Medium
 * 
 * Description:
 * There is a singly-linked list head and we want to delete a node node in it.
 * You are given the node to be deleted node. You will not be given access to the first node of head.
 * 
 * Time Complexity: O(N) in the provided implementation because it shifts all subsequent node values. (Optimal is O(1)).
 * Space Complexity: O(1) since we only use pointers.
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next != nullptr){
            node->val = node->next->val;
            if(node->next->next == nullptr){
                node->next = nullptr;
                break;
            }
            node = node->next;
        }
    }
};


// Local Testing
int main() {
    Solution solution;
    cout << "Compiled successfully!" << endl;
    return 0;
}
