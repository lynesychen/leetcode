class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        for(int i=0;i<n;++i){
            if(i>0&&i<n-1&&nums[i]!=nums[i-1]&&nums[i]!=nums[i+1])
                res.push_back(nums[i]);
            else if(i==0&&nums[i]!=nums[i+1])
                res.push_back(nums[i]);
            else if(i==n-1&&nums[i]!=nums[i-1])
                res.push_back(nums[i]);
        }
        return res;
    }
};