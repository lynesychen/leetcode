"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution:
    def dfs(self, node):
        if(node.next):
            self.dfs(node.next)
        if(node.child):
            self.dfs(node.child)
        node.next = self.res
        if self.res:
            self.res.prev = node
        self.res = node
        node.child=None
    
    def flatten(self, head: 'Node') -> 'Node':
        self.res = None
        if(head):
            self.dfs(head)
        return self.res
