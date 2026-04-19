/*
 * Problem: 19. Remove Nth Node From End of List
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Difficulty: Medium
 * 
 * Description:
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 * 
 * Time Complexity: O(N) where N is the number of nodes in the list. The list is passed through twice or once using two pointers.
 * Space Complexity: O(1) since only constant extra space is required for pointers.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* currentNode = head;
        if(head->next == nullptr){
            return nullptr;
        }
        int count = 1;
        while(currentNode->next != nullptr){
            count ++;
            currentNode = currentNode->next;
        }
        currentNode = head;
        while(count - n > 1){
            currentNode = currentNode->next;
            count --;
        }
        if(count - n == 0){
            head = head->next;
            return head;
        }
        currentNode->next = currentNode->next->next;
        return head;
    }
};


// Local Testing
int main() {
    Solution solution;
    cout << "Compiled successfully!" << endl;
    return 0;
}
