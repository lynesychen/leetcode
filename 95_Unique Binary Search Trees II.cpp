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
        vector<TreeNode*> generateTrees(int n) {
            vector<TreeNode *> res;
            if(n>0)
                res.push_back(nullptr);
            for(int i=1;i<=n;i++) {
                vector<TreeNode *> temp;
                int sz=res.size();
                for(int j=0;j<sz;j++) {
            	    TreeNode *oldT=res[j],*subr=oldT;
				    TreeNode *newTree=new TreeNode(i);
				    newTree->left=oldT;
                    res[j]=newTree;
                    TreeNode tnode(i);
				    while(subr) {
                        TreeNode *rchild=subr->right,*newnode=&tnode;
                        newnode->left=rchild;
                        subr->right=newnode;
                        res.push_back(CloneTree(oldT));
                        subr->right=rchild;
                        subr=subr->right;
				    }
                }
            }
		    return res;
        }
        TreeNode *CloneTree(TreeNode *root) {
            if(!root)
                return nullptr;
            TreeNode *newR=new TreeNode(root->val);
            newR->left=CloneTree(root->left);
            newR->right=CloneTree(root->right);
            return newR;
        }
};