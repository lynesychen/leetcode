class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        //vector<int> v(n+1,0);
        vector<int> res;
        for(auto c:nums){
            nums[abs(c)-1]=-nums[abs(c)-1];
            if(nums[abs(c)-1]>0){
                res.push_back(abs(c));    
            }
        }
        return res;
    }
};
