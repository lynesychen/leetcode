class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty()) return false;
        if(matrix[0].empty()) return false;
        int l = matrix.size();
        int j = matrix[0].size()-1;
        int i = 0;
        while (i<l&& j>=0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};