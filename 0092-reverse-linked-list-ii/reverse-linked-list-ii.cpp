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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);          // guarantees a node before position 1
        ListNode* leftList = &dummy;
    
        ListNode* currentNode = head;
      
        int pos = 1;
        
        for(int i=0;i<left-1;i++){
           leftList = leftList -> next;
        }
            ListNode* leftNode= leftList->next;
            ListNode* cur = leftNode;
            ListNode* prev = nullptr;        


        for(int i=0;i< right-left +1 ;++i){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur; cur = next; 
        } leftList->next = prev; leftNode->next = cur;
      return dummy.next;
   
    }
};