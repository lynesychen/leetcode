class Solution:
    def lengthLongestPath(self, input: str) -> int:
        items = input.split('\n')
        d = {}
        max_length = 0
        for i in items:
            level = i.count('\t')
            is_file = '.' in i
            full_length = len(i) - level + d.get(level - 1, 0)
            if not is_file:
                d[level] = full_length + 1
            else:
                max_length = max(full_length, max_length)
        return max_length
