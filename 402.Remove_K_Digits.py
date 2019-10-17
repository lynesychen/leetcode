class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if k == 0:
            return num 
        n = len(num)
        if n == k:
            return "0"
        top = 0
        remian_num = n - k
        stk = [''] * n
        for c in num:
            while (top > 0  and k > 0 and stk[top - 1] > c):
                top -= 1
                k -= 1
            stk[top] = c
            top += 1
        idx = 0
        
        while idx < remian_num and stk[idx] == '0':
            idx += 1
        if idx == remian_num:
            return "0"
        tmp = stk[idx : min(idx+remian_num, top)]
        return "".join(tmp)
