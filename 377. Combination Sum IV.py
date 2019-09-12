class Solution:
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """ 
        mem = [0]*(target + 1)
        mem[0] = 1
        for i in range(1, target +1):
            for num in nums:
                if i >= num:
                    mem[i] += mem[i - num]

        return mem[target]