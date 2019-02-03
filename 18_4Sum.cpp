class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> tt(4,0);
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n-2;++j){
                int tmp=target-nums[i]-nums[j];
                int l=j+1,r=n-1;
                while(l<r){
                    if(nums[l]+nums[r]>tmp)--r;
                    else if(nums[l]+nums[r]<tmp)++l;
                    else{
                        tt[0]=nums[i];tt[1]=nums[j];tt[2]=nums[l];tt[3]=nums[r];
                        res.push_back(tt);
                        --r;++l;
                    }
                }
            }
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};