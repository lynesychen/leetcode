class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        if(n<1)return res;
        int m = matrix[0].size();
        int i=0,j=0;
        //顺序　右上->左下
        int turn=0;
        while(i!=n-1||j!=m-1){
            res.push_back(matrix[i][j]);
            switch(turn){
                case 0:
                    if(i>0&j<m-1){
                        ++j;--i;
                    }else if(j<m-1){
                        ++j;
                        turn=1;
                    }else{
                        ++i;
                        turn=1;
                    }
                    break;
                case 1:
                    if(i<n-1&&j>0){
                        i++;--j;
                    }else if(i<n-1){
                        ++i;
                        turn=0;
                    }else{
                        ++j;
                        turn=0;
                    }
            }
        }
        res.push_back(matrix[n-1][m-1]);
        return res;
    }
};
