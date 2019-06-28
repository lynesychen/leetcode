class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin()+nums.size()/2, nums.end()); 
        int len = nums.size(), low = 0, high = len - 1, mid = nums[len/2], i = 0;  
        auto index = [=](int pos){ return (1 + pos * 2) % (len |1 ); };  
        while(i <= high) {  
            if(nums[index(i)] > mid) swap(nums[index(i++)], nums[index(low++)]);
            else if(nums[index(i)] < mid) swap(nums[index(i)],nums[index(high--)]);
            else ++i;
        }  
    }
};