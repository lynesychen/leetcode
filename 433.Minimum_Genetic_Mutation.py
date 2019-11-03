class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        res=[2**31-1]
        dict2={}
        for s in bank:
            dict2[s]=False
        if not end in dict2: return -1
        def dfs(gene,count,end):
            if gene==end:
                res[0]=min(res[0],count)
                return 
            for i in range(len(gene)):
                    left=gene[:i]
                    right=gene[i+1:]
                    for c in 'ACGT':
                        if c!=gene[i]:
                            cur=left+c+right
                            if cur in dict2 and not dict2[cur]:
                                dict2[cur]=True
                                dfs(cur,count+1,end)
                                dict2[cur]=False
        
        dfs(start,0,end)
        return -1 if res[0]==2**31-1 else res[0]
