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
    int sumNumbers(TreeNode* root) {
        return sumH(root,0);
    }
    
    int sumH(TreeNode* root,int curr){
        if(root==NULL) return 0;
        int sumTillHere = curr*10 + root->val;
        if(root->left==NULL && root->right==NULL)
            return sumTillHere;
        return sumH(root->left,sumTillHere) + sumH(root->right,sumTillHere);
    }
};