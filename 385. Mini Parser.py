# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution(object):
    def deserialize(self, s):
        """
        :type s: str
        :rtype: NestedInteger
        """
        stack = []
        elem = None #to reference the current NestedInteger object
        hasNum, sgn, num = False, 1, 0 # to reference current int object
        for x in s:
            if x == '[':
                stack.append(NestedInteger())
            elif x == '-':
                sgn = -1
            elif x.isdigit():
                hasNum = True
                num = num*10+int(x)
            else: # ',' or ']', attach an integer or a list to the parent
                if hasNum:
                    stack[-1].add(NestedInteger(sgn*num))
                    hasNum, sgn, num = False, 1, 0 # reset to none
                elif elem is not None:
                    stack[-1].add(elem) 
                    elem = None #reset to none, similar to num
                if x == ']':
                    elem = stack.pop()
        if hasNum:
            return NestedInteger(sgn*num)
        else:
            return elem

        