import operator
from collections import defaultdict


class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        d = defaultdict(int)
        for num in nums:
          d[num] += 1
        sorted_d = sorted(d.items(), key=operator.itemgetter(1), reverse=True)
        ans = []
        for key,v in sorted_d:
          if not k:
            break
          ans.append(key)
          k -=1
        return ans