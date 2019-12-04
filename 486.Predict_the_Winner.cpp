class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int> > dp(n, vector<int>(n)); // sum from left to right 
        for(int i=0; i<n;++i)
            dp[i][i] = nums[i];
        
        vector<int> nsum(n,0); // sum from index 0 to index i
        
        nsum[0] = nums[0];
        for(int i=0;i<n-1;++i)
            nsum[i+1]=nsum[i]+nums[i+1];
        
        for(int len=1;len<n;++len)//len
            for(int j=0;j+len<n;++j)//begin_idx
                dp[j][j+len]=max(nsum[j+len]-nsum[j]+nums[j]-dp[j+1][j+len], nsum[j+len]-nsum[j]+nums[j]-dp[j][j+len-1]);
        return dp[0][n-1]>=nsum[n-1]/2.0;
    }
};
