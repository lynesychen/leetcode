class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),target,i = n-1,j,k;
        vector<vector<int>> ans;
        while(i >= 2){
            target = -nums[i];
            j = 0;
            k = i-1;
            while(j < k){
                int temp = nums[j]+nums[k];
                if(temp < target) j++;
                else if(temp > target) k--;
                else{
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    ans.push_back(v);
                    j++;
                    k--;
                    while(j < k && nums[j-1] == nums[j])j++;
                    while(j < k && nums[k+1] == nums[k])k--;
                }
            }
            i--;
            while(nums[i+1]==nums[i])i--;
        }
        return ans;
    }
};