class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        mask = 0
        finalRes = 0
        for bit in range(31, -1, -1):
            mask |= 1 << bit
            prefixSet = {num & mask for num in nums}
            guess = finalRes | 1 << bit
            for prefix in prefixSet:
                if prefix ^ guess in prefixSet:
                    finalRes = guess
                    break
        return finalRese
