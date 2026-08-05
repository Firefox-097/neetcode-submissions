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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while (mid != NULL) {
            ListNode* next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        ListNode* hd1 = head;
        ListNode* hd2 = prev;
        while (hd2 != NULL) {
            ListNode* next1 = hd1->next;
            ListNode* next2 = hd2->next;
            hd1->next = hd2;
            hd2->next = next1;
            hd1 = next1;
            hd2 = next2;
        }
    }
};
