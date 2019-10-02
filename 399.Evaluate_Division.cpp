class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, map<string, double>> hash;
        for(int i = 0; i < equations.size(); i++){
            hash[equations[i][0]][equations[i][1]] = values[i];
            hash[equations[i][1]][equations[i][0]] = 1/values[i];
        }
        for(auto val: hash) hash[val.first][val.first] = 1;
        for(auto val1: hash){
            for(auto val2: hash)
                for(auto val3: hash)
                    if(hash[val1.first].count(val3.first) && hash[val2.first].count(val1.first))
                        hash[val2.first][val3.first] = hash[val2.first][val1.first]*hash[val1.first][val3.first];
        }
        vector<double> ans;
        for(auto val: queries)
            ans.push_back(hash[val[0]].count(val[1])?hash[val[0]][val[1]]:-1);
        return ans;
    }
};
