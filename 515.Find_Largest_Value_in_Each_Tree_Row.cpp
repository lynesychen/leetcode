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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root==NULL)return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            queue<TreeNode*> p;
            int maxval=q.front()->val;
            while(!q.empty()){
                TreeNode* node = q.front();
                q.pop();
                maxval=max(maxval, node->val);
                if(node->left!=NULL)p.push(node->left);
                if(node->right!=NULL)p.push(node->right);
            }
            res.push_back(maxval);
            swap(p,q);
        }
        return res;
    }
};
