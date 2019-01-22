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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res=new ListNode(0);
        ListNode *head=res;
        int tmp=0;
        while(l1!=NULL||l2!=NULL){
            if(l1){
                tmp+=l1->val;
                l1=l1->next;
            }
            if(l2){
                tmp+=l2->val;
                l2=l2->next;
            }
            res->val=tmp%10;
            tmp/=10;
            if(l1||l2||tmp){
                res->next=new ListNode(tmp);
                res=res->next;
            }
        }
        return head;
    }
};