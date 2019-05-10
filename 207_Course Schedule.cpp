class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<unordered_set<int>> matrix(numCourses); // save this directed graph
        for(int i = 0; i < prerequisites.size(); ++ i)
            matrix[prerequisites[i][1]].insert(prerequisites[i][0]);
        vector<int> d(numCourses, 0); 
        for(int i = 0; i < numCourses; ++ i)
            for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
                ++ d[*it];
        for(int j = 0, i; j < numCourses; ++ j){
            for(i = 0; i < numCourses && d[i] != 0; ++ i); 
            if(i == numCourses)
                return false;
            d[i] = -1;
            for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
                -- d[*it];
        }
        return true;
    }
};