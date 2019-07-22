class Solution:
    def integerBreak(self, n: int) -> int:
        if n < 4:
            return n - 1
        nums = [2,3]
        dp = [1] * (n + 1)
        for val in range(1, n + 1):
            for num in nums:
                if val >= num:
                    dp[val] = max(dp[val], num * dp[val - num])
        return dp[-1]