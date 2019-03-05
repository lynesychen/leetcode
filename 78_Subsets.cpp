class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        vector<int> sub;
        for(int i=0;i<=n;++i){
            find(i,n,nums,sub,res);
        }
        return res;
    }
    
    void find(int curr,int n,vector<int> &nums,vector<int> &sub,vector<vector<int>> &res){
        if(curr==n){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[curr]);
        for(int i=curr+1;i<=n;++i){
            find(i,n,nums,sub,res);
        }
        sub.pop_back();
    }
};