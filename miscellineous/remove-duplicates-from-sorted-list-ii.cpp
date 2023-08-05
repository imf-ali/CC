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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *p = head, *q=head->next;
        ListNode *dummy = new ListNode();
        dummy->next=head;
        while(q){
            while(p && q && (p->val == q->val)){
                q=q->next;
                p->next=p->next->next;
                if(q && p->val != q->val){
                    dummy->next=dummy->next->next;
                    if(head == p)
                        head = q;
                    p=q;
                    q=q->next;
                }
                else if(!q){
                    dummy->next=dummy->next->next;
                    if(head == p)
                        head = q;
                }
            }
            if(!q)
                break;
            dummy=dummy->next;
            p=p->next;
            q=q->next;
        }
        return head;
    }
};
