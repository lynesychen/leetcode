class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0])return a[1]<b[1];
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n==0)return 0;
        sort(points.begin(), points.end(), cmp);
        int res = 1, des=points[0][1];
        for(int i = 1; i < n ; ++i){
            if (points[i][0] <= des) des=min(des, points[i][1]);
            else{
                res++;
                des = points[i][1];
            }
        }
        return res;
    }
};
