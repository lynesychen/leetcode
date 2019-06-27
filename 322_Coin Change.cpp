class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 1)
            return (amount%coins[0]!=0?-1:amount/coins[0]);
        vector<int> dp(amount + 1, 0x3f3f3f3f);
        dp[amount] = 0;
        for(int i = n - 1; i >= 0; --i)
            for(int j = amount; j - coins[i] >= 0; --j)
                dp[j - coins[i]] = min(dp[j] + 1, dp[j - coins[i]]);
        return (dp[0]==0x3f3f3f3f?-1:dp[0]);
    }
};
