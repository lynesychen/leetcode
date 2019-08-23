class Solution(object):
	def largestDivisibleSubset(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[int]
		"""
		if not nums: return []
		from collections import Counter
		dp = Counter()
		prev = {}
		def fac(n):
			res = [1]
			x = 2
			while x * x <= n:
				if n % x == 0:
					res.append(x)
					res.append(n / x)
				x += 1
			return res
		nums.sort()
		best = None
		maxLen = float('-inf')
		for n in nums:
			dp[n] = 1
			if n > 1:
				for f in fac(n):
					if dp[f] + 1 > dp[n]:
						dp[n] = dp[f] + 1
						prev[n] = f
			if dp[n] > maxLen:
				maxLen = dp[n]
				best = n
		res = []
		curr = best
		while curr:
			res.append(curr)
			curr = prev.get(curr)
		return res