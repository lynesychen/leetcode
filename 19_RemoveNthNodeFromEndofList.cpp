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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nhead=head,*res=head;
        int num=0;
        while(head){
            head=head->next;
            ++num;
        }
        n=num-n+1;
        if(n==1)res=res->next;
        else {
            for(int i=1;i<n-1;++i){
                nhead=nhead->next;
            }
            if(nhead->next)nhead->next=nhead->next->next;
        }
        return res;
    }
};