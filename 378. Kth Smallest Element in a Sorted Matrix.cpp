class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), l = matrix[0][0], r = matrix[n - 1][n - 1] + 1;
        int mid = l;
        while(l < r){
            mid = l + (r - l) / 2;
            int cnt = 0, cnt2 = 0;
            for(int i = 0; i < n; i++){
                auto &v = matrix[i];
                cnt += lower_bound(v.begin(), v.end(), mid) - v.begin();
                cnt2 += upper_bound(v.begin(), v.end(), mid) - v.begin();
            }
            if(cnt < k && cnt2 >= k) return mid;
            if(cnt < k) l = mid + 1;
            else r = mid;
        }
        return mid;
    }
};