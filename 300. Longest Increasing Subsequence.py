from bisect import bisect_left
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        mem = list()
        n = len(nums)
        for i in range(n):
            index = bisect_left(mem, nums[i])
            if len(mem) == index:
                mem.append(nums[i])
            else:
                mem[index] = nums[i]
        return len(mem)