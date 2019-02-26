class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(n, vector(m,0)); 
        if(m <= 1 && n <= 1)return m & n;
        return uniquePaths(0, 0, m , n, memo);
    }
    
    int uniquePaths(int startr, int startc, int cols, int rows, vector<vector<int>>& memo) {
        if(memo[startr][startc] != 0) return memo[startr][startc];
        int res = 0;
        if((startr == rows-1 && startc == cols-2) || (startr == rows-2 && startc == cols-1))  
            res = 1; 
        else{ 
            int right = (startc != cols-1)? uniquePaths(startr, startc+1, cols , rows, memo) : 0;
            int down = (startr != rows-1)? uniquePaths(startr+1, startc, cols , rows, memo) : 0;
            res = right + down;
        }
        memo[startr][startc] = res;
        return res;
    }
};