class Solution {
public:
    Solution(int n_rows, int n_cols) {
        total = n_rows * n_cols;
        row = n_rows;
        col = n_cols;
    }
    vector<int> flip() {
        if (total <= 0) return{};
        int r = rand() % (total--);
        int x ;
        if (m.count(r) > 0) {
            x = m[r];
        }
        else x = r;
        m[r] = m.count(total) > 0 ? m[total] : total;
        return{ x / col,x%col };
    }
    void reset() {
        m.clear();
        total = row * col;
    }
private:
    unordered_map<int, int> m;
    int total;
    int row, col;
};
static const auto io_sync_off = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
