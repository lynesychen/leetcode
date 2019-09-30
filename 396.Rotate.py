class Solution:
    def maxRotateFunction(self, A: List[int]) -> int:
        n = len(A)
        sum_value = sum(A)
        F = sum([i * A[i] for i in range(n)]) 
        maxF = F
        for k in range(1, n):
            F = F + sum_value - n * A[n - k]
            maxF = max(maxF, F)
        return maxF
