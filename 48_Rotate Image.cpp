class Solution {
public:
    void RotateNinetyDegrees(int& a,int& b,int& c,int& d){
        swap(a,b);
        swap(a,d);
        swap(c,d);
	}  
		   
    void rotate(vector<vector<int>>& matrix) {
        int size=matrix.size();
        for(int i=0;i<(size+1)/2;++i)
            for(int j=i;j<size-1-i;++j)  
                RotateNinetyDegrees(matrix[i][j],matrix[j][size-1-i],matrix[size-1-i][size-1-j],matrix[size-1-j][i]);   
    }
};