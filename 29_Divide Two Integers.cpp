class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res=(long long)dividend/(long long)divisor;
        if(res!=(int)res)return pow(2,31)-1;
        return res;
    }
};