# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        count = []
        self.helper(root, count, k)
        return count[k-1]
        
    def helper(self, node, count, k):
        if not node:
            return
        
        self.helper(node.left, count, k)
        count.append(node.val)
        if(len(count)>=k):
            return
        self.helper(node.right, count, k)