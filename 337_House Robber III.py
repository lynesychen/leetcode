# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, root: TreeNode):
        if root is None:
            return 0, 0
        max_left, left_down = self.dfs(root.left)
        max_right, right_down = self.dfs(root.right)
        return max(max_left + max_right, root.val + left_down + right_down), max_left + max_right
    
    def rob(self, root: TreeNode) -> int:
        res, _ = self.dfs(root)
        return res
