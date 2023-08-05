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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* build(vector<int> &list,int left,int right){
        if(left>right)  
            return NULL;

        int mid = (left + right)/2;
        TreeNode* root = new TreeNode(list[mid]);
        root->right = build(list,mid+1,right);
        root->left = build(list,left,mid-1);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;

        vector<int> list;
        while(head){
            list.push_back(head->val);
            head = head->next;
        }

        return build(list,0,list.size()-1);
    }
};
