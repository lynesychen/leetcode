class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> p_count(26, 0);
        vector<int> s_count(26, 0);
        for(auto c : p){
            p_count[c - 'a']++;
        }
        int plen = p.length();
        vector<int> result;
        if(plen>s.length())return result;
        for(int i = 0; i < plen; ++i){
            s_count[s[i] - 'a']++;
        }
        if(s_count == p_count){
            result.push_back(0);
        }
        for(int i = plen; i < s.length(); ++i){
            s_count[s[i-plen] - 'a']--;
            s_count[s[i] - 'a']++;
            if(s_count == p_count){
                result.push_back(i-plen+1);
            }
        }
        return result;
    }
};
