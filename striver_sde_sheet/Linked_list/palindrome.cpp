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
    ListNode* reverseList(ListNode* head) {

        if(!head || !head->next)
            return head;
        
        ListNode* p = NULL;
        ListNode *q = head, *r = head->next;

        while(q) {
            q->next = p;
            p = q;
            q = r;
            if(r)   r = r->next;
        }

        return p;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;

        ListNode *p = head, *q = head;
        while(q && q->next){
            p = p->next;
            q = q->next->next;
        }
        ListNode* head2 = reverseList(p);
        while(head && head2){
            if(head->val != head2->val)
                return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};
