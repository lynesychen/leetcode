class Solution {
public:
    int factorial(int n){
        if (n <= 1) return 1;
        return n = n * factorial(n-1);
    }
    string getPermutation(int n, int k) {
        string res;
        string t;
        for (int i = 1; i <= n; ++i){
            t += (i + 48);
        }
        int flag;
        int flag_;
        for (int i = 0; i < (n-1); ++i){
            k = k % factorial(n-i) == 0 ? factorial(n-i) : k % factorial(n-i);
            flag = k / factorial(n-i-1);
            flag_ = k % factorial(n-i-1);
            int index = flag_ == 0 ? flag - 1 :flag; 
            res += t[index];
            t.replace(index,1,"");
        }
        res += t[0];
        return res;
    }
};