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

// Recursive Approach TC: O(N) SC: O(H) => DFS
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // base case
        if (!p && !q)
            return true;
        // aghr first node present hain or dono ki val
        // same ha toh aghy recursively call kro last ma saab
        // values collect ho kr bolean sol de dein ghy
        if (p && q && p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else
        {
            return false;
        }
    }
};

// Iterative Approach TC: O(N) SC: O(H) => BFS
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);

        while (!q1.empty() && !q2.empty()) {
            for (int i = q1.size(); i > 0; i--) {
                TreeNode* nodeP = q1.front(); q1.pop();
                TreeNode* nodeQ = q2.front(); q2.pop();

                if (!nodeP && !nodeQ) continue;
                if (!nodeP || !nodeQ || nodeP->val != nodeQ->val)
                    return false;

                q1.push(nodeP->left);
                q1.push(nodeP->right);
                q2.push(nodeQ->left);
                q2.push(nodeQ->right);
            }
        }

        return true;
    }
};
