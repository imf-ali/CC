/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *newHead=NULL, *temp=NULL;
        Node* p = head;
        while(p){
            if(!newHead){
                newHead = new Node(head->val);
                temp = newHead;
            }
            else {
                temp->next = new Node(p->val);
                temp = temp->next;
            }
            p = p->next;
        }
        p = head;
        temp = newHead;
        while(p) {
            Node *q=head, *temp2=newHead;
            while(q != p->random){
                q = q->next;
                temp2 = temp2->next;
            }
            temp->random = temp2;
            p = p->next;
            temp = temp->next;
        }

        return newHead;
    }
};
