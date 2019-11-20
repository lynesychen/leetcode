class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return 0;
        int res=0;
        sort(nums.begin(), nums.end());
        int mid = nums[n/2];
        for(int i = 0; i < n; ++i)res+=abs(nums[i]-mid);
        return res;
    }
};
