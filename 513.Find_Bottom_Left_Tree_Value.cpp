/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res= root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            res = q.front()->val;
            queue<TreeNode*> p;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL)p.push(node->left);
                if(node->right!=NULL)p.push(node->right);
            }
            swap(p, q);
        }
        return res;
    }
};
