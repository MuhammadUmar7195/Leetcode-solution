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

// Recursive Approach TC O(H) SC O(H) 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q){
            return nullptr;
        }
        if(max(p->val, q->val) < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }else if(min(p->val, q->val) > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }else {
            return root;
        }
    }
};

// Iterative Approach TC O(H) SC O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;

        while (cur) {
            if (p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            } else if (p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            } else {
                return cur;
            }
        }
        return nullptr;
    }
};

