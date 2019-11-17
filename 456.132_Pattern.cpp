class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;
        int inf = 0x3f3f3f3f;
        int two= -inf;
        int three = -inf;
        int three_2 = -inf;
        for(int i = n - 1; i >= 0; --i){
            if(nums[i]>two){
                if(two>three){
                    three = two;
                    three_2 = two;
                }
                two = nums[i];
            }
            else if(nums[i] == two){
                three = three_2;
            }else if(nums[i]>three_2){
                three = three_2;
                three_2 = nums[i];
            }else if(nums[i] < three && two>three){
                return true;
            }
        }
        return false;
    }
};

