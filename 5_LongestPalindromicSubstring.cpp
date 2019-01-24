/*
以下算法复杂度为O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0)return "";
        int st=0,des=0;
        for(int i=0;i<s.length();++i){
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);
            int len=max(len1,len2);
            if(len>des-st){
                st=i-(len-1)/2;
                des=i+len/2;
            }
        }
        return s.substr(st,des-st+1);
    }
    int expand(string s,int l,int r){
        int ll=l,rr=r;
        while(ll>=0&&r<s.length()&&s[ll]==s[rr]){
            ll--;
            rr++;
        }
        return rr-ll-1;
    }
};
*/

//manacher's algorithm 
//O(n)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0)return "";
        string tmp="$";
        for(int i=0;i<s.length();++i){
            tmp+="#";
            tmp+=s[i];
        }
        tmp+="#";
        int centerInd=0,rightInd=0,reslen=0,rescenter=0;
        vector<int> radius(tmp.length()+2,0);
        for(int i=1;i<tmp.length();++i){
            radius[i]=rightInd>i?min(rightInd-i,radius[centerInd*2-i]):1;
            while(tmp[i+radius[i]]==tmp[i-radius[i]])++radius[i];
            if(rightInd<i+radius[i]){
                rightInd=i+radius[i];
                centerInd=i;
            }
            if(reslen<radius[i]){
                reslen=radius[i];
                rescenter=i;
            }
        }
        return s.substr((rescenter-reslen)/2,reslen-1);
    }
};