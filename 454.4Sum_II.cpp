class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> bank;
        for (int i = 0; i < C.size(); i++) 
            for (int j = 0; j < D.size(); j++) 
                bank[C[i] + D[j]]++;
        int count = 0;
        for (int i = 0; i < A.size(); i++) 
            for (int j = 0; j < B.size(); j++) 
                if (bank.find(-(A[i] + B[j])) != bank.end()) count += bank[-(A[i] + B[j])];
        return count;
    }
};
