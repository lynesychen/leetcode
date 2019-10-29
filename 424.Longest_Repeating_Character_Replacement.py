# 事实证明defaultdict还是比自己造数组快了四倍
from collections import defaultdict

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if s == '':
            return 0
        count = defaultdict(int)
        max_len = 0
        width = k + 1
        st_idx = 0
        lens = len(s)
        max_cnt = 0
        max_char = ""
        for c in s[:width]:
            tmp = count[c]
            count[c] = tmp + 1
            if tmp + 1 > max_cnt:
                max_cnt = tmp + 1
                max_char = c
        while True:
            if width - max_cnt <= k:
                max_len = max(max_len, width)
                if st_idx + width < lens:
                    tmp = count[s[st_idx+width]]
                    count[s[st_idx+width]] = tmp + 1
                    if tmp + 1 >= max_cnt:
                        max_cnt = tmp + 1
                        max_char = s[st_idx+width]
                    width += 1
                else:
                    break
            else:
                tmp = count[s[st_idx]]
                count[s[st_idx]] = tmp - 1
                if s[st_idx] == max_char:
                    max_cnt -= 1
                st_idx += 1
                width -= 1
        return max_len

