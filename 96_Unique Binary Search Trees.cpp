class Solution {
public:
    int numTrees(int n) {
	    vector<int> t(n + 1, 0);
	    t[0] = t[1] = 1;
        
	    for (int i = 2; i <= n; ++i){
		    for (int j = 1; j <= i / 2; ++j)
			    t[i] += t[j - 1] * t[i - j];
		    t[i] *= 2;
		    if (i % 2)
			    t[i] += t[i / 2] * t[i / 2];
	    }
        
	    return t[n];
    }
};