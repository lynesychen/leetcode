class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 2: return False
        for i in range(n):
            if nums[i] < 2000:
                i0 = i
                v = 2000+i
                sgn = 1 if nums[i] > 0 else -1
                while True:
                    i1 = (i0 + nums[i0]) % n
                    nums[i0] = v
                    if i1 == i0:
                        break
                    elif nums[i1] == v:
                        return True
                    elif nums[i1] >=2000:
                        break
                    elif nums[i1]*sgn < 0:
                        break
                    else:
                        i0 = i1
        return False
