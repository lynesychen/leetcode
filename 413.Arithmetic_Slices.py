class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        n = len(A)
        if n < 3:
            return 0
        tmp = 0
        count = 0
        for i in range(2,n):
            if A[i]-A[i-1] == A[i-1]-A[i-2]:
                tmp = tmp + 1
                count += tmp
            else:
                tmp = 0
        return count
