/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Recursion Approach with TC O(h) and SC O(n)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;

        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else if(root->val >key){
            root->left = deleteNode(root->left, key);
        }else {
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            TreeNode* curr = root->right;
            while(curr->left){
                curr = curr->left;
            }
            curr->left = root->left;
            TreeNode* res = root->right;
            delete root;
            return res;
        }

        return root;
    }
};

//// Iterative Approach with TC O(h) and SC O(1)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        TreeNode* parent = nullptr;
        TreeNode* cur = root;

        // Find the node to delete
        while (cur && cur->val != key) {
            parent = cur;
            if (key > cur->val) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }

        if (!cur) return root;

        // Node with only one child or no child
        if (!cur->left || !cur->right) {
            TreeNode* child = cur->left ? cur->left : cur->right;
            if (!parent) return child;
            if (parent->left == cur) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            // Node with two children
            TreeNode* par = nullptr; // parent of right subtree's min node
            TreeNode* delNode = cur;
            cur = cur->right;
            while (cur->left) {
                par = cur;
                cur = cur->left;
            }

            if (par) { // if there was a left traversal
                par->left = cur->right;
                cur->right = delNode->right;
            }
            cur->left = delNode->left;

            if (!parent) return cur; // if deleting root

            if (parent->left == delNode) {
                parent->left = cur;
            } else {
                parent->right = cur;
            }
        }

        return root;
    }
};