/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr != NULL){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        ListNode* newHead = prev;
        ListNode* node1=newHead;
        ListNode* newPrev=NULL;
        for(int i=1;i<n;i++){
            newPrev=node1;
            node1=node1->next;

        }
        if(node1 != newHead){
            newPrev->next=node1 ->next;
            node1->next=NULL;
        }
        else{
            newHead=newHead->next;
        }
    ListNode* prev1=NULL;
    ListNode* curr1=newHead;
    while(curr1 != NULL){
            ListNode* nxt=curr1->next;
            curr1->next=prev1;
            prev1=curr1;
            curr1=nxt;
        }
    return prev1;
    }
};
