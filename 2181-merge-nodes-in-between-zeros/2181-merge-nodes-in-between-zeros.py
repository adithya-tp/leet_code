# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr_zero = head
        curr_sum = 0
        dummy_node = ListNode(None)
        dummy_node_copy = dummy_node
        head = head.next
        while head != None:
            if head.val == 0:
                dummy_node.next = ListNode(curr_sum)
                dummy_node = dummy_node.next
                curr_sum = 0
                curr_zero = head
            else:
                curr_sum += head.val
            head = head.next
            
        return dummy_node_copy.next
            
                