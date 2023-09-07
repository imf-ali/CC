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
    ListNode* reverseList(ListNode *head, int len){
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *p = dummy, *q = dummy->next, *r = dummy->next->next;
        while(len--){
            q->next = p;
            p = q;
            q = r;
            if(r)
                r = r->next;
        }
        dummy->next->next = q;
        return p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *p=dummy;
        int cnt = 1;
        while(cnt++ != left)
            p=p->next;

        p->next = reverseList(p->next,right-left+1);
        return dummy->next;
    }
};
