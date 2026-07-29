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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0){
            return head;
        }
        // now calculate tail and lenth
        int len=1;
        ListNode* tail=head;
        while(tail->next){
            len++;
            tail=tail->next;
        }
        // remove our unnecessary rotations
        k=k%len;

        if(k==0)
        return head;

        tail->next=head; // this make the list circular
    
    ListNode* temp=head;
    for(int i=1;i<len-k;i++){
            temp=temp->next;
    }
    ListNode* newhead=temp->next;
    // now break the loop
    temp->next=NULL;
    return newhead;
    }
};