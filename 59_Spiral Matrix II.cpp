class Solution {
public:
    int fill(vector<vector<int>>& arr, int val, int row, int col, int r, int c, int len) {
	    for (int i = 0; i < len; ++i, row += r, col += c) {
		    arr[row][col] = val++;
	    }
	    return val;
}
    
    vector<vector<int>> generateMatrix(int n) {
	    auto arr = vector<vector<int>>(n, vector<int>(n));
	    int val = 1; // current value to assign
	    int len = n - 1; // num of assignments per swoop (4 for each depth)
	    int depth = 0; // depth of current circle
	    while (len > 0) {
		    int opInd = n - depth - 1; // oposite index
		    val = fill(arr, val, depth, depth,  0,  1, len); // left to right
		    val = fill(arr, val, depth, opInd,  1,  0, len); // top to bottom
		    val = fill(arr, val, opInd, opInd,  0, -1, len); // right to left
		    val = fill(arr, val, opInd, depth, -1,  0, len); // bottom to top
		    len -= 2;
		    ++depth;
	    }
	    if (len == 0) arr[depth][depth] = val;
	    return arr;
    }
};