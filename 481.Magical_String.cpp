class Solution {
public:
    int magicalString(int n) {
        int cnt=0;
        char * p=new char[n+2];
        memset(p, 0, n+2);
        int i=0,j=0;
        p[0]=1;
        while(j<n && i<n) {
            int nc=0;
            if(p[i]==1) {
                i++;
                j++;
                if(p[j]==0) p[j]=3-p[j-1];
            }
            else if(p[i]==2) {
                if(p[j]!=p[j-1]) {int aa=p[j];p[++j]=aa;}
                i++;
                j++;
                if(p[j]==0) p[j]=3-p[j-1];
            }
        }
        for(int i=0;i<n;i++)
            if(p[i]==1) cnt++;
        return cnt;
    }
};
