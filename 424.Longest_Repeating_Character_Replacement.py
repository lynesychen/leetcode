ass Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if s == '':
            return 0
        count = [0] * 26
        max_len = 0
        width = k + 1
        st_idx = 0
        lens = len(s)
        orda = ord('A')
        max_cnt = 0
        max_char = ""
        for c in s[:width]:
            tmp = count[ord(c)-orda]
            count[ord(c)-orda] = tmp + 1
            if tmp + 1 > max_cnt:
                max_cnt = tmp + 1
                max_char = c
        while True:
            if width - max_cnt <= k:
                max_len = max(max_len, width)
                if st_idx + width < lens:
                    tmp = count[ord(s[st_idx+width]) - orda]
                    count[ord(s[st_idx+width]) - orda] = tmp + 1
                    if tmp + 1 >= max_cnt:
                        max_cnt = tmp + 1
                        max_char = s[st_idx+width]
                    width += 1
                else:
                    break
            else:
                tmp = count[ord(s[st_idx])-orda]
                count[ord(s[st_idx])-orda] = tmp - 1
                if s[st_idx] == max_char:
                    max_cnt -= 1
                st_idx += 1
                width -= 1
        return max_len


