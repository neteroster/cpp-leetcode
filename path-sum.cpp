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
class Solution { // O(n) & BFS & 层次遍历
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        queue<TreeNode*> s;
        s.push(root);


        while(!s.empty())
        {
            TreeNode* x = s.front();
            s.pop();

            if (x->val == targetSum && isLeaf(x)) return true; 
            if (x->right) s.push(x->right), x->right->val += x->val;
            if (x->left) s.push(x->left), x->left->val += x->val;
        }
        return false;
    }
    bool isLeaf(TreeNode* node)
    {
        return !node->left && !node->right;
    }
};
