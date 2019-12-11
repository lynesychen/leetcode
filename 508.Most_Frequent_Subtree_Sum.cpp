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
    unordered_map<int, int> cnt;
    int dfs(TreeNode* root){
        int sum=root->val;
        if(root->left!=NULL) sum+=dfs(root->left);
        if(root->right!=NULL) sum+=dfs(root->right);
        cnt[sum]+=1;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root!=NULL)dfs(root);
        int fre=0;
        vector<int> res;
        for(auto it:cnt){
            if(it.second>fre){
                fre=it.second;
                res.clear();
                res.push_back(it.first);
            }else if(it.second==fre){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
