/*
 * Problem: 109. Convert Sorted List to Binary Search Tree
 * Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * Difficulty: Medium
 * 
 * Description:
 * Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 * 
 * Time Complexity: O(N) where N is the number of nodes in the linked list. We construct the tree efficiently by simulating an inorder traversal.
 * Space Complexity: O(log N) representing the maximum depth of the call stack during the recursive tree construction.
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(int n, ListNode*& current){
        if(n <= 0){
            return NULL;
        }
        TreeNode* left = buildTree(n / 2, current);
        TreeNode* root = new TreeNode(current -> val);
        current = current -> next;
        TreeNode* right = buildTree(n - n/2 - 1, current);
        root -> left = left;
        root -> right = right;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* current = head;
        int count = 0;
        while(head != nullptr){
            count += 1;
            head = head -> next;
        }
        return buildTree(count, current);
    }
};


// Local Testing
int main() {
    Solution solution;
    cout << "Compiled successfully!" << endl;
    return 0;
}
