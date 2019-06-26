class Solution {
public:
    int bulbSwitch(int n) {
        long i=1;
        while (i * i <= n) i++;
        return i-1;
    }
};