class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        std::vector<std::vector<long int>> table (m+1, std::vector<long int> (n+1, 0));
        
        for(int i = 1; i < m+1; ++i) {
            for(int j = 1; j < n+1; ++j) {
                if(obstacleGrid[i-1][j-1] == 1) { 
                    table[i][j] = -1;
                    continue;
                } else if(table[i-1][j] == -1 && table[i][j-1] == -1) { 
                    table[i][j] = -1;
                    continue;
                }
                else if(table[i-1][j] == -1) {
                    if(table[i][j-1] == 0) {
                        table[i][j] = -1;
                        continue;
                    }
                    table[i][j] = table[i][j-1] > 1 ? table[i][j-1] : 1;   
                }
                else if(table[i][j-1] == -1) {
                    if(table[i-1][j] == 0) {
                        table[i][j] = -1;
                        continue;
                    }
                    table[i][j] = table[i-1][j] > 1 ? table[i-1][j] : 1;
                }
                else {
                    table[i][j] = table[i-1][j] + table[i][j-1] > 1 ? table[i-1][j] + table[i][j-1] : 1;     
                } 
            }
        }
        
        return table[m][n] > 0 ? table[m][n] : 0;
    }
};