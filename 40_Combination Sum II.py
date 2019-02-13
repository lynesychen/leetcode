class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        #print(candidates)
        res = []
        self.dfs(candidates, target, 0, [], res)
        return res
    
    def dfs(self, nums, target, index, path, res):
        if target < 0:
            return  # backtracking
        if target == 0:
            res.append(path)
            return 
        for i in xrange(index, len(nums)):
            if i>index and nums[i]==nums[i-1]:
                continue
            if nums[i]>target:
                break
            self.dfs(nums, target-nums[i], i+1, path+[nums[i]], res)
        