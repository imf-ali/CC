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
    pair<ListNode*,ListNode*> reverseList(ListNode* head){
        
        ListNode *prev = NULL, *next = head->next;
        ListNode *newLast = head;
        while(head){
            head->next = prev;
            prev = head;
            head = next;
            if(next) next = next->next;
        }
        return {prev, newLast};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head || !head->next)
            return head;

        ListNode *p = head, *q = head;
        ListNode *dummy = new ListNode();
        ListNode *prev = dummy;
        dummy->next = head;
        int cnt = 1;
        while(q){
            if(cnt == k){
                ListNode *next = q->next;
                q->next = NULL;
                auto ptr = reverseList(p); 
                prev->next = ptr.first;
                prev = ptr.second;
                ptr.second->next = next;
                q = next;
                p = next;
                cnt = 1;
                continue;
            }
            cnt++;
            q = q->next;
        }
        return dummy->next;
    }
};
