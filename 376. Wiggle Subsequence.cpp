class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return n;
        if(n==2){
            if(nums[0]==nums[1])return 1;
            return 2;
        }
        int res = 1;
        int note = 0, tmplen=1;
        for(int i=1;i<n;++i){
            if(nums[i] > nums[i-1]&&note!=1){
                note = 1;
                tmplen++;
                res = max(res,tmplen);
            }else if(nums[i] < nums[i-1]&&note!=-1){
                note = -1;
                tmplen++;
                res = max(res,tmplen);
            }
        }
        return res;
    }
};