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
    TreeNode* deleteNode(TreeNode* root, int key){
        if (root == NULL)       return NULL;
        TreeNode** rootiter = &root;
        while ((*rootiter)->val != key){
            rootiter = key < (*rootiter)->val ? &(*rootiter)->left : &(*rootiter)->right;
            if ((*rootiter) == NULL)                
                return root;
        }
        TreeNode* replacement = findReplacement (*rootiter);
        if (replacement == NULL){
            delete (*rootiter);
            (*rootiter) = NULL; 
            return root;
        }
        if (replacement == (*rootiter)->left){
            delete (*rootiter);
            *rootiter = replacement;
        }
        else{
            (*rootiter)->val = replacement->val;
            (*rootiter)->right = deleteNode ((*rootiter)->right, replacement->val);
        }
        return root;
    }
    
    TreeNode* findReplacement (TreeNode* root){
        if (root->right == NULL)
            return root->left; 
        TreeNode* rootiter = root->right;
        while (rootiter->left)
            rootiter = rootiter->left;
        return rootiter;
    }
};
