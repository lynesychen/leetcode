class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count=0;
        
        for(int i=0;i<31;i++){
            int x=1<<i;
            int tmp=0;
            for(int j=0;j<nums.size();j++){
                if((x&nums[j])==0) tmp++;
            }
            count+=tmp*(nums.size()-tmp);
        }
        return count;
    }
};
