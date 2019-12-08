class Solution {
public:
    vector<int> area;
    vector<vector<int>> rts;
    Solution(vector<vector<int>> rects) {
        rts = rects;
        for(int i = 0; i < rects.size(); ++i) {
            auto &r = rects[i];
            int a = (r[2] - r[0] + 1) * (r[3] - r[1] + 1) + (i > 0 ? area.back() : 0);
            area.push_back(a);
        }
        
    }
    
    vector<int> pick() {
        int p = rand() % area.back();
        int idx = upper_bound(area.begin(), area.end(), p) - area.begin();
        auto &rect = rts[idx];
        p -= (idx > 0 ? area[idx - 1] : 0);
        return {p / (rect[3] - rect[1]+1) + rect[0], p % (rect[3] - rect[1] + 1) + rect[1]};
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
