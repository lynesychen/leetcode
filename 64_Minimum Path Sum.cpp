class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int inf=0x3f3f3f3f;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res (n+1, vector<int> (m+1, 0));
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(i==1&&j==1)res[i][j]=grid[i-1][j-1];
                else if(i==1)res[i][j]=res[i][j-1]+grid[i-1][j-1];
                else if(j==1)res[i][j]=res[i-1][j]+grid[i-1][j-1];
                else res[i][j]=min(res[i-1][j]+grid[i-1][j-1],res[i][j-1]+grid[i-1][j-1]);
            }
        }
        return res[n][m];
    }
};