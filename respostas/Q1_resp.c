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
#include <vector> 

class Solution {
private:
    std::vector<int> sortedValues;
    void inOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inOrderTraversal(node->left);
        sortedValues.push_back(node->val);
        inOrderTraversal(node->right);
    }
    TreeNode* buildBalancedBST(int start, int end) {

        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;     
        TreeNode* root = new TreeNode(sortedValues[mid]);
        root->left = buildBalancedBST(start, mid - 1);       
        root->right = buildBalancedBST(mid + 1, end);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        inOrderTraversal(root);
        return buildBalancedBST(0, sortedValues.size() - 1);
    }
};