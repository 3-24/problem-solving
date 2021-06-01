# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def addTwoNumbers(list1, list2, node, digit):
            n = digit
            if (list1 != None):
                n += list1.val
            if (list2 != None):
                n += list2.val
            
            q = n // 10
            r = n % 10
            node.val = r
            node.next = None
            
            if (list1 == None):
                next_list1 = None
            else:
                next_list1 = list1.next
            
            if (list2 == None):
                next_list2 = None
            else:
                next_list2 = list2.next
            
            if (next_list1 == None and next_list2 == None and q == 0):
                return
            
            node.next = ListNode(0)
        
            
            addTwoNumbers(next_list1, next_list2, node.next, q)
            
            
            
        startNode = ListNode(0)
        addTwoNumbers(l1, l2, startNode, 0)
        return startNode
        
        