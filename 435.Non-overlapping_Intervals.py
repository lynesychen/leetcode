class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key=lambda x: x[0])
        result = 0
        prev = 0
        for i in range(1, len(intervals)):
            if intervals[prev][-1] <= intervals[i][0]:
                prev = i
            else:
                result += 1
                if intervals[prev][-1] > intervals[i][-1]:
                    prev = i
        return result
