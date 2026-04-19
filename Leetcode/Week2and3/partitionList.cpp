/*
 * Problem: 86. Partition List
 * Link: https://leetcode.com/problems/partition-list/
 * Difficulty: Medium
 * 
 * Description:
 * Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x. You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * Time Complexity: O(N) where N is the number of nodes in the linked list, since each node is visited once.
 * Space Complexity: O(1) as lists are partitioned locally using pointers.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* low = nullptr;
        ListNode* high = nullptr;
        ListNode* lowCurr = nullptr;
        ListNode* highCurr = nullptr;
        ListNode* next = nullptr;
        while(head){
            next = head -> next;
            head -> next = nullptr;
            if(head -> val < x){
                if(low){
                    lowCurr -> next = head;
                    lowCurr = lowCurr -> next;
                } else {
                    low = head;
                    lowCurr = low;
                }
            } else {
                if(high){
                    highCurr -> next = head;
                    highCurr = highCurr -> next;
                } else {
                    high = head;
                    highCurr = high;
                }
            }
            head =  next;
        }
        if(lowCurr){
            lowCurr -> next = high;
        }
        if(low){
            return low;
        } else {
            return high;
        }
    }
};


// Local Testing
int main() {
    Solution solution;
    cout << "Compiled successfully!" << endl;
    return 0;
}
