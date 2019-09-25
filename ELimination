class Solution:
    def helper(self, n: int, left: bool):
        if n==1:
            return 1
        if left==True:
            return 2 * self.helper(n // 2, False)
        else:
            return 2 * self.helper(n // 2, True) - 1 + n % 2
    
    def lastRemaining(self, n: int) -> int:
        return self.helper(n, True)
