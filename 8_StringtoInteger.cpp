class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0)
			return 0;
		stringstream ss(str);
        int x =0;
        ss>>x;
        return x;
    }
};