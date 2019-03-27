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
    vector<vector<int>> result;
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
        vector<int> tmp;
        if(root!=NULL)solve(root,sum,tmp);
        return result;
    }
    
    void solve(TreeNode* root,int sum,vector<int> tmp){
        //if(sum<0)return;
        tmp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&root->val==sum){
            result.push_back(tmp);
            tmp.pop_back();
            return;
        }
        if(root->left!=NULL)solve(root->left,sum-root->val,tmp);
        if(root->right!=NULL)solve(root->right,sum-root->val,tmp);
        tmp.pop_back();
    }
};