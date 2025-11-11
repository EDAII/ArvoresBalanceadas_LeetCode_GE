#include <string>
#include <sstream> // Para ostringstream e stringstream
#include <queue>   // Para std::queue
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void buildString(TreeNode* node, ostringstream& out) {
        if (node == NULL) {
            out << "N,";
            return;
        }
        out << node->val << ",";
        buildString(node->left, out);
        buildString(node->right, out);
    }

    TreeNode* buildTree(queue<string>& q) {
        string val = q.front();
        q.pop();

        if (val == "N") {
            return NULL;
        }

        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(q);
        node->right = buildTree(q);
        return node;
    }

public:
    string serialize(TreeNode* root) {
        ostringstream out;
        buildString(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            if (!token.empty()) {
                q.push(token);
            }
        }

        if (q.empty()) {
            return NULL;
        }
        
        return buildTree(q);
    }
};