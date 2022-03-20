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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> s;
        s.push(root);


        int now_node_num = 1;
        int now = 0;
        int depth = 1;
        int next_node_num = 0;
        while(!s.empty())
        {
            auto x = s.front();
            s.pop();

            now++;
            
            
            if (x->left) s.push(x->left), next_node_num++;
            if (x->right) s.push(x->right), next_node_num++;
            if (!x->left && !x->right) return depth;
            if (now == now_node_num)
            {
                now_node_num = next_node_num;
                next_node_num = 0;
                now = 0;
                depth++;

            }
        }
        return -1;
    }
};
