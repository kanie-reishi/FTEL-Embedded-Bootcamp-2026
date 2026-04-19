/*
 * Problem: 203. Remove Linked List Elements
 * Link: https://leetcode.com/problems/remove-linked-list-elements/
 * Difficulty: Easy
 * 
 * Description:
 * Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
 * 
 * Time Complexity: O(N) where N is the number of nodes in the linked list. We traverse the list exactly once.
 * Space Complexity: O(1) since removing an element does not use any additional memory.
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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* currentNode = dummyHead;
        if(head == nullptr){
            return head;
        }
        while(currentNode->next != nullptr){
            if(currentNode->next->val == val){
                currentNode->next = currentNode->next->next;
            } else {
                currentNode = currentNode->next;
            }
        }
        return dummyHead->next;
    }
};


// Local Testing
int main() {
    Solution solution;
    cout << "Compiled successfully!" << endl;
    return 0;
}
