class Solution {
public:

    ListNode* mergeTwoLists(ListNode* a, ListNode* b){

        ListNode dummy;
        ListNode* curr = &dummy;

        while(a && b){

            if(a->val <= b->val){
                curr->next = a;
                a = a->next;
            }
            else{
                curr->next = b;
                b = b->next;
            }

            curr = curr->next;
        }

        if(a) curr->next = a;
        else curr->next = b;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return NULL;

        int interval = 1;

        while(interval < lists.size()){

            for(int i = 0; i + interval < lists.size(); i += interval * 2){

                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }

            interval *= 2;
        }

        return lists[0];
    }
};