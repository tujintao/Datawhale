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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head, *newH = nullptr;
        while(p) {
            ListNode* tmp = p->next;
            p->next = newH;
            newH = p;
            p = tmp;
        }
        return newH;
    }
};