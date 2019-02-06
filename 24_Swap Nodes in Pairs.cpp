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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        auto pre = head;
        auto next = head->next;
        if (next) {
            head->next = next->next;
            next->next = head;
            head = next;
        }
        while (pre->next) {
            next = pre->next;
            if (!next->next)break;
            pre->next = next->next;
            next->next = next->next->next;
            pre->next->next = next;
            pre = next;
        }
        
        return head;
    }
};