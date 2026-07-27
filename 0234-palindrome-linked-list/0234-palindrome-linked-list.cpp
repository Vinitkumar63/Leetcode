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

        // make function on reversing
        ListNode* reverse(ListNode* head){
           ListNode* prev=NULL;
           ListNode* curr=head;
           while(curr!=NULL){
            ListNode* newNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newNode;
           }
           return prev;
        }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        // first find middle
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondhalf =reverse(slow);
        ListNode* first_half=head;
        while(secondhalf !=NULL){
            if(secondhalf->val!=first_half->val){
                return false;
            }else{
                secondhalf= secondhalf->next;
                first_half=first_half->next;
            }
        }
        return true;
    }
};