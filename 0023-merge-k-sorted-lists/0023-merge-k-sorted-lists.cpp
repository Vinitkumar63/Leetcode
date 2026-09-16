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
// ya hanma likh ha
struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val> b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // use priority_queue;

        priority_queue<ListNode*, vector<ListNode*>,compare>pq; // here greater<listnode> is not used because it deal with memory but here we need the value from the list thatswhy we write this

        for(ListNode* node:lists){
            if(node!=NULL){
                     pq.push(node);
            }
           
           
        }
        ListNode* dummy= new ListNode(-1);
        ListNode* tail=dummy;

        while(!pq.empty()){
               ListNode* node=pq.top();
               pq.pop();

               tail->next=node;
               tail=tail->next;

               if(node->next!=NULL){
                pq.push(node->next);
               }
              
            
        }
         return dummy->next;
    }
};