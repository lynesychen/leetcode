class Solution {
public:
    void helper(int total, int searchIndex, int numOpen, string& validCombination, vector<string>& result) {
        if (searchIndex == total) {
            for (int i = 0; i < numOpen; ++i) {
                validCombination += ')';
            }
            result.push_back(validCombination);
            for (int i = 0; i < numOpen; ++i) {
                validCombination.pop_back();
            }
        } else {
            // search with closing parentheses added
            for (int i = 0; i < numOpen; ++i) {
                validCombination += ')';
                validCombination += '(';
                helper(total, searchIndex + 1, numOpen - i, validCombination, result);
                validCombination.pop_back();
            }
            for (int i = 0; i < numOpen; ++i) {
                // remove the closing parentheses
                validCombination.pop_back();
            }
            // search without closing parentheses added
            validCombination += '(';
            helper(total, searchIndex + 1, numOpen + 1, validCombination, result);
            validCombination.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {""};
        }
        
        vector<string> result;
        string validCombination;
        helper(n, 0, 0, validCombination, result);
        return result;
    }
};