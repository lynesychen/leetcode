class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (!len)return 0;
        int j = 1;
        int md = 1;
        int dv = nums[0];
        int mv = dv;
        for (int i = 1; i < len; i++) {
            if (nums[i] < mv)continue;
            if (md == 2 && mv == nums[i])continue;
            if (mv < nums[i]) {
                md = 1;
                mv = nums[i];
                swap(nums[i], nums[j]);
                j++;
            } else {
                md ++;
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return j;
    }

};