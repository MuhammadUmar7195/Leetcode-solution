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

// Recursive Approach TC: O(N) SC: O(N)
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        postorder(root, res);
        return res;
    }

private:
    void postorder(TreeNode *node, vector<int> &result)
    {
        if (node == nullptr)
            return;

        postorder(node->left, result);
        postorder(node->right, result);
        result.push_back(node->val);
    }
};

// Iterative Approach TC: O(N) SC: O(N)
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (curr || !st.empty())
        {
            if (curr)
            {
                res.push_back(curr->val);
                st.push(curr);
                curr = curr->right;
            }
            else
            {
                curr = st.top();
                st.pop();
                curr = curr->left;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};