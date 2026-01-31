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

// Recursive Approach TC: O(N^2) SC: O(H)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(abs(rightHeight - leftHeight) > 1)  
            return false;
                
        return isBalanced(root->left) && isBalanced(root->right);
    }
private: 
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
};

// Optimized Recursive Approach TC: O(N) SC: O(H) => DFS
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }

private:
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {1, 0};
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        bool balanced = (left[0] == 1 && right[0] == 1) &&
                        (abs(left[1] - right[1]) <= 1);
        int height = 1 + max(left[1], right[1]);

        return {balanced ? 1 : 0, height};
    }
};