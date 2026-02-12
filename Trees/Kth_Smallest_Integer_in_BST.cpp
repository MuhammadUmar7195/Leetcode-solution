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


// Recursive Approach TC: O(H + k) SC: O(H)
class Solution {
public:
    int prevOrder = 0;
    
    int kthSmallest(TreeNode* root, int k) {

        if(!root) return -1;

        //left ma check krna ha according to inorder traversal
        if(root->left != NULL){
            int leftAns = kthSmallest(root->left, k);
            if(leftAns != -1)
                return leftAns;
        }

        // Now root level jo check krna ha
        if(prevOrder + 1 == k){
            return root->val;
        }
        prevOrder = prevOrder + 1;

        //right ma check krna ha according to inorder traversal
        if(root->right != NULL){
            int rightAns = kthSmallest(root->right, k);
            if(rightAns != -1)
                return rightAns; 
        }

        return -1;
    }
};

//Iterative Approach TC: O(H + k) SC: O(H)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        TreeNode* curr = root;

        while (!stack.empty() || curr != nullptr) {
            while (curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            k--;
            if (k == 0) {
                return curr->val;
            }
            curr = curr->right;
        }

        return -1;
    }
};