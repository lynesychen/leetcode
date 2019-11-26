class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int nn = strs.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1,0));
        for(int i=0;i<nn;++i){
            int count1=0,count0=0;
            string ss = strs[i];
            for(auto c:ss){
                if (c=='0'){
                    count0++;
                }
            }
            count1=ss.length()-count0;
            for(int j=m;j>=count0;j--){
                for(int k=n;k>=count1;k--){
                    dp[j][k] = max(dp[j][k], dp[j-count0][k-count1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
