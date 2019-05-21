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
    int countNodes(TreeNode* root) {
        int res = 0;
        countNode(root, res);
        return res;
    }
    void countNode(TreeNode *root, int &res){
        if(root==NULL)return;
        res+=1;
        if(root->left!=NULL)countNode(root->left,res);
        if(root->right!=NULL)countNode(root->right,res);
    }
};