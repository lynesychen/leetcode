class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        if(len(nums)<2):
            return(False)
        if(any(0==nums[i]+nums[i+1] for i in range(0,len(nums)-1))):
            return(True)
        if(k==0):
            return(False)
        if(k<0):
            k = -k
        last_sum = [nums[0]%k, (nums[0]+nums[1])%k]
        sum_set = set()
        sum_set.add(0)
        if (last_sum[1]==0):
            return(True)
        for n in range(2,len(nums)):
            sum_set.add(last_sum[0])
            last_sum = [last_sum[1], (last_sum[1]+nums[n])%k]
            if(last_sum[1] in sum_set):
                return(True)
        return(False)
