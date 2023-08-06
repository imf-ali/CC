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

    ListNode* mergeSort(ListNode* head){

        if(!head || !head->next)
            return head;

        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *slow=dummy, *fast=dummy;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rt = mergeSort(slow->next);
        slow->next = NULL;
        ListNode *lt = mergeSort(head);

        ListNode *dn = new ListNode();
        ListNode *p = dn;
        while(lt && rt){
            if(lt->val < rt->val){
                dn->next = lt;
                lt=lt->next;
            }else{
                dn->next = rt;
                rt=rt->next;
            }
            dn=dn->next;
        }
        if(lt){
            dn->next = lt;
        }
        else if(rt){
            dn->next = rt;
        }
        return p->next;
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
