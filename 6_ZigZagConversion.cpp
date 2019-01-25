class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (len <= 2 || len <= numRows || numRows <= 1) return s;
        
        int step = 2 * numRows - 2;
        string res;
        for (int i=0; i<numRows; i++) {
            int round = 0;
            while (step * round + i < len) {
                res += s[step * round + i];
                if (i != 0 && i != numRows - 1 && (step * (round+1) - i)<len) {
                    res += s[step * (round+1) - i];
                }

                round++;
            }
        }
        
        return res;
    }
};