class Solution:
    def countBits(self, num: int) -> List[int]:
        res = [0]
        j = 1
        for i in range(1, num + 1):
            if i - j == j:
                j *= 2
            res.append(res[i - j] + 1)
            
        return res