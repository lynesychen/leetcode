class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0: return 0
        if n < 4: return max(nums)

        first, second = 0, 0
        for i in nums[:-1]: first, second = second, max(first + i, second)
        result = second

        first, second = 0, 0
        for i in nums[1:]: first, second = second, max(first + i, second)
        return max(result, second)