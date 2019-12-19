class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1]={0};
        dp[0]=1;
        for(int j=0;j<coins.size();j++)
            for(int i=0;i<=amount;i++)
                if(i+coins[j]<=amount)
                    dp[i+coins[j]]+=dp[i];
        return dp[amount];
    }
};
