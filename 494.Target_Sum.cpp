// 4ms 8.7MB
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long long sum = 0;
        for(int num : nums) sum += num;
        int target = sum + S;
        if (sum < S || target % 2 == 1){
             return 0;
        }
        target/=2;
        vector<int> dp( target + 1,0);
        dp[0] = 1;
        for(int num : nums)
            for(int i = target; i >= num; --i){
                dp[i] += dp[i-num];
            } 
        return dp[target];
    }
};

//204ms 47.6MB
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//         int n = nums.size();
//         unordered_map<long long, int> m1;
//         m1[0]=1;
//         for(int i=0;i<n;++i){
//            unordered_map<long long, int> m2;
//             for(auto it: m1){
//                 m2[it.first+nums[i]] = m2[it.first+nums[i]]+m1[it.first];
//                 m2[it.first-nums[i]] = m2[it.first-nums[i]]+m1[it.first];
//             }
//             m1 = m2;
//         }
//         return m1[S];
//     }
// };

// 404ms 8.5MB
// class Solution {
// public:
//     int cnt;
//     void dfs(long long target, int idx, vector<int> &sum, vector<int> &nums, int n){
//         if(idx==n){
//             if(target==0)++cnt;
//             return;
//         }
//         if(target>sum[n-1]-sum[idx-1])return;
//         if(target<-(sum[n-1]-sum[idx-1]))return;
//         dfs(target-nums[idx],idx+1,sum,nums,n);
//         dfs(target+nums[idx],idx+1,sum,nums,n);
//     }
//     int findTargetSumWays(vector<int>& nums, int S) {
//         int n = nums.size();
//         vector<int> sum(n,0);
//         sum[0]=nums[0];
//         for(int i=0;i<n-1;++i)
//             sum[i+1] = sum[i] + nums[i+1];
//         if (sum[n-1] < S || (sum[n-1]+S) % 2 == 1){
//              return 0;
//         }
//         cnt=0;
//         if(n>=1){
//             dfs((long long)S-nums[0], 1, sum, nums, n);
//             dfs((long long)S+nums[0], 1, sum, nums, n);
//         }
//         return cnt;
//     }
// };

