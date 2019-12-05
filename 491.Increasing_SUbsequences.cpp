class Solution {
public:
    vector<vector<int>> results;
    void dfs(int pre, int ind, int n, vector<int> &path, vector<int> &nums){
        if(path.size()>1){
            results.push_back(path);
        }
        unordered_set<int> hash;
        for(int i=ind;i<n;++i){
            if(hash.find(nums[i])!=hash.end())continue;
            if(nums[i]<pre)continue;
            hash.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums[i], i+1, n, path, nums);
            path.pop_back();
        }
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<int> path;
        dfs(-101, 0, n, path,nums);
        return results;
    }
};
