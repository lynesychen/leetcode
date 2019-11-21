class Solution {
public:
    bool dfs(int i, int maxChoose, int desire, vector<int> &vis){
        if(~vis[i])return vis[i];
        for(int j=maxChoose; j > 0; --j){
            if(i & (1<<(j-1)))continue;
            if(j >= desire || !dfs(i|(1<<(j-1)), maxChoose, desire-j,vis))
                return vis[i]=1;
        }
        return vis[i]=0;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
         if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        vector<int> vis(1 << maxChoosableInteger, -1);
        return dfs(0, maxChoosableInteger, desiredTotal, vis);
    }
};
