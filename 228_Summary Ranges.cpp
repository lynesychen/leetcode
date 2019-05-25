class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> result;
        if(n<1)return result;
        int be=nums[0],des=nums[0];
        for(int i=1;i<n;++i){
            if(nums[i]==nums[i-1]+1){
                des=nums[i];
            }else{
                if(be==des)result.push_back(""+to_string(des));
                else result.push_back(to_string(be)+"->"+to_string(des));
                be=nums[i];des=nums[i];
            }
        }
        if(be==des)result.push_back(""+to_string(des));
        else result.push_back(to_string(be)+"->"+to_string(des));
        return result;
    }
};