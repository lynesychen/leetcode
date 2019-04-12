class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool answer = false;
        int size = s.length();
        unordered_set<string> umap;
        for (auto word: wordDict) {
            umap.insert(word);
        }
        vector<bool> check(size + 1, false);
        check[0] = true;
        for (int i = 1; i <= size; i++) {
            for (int k = 0; k < i; k++) {
                if (check[k] && (umap.find(s.substr(k, i - k)) != umap.end())) {
                    check[i] = true;
                    break;
                }
            }
        }
        return check[s.length()];
    }
};