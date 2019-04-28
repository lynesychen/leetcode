/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> arr;
    int index;
    BSTIterator(TreeNode* root) {
        arr.clear();
        index=0;
        if(root==NULL)return;
        inorder(root);
    }
    
    void inorder(TreeNode *root){
        if(root->left!=NULL)inorder(root->left);
        arr.push_back(root->val);
        if(root->right!=NULL)inorder(root->right);
    }
    
    /** @return the next smallest number */
    int next() {
        return arr[index++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index<arr.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */