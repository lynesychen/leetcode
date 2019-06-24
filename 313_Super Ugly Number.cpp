class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> uglyNumbers;
        uglyNumbers.push_back(1);
        vector<int> multiple_of(k, 0);
        vector<int> next_multiple(k);
        for (int i=0;i<k;i++) {
            next_multiple[i] = primes[i];
        }
        while (uglyNumbers.size()<n) {
            int iMin = next_multiple[0];
            int ind = 0;
            for (int j = 1; j < next_multiple.size(); j++) {
                iMin = min(iMin, next_multiple[j]);
            }
            uglyNumbers.push_back(iMin);
            for (int j = 0; j < next_multiple.size(); j++) {
                if (iMin == next_multiple[j]) {
                    ind = j;
                    ++multiple_of[ind];
                    next_multiple[ind] = primes[ind] * uglyNumbers[multiple_of[ind]];
                }
            }
        }
        return uglyNumbers[n-1];
    }
};