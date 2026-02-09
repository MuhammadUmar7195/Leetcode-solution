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

// Using DFS to count good nodes TC: O(n) SC: O(n)
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return helperNode(root, 0, INT_MIN);
    }
private:
    int helperNode(TreeNode* node, int ans, int currMax){
        if(!node) return 0;

        int rootAnswer = 0;
        if(node->val >= currMax){
            rootAnswer = 1;
            currMax = node->val;
        }

        int leftAnswer = helperNode(node->left, ans, currMax);
        int rightAnswer = helperNode(node->right, ans, currMax);

        return leftAnswer + rightAnswer + rootAnswer;
    }
};

// Using BFS to count good nodes TC: O(n) SC: O(n)
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, -INT_MAX});

        while (!q.empty()) {
            auto [node, maxval] = q.front();
            q.pop();
            if (node->val >= maxval) {
                res++;
            }
            if (node->left) {
                q.push({node->left, max(maxval, node->val)});
            }
            if (node->right) {
                q.push({node->right, max(maxval, node->val)});
            }
        }
        return res;
    }
};
