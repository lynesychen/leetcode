class Solution:
    def findOrder(self, numCourses, prerequisites):
        self.graph = collections.defaultdict(list) 
        self.res = [] 
        for pair in prerequisites:
            self.graph[pair[0]].append(pair[1]) 
        self.visited = [0 for x in xrange(numCourses)]  
        for x in xrange(numCourses):
            if not self.DFS(x):
                return []
        return self.res
    
    def DFS(self, node):
        if self.visited[node] == -1: 
            return False
        if self.visited[node] == 1:
            return True 
        self.visited[node] = -1 
        for x in self.graph[node]:
            if not self.DFS(x):
                return False
        self.visited[node] = 1 
        self.res.append(node) 
        return True