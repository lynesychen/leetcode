
class Solution {
public:
    bool hasCommon(string a,string b){
        int len1 = a.size();
        int len2 = b.size();
        while(len1>0&&len2>0){
            int i = a.size()-len1;
            int j = b.size()-len2;
            if(a.at(i) == b.at(j)){
                len1--;len2--;
            }else{
                len2--;
            }
        }
        return len1==0;
    }
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        for(int i = 0;i<strs.size();++i){
            int currentLen = strs[i].length();
            bool all = true;
            for(int j = 0;j<strs.size();++j){
                if(i!=j&&hasCommon(strs[i], strs[j])){
                    all = false;
                    break;
                }
            }
            if(all){
                maxLen = maxLen<currentLen?currentLen:maxLen;
            }
        }
        return maxLen;
    }
};
