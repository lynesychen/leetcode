class Solution {
public:
    void find(int curr,int n,int k,vector<int> &res,vector<vector<int>> &total){
        if(n-curr+2<k)return;
        res.push_back(curr);
        if(k==0)total.push_back(res);
        for(int i=curr+1;i<=n;++i){
            find(i,n,k-1,res,total);
        }
        res.pop_back();
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> init;
        for(int i=1;i<=n;++i){
            find(i,n,k-1,init,res);
        }
        return res;
    }
};