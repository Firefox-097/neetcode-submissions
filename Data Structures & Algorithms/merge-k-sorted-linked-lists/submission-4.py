# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if not lists:
            return None
        def merge2Lists(list1 , list2):
            if not list1:
                return list2
            if not list2:
                return list1
            if list1.val <= list2.val:
                head=list1
                list1=list1.next
            else:
                head=list2
                list2=list2.next
            curr=head
            while list1 is not None and list2 is not None:
                if list1.val<=list2.val:
                    curr.next=list1
                    list1=list1.next
                else:
                    curr.next=list2
                    list2=list2.next
                curr=curr.next
            if list1 is not None:
                curr.next=list1
            else:
                curr.next=list2
            return head
        def mergeRange(left , right):
            if (left == right) :
                return lists[left]
            mid = (left + right) //2
            firstHalf= mergeRange(left , mid)
            secondHalf=mergeRange(mid+1,right)
            return merge2Lists(firstHalf , secondHalf)
        return mergeRange (0,len(lists)-1)