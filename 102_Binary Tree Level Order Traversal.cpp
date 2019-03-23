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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q,p;
        vector<vector<int>> result;
        if(root!=NULL)q.push(root);
        while(!q.empty()){
            vector<int> temp;
            while(!q.empty()){
                TreeNode* head=q.front();
                q.pop();
                temp.push_back(head->val);
                if(head->left!=NULL)p.push(head->left);
                if(head->right!=NULL)p.push(head->right);
            }
            swap(p,q);
            result.push_back(temp);
        }
        
        return result;
    }
};