/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */ 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        
        for (ListNode* list : lists) 
            if (list) q.push(list);
        
        while(!q.empty()) {
            cur->next = q.top(); q.pop();
            cur = cur->next;
            if(cur->next) q.push(cur->next);
        }
        return dummy.next;
    }
};