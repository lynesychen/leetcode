ass Solution:
    def canPartition(self, nums: List[int]) -> bool:
        sumn = sum(nums)
        n = len(nums)
        if (sumn & 1) or n <= 1:
            return False
        sumn = sumn >> 1
        dp = [False] * (sumn + 1)
        dp[0] = True
        for num in nums:
            for val in range(sumn, num-1, -1):
                dp[val] = dp[val] or dp[val - num]
        return dp[sumn]
    
