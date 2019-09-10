class Solution {
public:
    int DFS(vector<vector<int>> &dp, int left, int right){
        if(left >= right) return 0;
        if(dp[left][right]) return dp[left][right];
        int ans = INT_MAX;
        for(int i = left; i <= right; i++)
            ans = min(ans, i + max(DFS(dp, left, i-1), DFS(dp, i+1, right)));
        return dp[left][right]=ans;
    }
    
    int getMoneyAmount(int n) {
        if(n ==0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return DFS(dp, 1, n);
    }
};