class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int high_index = INT_MIN, high = INT_MIN;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] >= high) {
                high = nums[i];
                high_index = i;
            }
        stack<int> s;
        vector<int> ans(nums.size());
        int i = high_index;
        do{
            while(!s.empty() && nums[i] >= s.top()) s.pop();
            if(s.empty()) ans[i] = -1;
            else ans[i] = s.top();
            s.push(nums[i]);
            i--;
            if(i < 0) i = nums.size() - 1; 
        }
        while(i != high_index);
        return ans;
    }
};
