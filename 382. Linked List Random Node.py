# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# Runtime: 68 ms, faster than 92.02% of Python online submissions for Linked List Random Node.
# Memory Usage: 16 MB, less than 50.00% of Python online submissions for Linked List Random Node.
class Solution(object):

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.lists = []
        while head!=None:
            self.lists.append(head.val)
            head = head.next

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        n = len(self.lists)
        return self.lists[random.randint(0, n - 1)]
    
# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()