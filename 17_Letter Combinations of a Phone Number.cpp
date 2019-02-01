class Solution {
private:
    vector<string> expand(vector<string> v, string digits, int n) {
        vector<string> newstrings;
        if (digits.size() == 0) return(newstrings);
        if (n == digits.size()) return(v);
        string letters [] = {"", "", "abc", "def", "ghi", "jkl",
                           "mno", "pqrs", "tuv", "wxyz"};
        int button = digits[n] - '0';
        for (int j = 0; j < v.size(); j++)
            for (int l = 0; l < letters[button].size(); l++)
                newstrings.push_back(v[j] + letters[button][l]);
        return(expand(newstrings, digits, n + 1));
    }
public:
    vector<string> letterCombinations(string digits) {
        return(expand({""}, digits, 0));
    }
};