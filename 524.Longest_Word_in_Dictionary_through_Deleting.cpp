class Solution {
public:
    static bool cmp(const string &a, const string &b){
        if(a.length()!=b.length()) return a.length()>b.length();
        return a<b;
    }
    string findLongestWord(string s, vector<string>& d) {
        string ans;
        sort(d.begin(), d.end(), cmp);
        for(string t : d) {
            int i = 0, j = 0;
            for(j = 0; j < s.size(); j++) {
                if(s[j] == t[i]){
                    i++;
                    if(i == t.size())return t;
                }
            }
        }
        return ans;
    }
};
