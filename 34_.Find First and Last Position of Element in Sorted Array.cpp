class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        vector<int> res(2,-1);
        while(l<=r){
            if(nums[l]==target&&nums[r]==target){
                res[0]=l;
                res[1]=r;
                break;
            }
            if(nums[r]>target)r--;
            if(nums[l]<target)++l;
        }
        return res;
    }
};