class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff, res, dist;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if ((i>0) && (nums[i]==nums[i-1]))continue;
            int l = i+1, r = nums.size()-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > target) dist = sum - target;
                else    dist = target - sum;
                if(i==0 && l==i+1 && r == nums.size()-1){
                    diff = dist;
                    res = sum;
                }
                if(dist < diff){
                    diff = dist;
                    res = sum;
                }
                if(sum < target)  l++;
                else if(sum > target)   r--;
                else return sum;
            }
        }
        return res;
    }
};