#include <vector> // Necessário para std::vector

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* buildFromVector(std::vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;     
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildFromVector(nums, start, mid - 1);
        root->right = buildFromVector(nums, mid + 1, end);       
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        std::vector<int> sortedValues;
        ListNode* current = head;
        while (current != nullptr) {
            sortedValues.push_back(current->val);
            current = current->next;
        }
        return buildFromVector(sortedValues, 0, sortedValues.size() - 1);
    }
};