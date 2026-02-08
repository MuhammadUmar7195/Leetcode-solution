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

// Recursivly Approach Tc: O(N) Sc: O(H) => DFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int depth, vector<int>& res){
        if(!node) return;

        if(depth == res.size()){
            res.push_back(node->val);
        }

        dfs(node->right, depth + 1, res);
        dfs(node->left, depth + 1, res);
    }
};

// Iteratively Approach Tc: O(N) Sc: O(N) => BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int levelSize = q.size();
            
            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // If this is the last node of the current level
                if(i == levelSize - 1) {
                    res.push_back(node->val);
                }
                
                // Add child nodes for the next level
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        
        return res;
    }
};