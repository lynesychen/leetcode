class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0,cnt=0;
        map<char,int> m;
        for(int i=0,j=0;i<s.length();++i){
            char tmp=s[i];
            if(m[tmp]){
                j=max(m[tmp],j);
            }
            res=max(res,i-j+1);
            m[tmp]=i+1;
        }
        return res;
    }
};