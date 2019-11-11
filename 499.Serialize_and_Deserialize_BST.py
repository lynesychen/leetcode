# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        vals = []
        def helper(n):
            if not n:
                vals.append('$')
                return
            vals.append(str(n.val))
            helper(n.left)
            helper(n.right)
            return
        helper(root)
        return ' '.join(vals)
                

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def helper():
            val = next(vals)
            if val=='$':
                return None
            
            n = TreeNode(val)
            n.left = helper()
            n.right = helper()
            return n
            
        vals = iter(data.split(' '))
        root = helper()
        return root
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
