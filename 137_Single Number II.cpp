class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            ones = ones ^ nums[i] & twos;
            twos = twos ^ nums[i] & ones;
        }
        return ones;
    }
};