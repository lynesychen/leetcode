# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution(object):
    def rand10(self):
        """
        :rtype: int
        """
        r40 = (rand7() - 1) * 7 + (rand7() - 1)
        if r40 < 40:
            return r40 % 10 + 1
        
        return self.rand10()
