class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0);
        int n = p.length();
        int cnt = 0;
        for(int i=0; i<n; ++i){
            if (i>0&&(p[i]-p[i-1]==1 || p[i]-p[i-1]==-25)){
                ++cnt;
            }else{
                cnt=1;
            }
            dp[p[i]-'a'] = max(dp[p[i]-'a'], cnt);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

