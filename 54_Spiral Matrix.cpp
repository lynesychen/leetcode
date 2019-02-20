class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {   
        vector<int> result;
        
        int m = matrix.size();
        if(m == 0) return result;
        int n = matrix[0].size();
        
        int total = m * n;
        int count = 0;
        int i = 0, j = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        result.push_back(matrix[0][0]);
        visited[0][0] = true;
        count = 1;

        while(count != total){           
            bool right = true, down = false, left = false, up = false;
            while(right && j + 1 < n && !visited[i][j + 1]){
                j++;
                result.push_back(matrix[i][j]);
                visited[i][j] = true;
                count++;
            }

            right = false;  down = true;

            while(down && i + 1 < m && !visited[i + 1][j]){
                i++;
                result.push_back(matrix[i][j]);
                visited[i][j] = true;
                count++;
            }

            down = false;   left = true;
            
            while(left && j - 1 >= 0 && !visited[i][j - 1]){
                j--;
                result.push_back(matrix[i][j]);
                visited[i][j] = true;
                count++;
            }

            down = false;   up = true;

            while(up && i - 1 > 0 && !visited[i - 1][j]){
                i--;
                result.push_back(matrix[i][j]);
                visited[i][j] = true;
                count++;
            }            
        }

        return result;
    }
};