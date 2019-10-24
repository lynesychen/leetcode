class Solution {
public:
    bool judge(int i, int j, int n, int m, vector<vector<int>> &mark){
        if(i<0||j<0||i>=n||j>=m)return false;
        if(mark[i][j]==1)return false;
        return true;
    }
    bool judge2(int i, int j, int n, int m, vector<vector<int>> &mark){
        if(i<0||j<0||i>=n||j>=m)return false;
        if(mark[i][j]==2)return false;
        return true;
    }
        void dfs2(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &mark, int &n, int &m, vector<int> &tmp, vector<vector<int>> &result){
        if(judge2(row-1, col, n,m,mark)&&matrix[row-1][col]>=matrix[row][col]){
            if(mark[row-1][col]==1){
                tmp[0]=row-1;
                tmp[1]=col;
                result.push_back(tmp);
            }
            mark[row-1][col]=2;
            dfs2(row-1, col, matrix, mark, n, m, tmp, result);
        }
        if(judge2(row+1, col, n,m,mark)&&matrix[row+1][col]>=matrix[row][col]){
            if(mark[row+1][col]==1){
                tmp[0]=row+1;
                tmp[1]=col;
                result.push_back(tmp);
            }
            mark[row+1][col]=2;
            dfs2(row+1, col, matrix, mark, n, m, tmp, result);
        }
        if(judge2(row, col-1, n,m,mark)&&matrix[row][col-1]>=matrix[row][col]){
            if(mark[row][col-1]==1){
                tmp[0]=row;
                tmp[1]=col-1;
                result.push_back(tmp);
            }
            mark[row][col-1]=2;
            dfs2(row, col-1, matrix, mark, n, m, tmp, result);
        }
        if(judge2(row, col+1, n,m,mark)&&matrix[row][col+1]>=matrix[row][col]){
            if(mark[row][col+1]==1){
                tmp[0]=row;
                tmp[1]=col+1;
                result.push_back(tmp);
            }
            mark[row][col+1]=2;
            dfs2(row, col+1, matrix, mark, n, m, tmp, result);
        }
    }
    void dfs(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &mark, int &n, int &m){
        //cout<<row<<" "<<col<<" "<<matrix[row][col]<<endl;
        if(judge(row-1, col, n,m,mark)&&matrix[row-1][col]>=matrix[row][col]){
            mark[row-1][col]=1;
            dfs(row-1, col, matrix, mark, n, m);
        }
        if(judge(row+1, col, n,m,mark)&&matrix[row+1][col]>=matrix[row][col]){
            mark[row+1][col]=1;
            dfs(row+1, col, matrix, mark, n, m);
        }
        if(judge(row, col-1, n,m,mark)&&matrix[row][col-1]>=matrix[row][col]){
            mark[row][col-1]=1;
            dfs(row, col-1, matrix, mark, n, m);
        }
        if(judge(row, col+1, n,m,mark)&&matrix[row][col+1]>=matrix[row][col]){
            mark[row][col+1]=1;
            dfs(row, col+1, matrix, mark, n, m);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int> > result;
        int n = matrix.size();
        if(n<1)
            return result;
        int m = matrix[0].size();
        vector<vector<int> > mark(n, vector<int>(m));
        vector<int> tmp(2);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(i==0||j==0){
                    mark[i][j]=1;
                    dfs(i, j, matrix, mark, n, m);
                }
            }
        }
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                if(i==n-1||j==m-1){
                    if(mark[i][j]==1){
                        tmp[0]=i;
                        tmp[1]=j;
                        result.push_back(tmp);
                    }
                    mark[i][j]=2;
                    dfs2(i, j, matrix, mark, n, m, tmp, result);
                }
            }
        }
        return result;
    }
};
