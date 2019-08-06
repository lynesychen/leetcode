class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
    	if n == 0:
    		return 1
    	g, h = 10, 9
    	for i in range(n-1):
    		g += 9*h
    		h *= (8-i)
    	return g