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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root); q.push(root);
        while(!q.empty())
        {
            auto x = q.front(); q.pop();
            auto y = q.front(); q.pop();
            if ((x&&y) && (x->val!=y->val)) return false;
            if ((x && !y) || (y && !x)) return false;
            if (!x && !y) continue;
            q.push(x->left);
            q.push(y->right);
            q.push(x->right);
            q.push(y->left);
        }
        return true;
    }
};
