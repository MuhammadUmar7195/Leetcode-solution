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

// Recursive solution using DFS TC: O(n) SC: O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
private:
    bool valid(TreeNode* node, long left, long right){
        if(!node) return true;

        if(!(left < node->val && right > node->val)){
            return false;
        }

        return valid(node->left, left, node->val) && 
            valid(node->right, node->val, right);
    }
};

// Iterative solution using BFS TC: O(n) SC: O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        queue<tuple<TreeNode*, long, long>> queue;
        queue.push(make_tuple(root, LONG_MIN, LONG_MAX));

        while (!queue.empty()) {
            auto [node, left, right] = queue.front();
            queue.pop();

            if (!(left < node->val && node->val < right)) {
                return false;
            }
            if (node->left) {
                queue.push(make_tuple(node->left, left, node->val));
            }
            if (node->right) {
                queue.push(make_tuple(node->right, node->val, right));
            }
        }

        return true;
    }
};