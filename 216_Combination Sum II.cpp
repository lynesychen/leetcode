class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        vector<int> tmp;
        find(n, k, 1, tmp);
        return result;
    }
    void find(int goal, int num, int ind, vector<int> tmp){
        //if(goal<1)return;
        if(goal==0&&num==0){
            result.push_back(tmp);
            return;
        }
        if(goal<=0||num==0)return;
        if(ind>9)return;
        for(int i=ind;i<=9;++i){
            tmp.push_back(i);
            find(goal-i, num-1, i+1, tmp);
            tmp.pop_back();
        }
        
    }
};