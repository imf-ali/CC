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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head, *q;
        if(!head || !head->next)
            return head;
            
        int len=1;
        while(p->next){
            len++;
            p=p->next;
        }
        p->next = head;

        int i=len-(k%len);
        while(i--)
            p=p->next;
        
        q = p->next;
        p->next = NULL;

        return q;
    }
};
