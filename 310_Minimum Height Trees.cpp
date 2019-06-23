class Solution{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges){
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for (auto e : edges){
            degree[e[0]]++; degree[e[1]]++;
            graph[e[0]].push_back(e[1]); graph[e[1]].push_back(e[0]);
        }
        vector<int> res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        if (n == 2) {
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        queue<int> remove;
        queue<int> toremove;    
        stack<int> removed;
        for (int i = 0; i < n; i++)
            if (degree[i] == 1)
                remove.push(i);
        while (removed.size() !=  n - 1 && removed.size() !=  n - 2){
            while (!remove.empty()) {
                int v = remove.front();
                remove.pop();
                removed.push(v);
                for (int w : graph[v])
                    if (--degree[w] == 1)
                        toremove.push(w);
            }
            swap(remove, toremove);
        }
        while (!remove.empty()){
            res.push_back(remove.front());
            remove.pop();
        }
        return res;
    }
};