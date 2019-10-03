class Solution:
    def findNthDigit(self, n: int) -> int:
        digit = 1
        while n > digit*9*10**(digit-1):
            n -= digit*9*10**(digit-1)
            digit += 1
        a = int((n-1)/digit)
        b = int((n-1)%digit)
        num = 10**(digit-1)+a
        res = list(str(num))[b:b+1]
        return int(''.join(res))
