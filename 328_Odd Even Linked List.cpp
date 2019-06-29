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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *oHead = head -> next; 
        ListNode *eCurrent = head; 
        ListNode *oCurrent = oHead; 
        ListNode *current = head->next->next;
        int i=2;
        while(current !=NULL){
            ++i;
            if(i%2){
                eCurrent->next = current;
                eCurrent=current;
            }
            else{             
                oCurrent->next = current;
                oCurrent=current;
            }
            current=current->next;
        }
        eCurrent->next=oHead;
        oCurrent->next=NULL;
        return head;
        
    }
};