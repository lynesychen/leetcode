class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        string ss=s;
        reverse(ss.begin(), ss.end());
        if(s==ss)return len;
        vector<vector<int>> dp(len, vector<int>(len, 1));  // left to right 
        for(int i=1; i<len; ++i){
            if(s[i]==s[i-1])
                dp[i-1][i]=2;
            for(int j=i-2; j>=0; --j){
                if(s[j]==s[i])
                    dp[j][i] = dp[j+1][i-1] + 2;
                else dp[j][i]=max(dp[j+1][i], dp[j][i-1]);
            }
        }
        return dp[0][len-1];
    }
};
