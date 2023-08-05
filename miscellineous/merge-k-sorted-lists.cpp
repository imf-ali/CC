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
typedef pair<int,int> pii;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i])
                pq.push({lists[i]->val,i});
        }
        ListNode *dummyRes = new ListNode();
        ListNode *q = dummyRes;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            q->next = lists[it.second];
            q=q->next;
            lists[it.second] = lists[it.second]->next;
            if(lists[it.second])
                pq.push({lists[it.second]->val,it.second});
        }
        return dummyRes->next;
    }
};
