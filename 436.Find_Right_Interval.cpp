class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        unordered_map<int,int> pos;
        vector<int> vec(n,0),res(n,-1);
        for(int i=0;i<n;i++){
            int tmp=intervals[i][0];
            vec[i]=intervals[i][0];
            pos[tmp]=i;
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<n;i++){
            int end=intervals[i][1];
            auto it=lower_bound(vec.begin(),vec.end(),end);
            if(it!=vec.end()) res[i]=m[*it]; 
        }
        return res;
    }
};
