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
    void reorderList(ListNode* head) {
       ListNode *curr = head, *fast = head -> next, *slow = head;
       while(fast != NULL && fast -> next != NULL)
       {
        slow = slow -> next;
        fast = fast -> next -> next;
       }
  
       ListNode* prev = NULL;
       curr = slow -> next;
       while(curr != NULL)
       {
        ListNode* temp = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
       }

        slow -> next = NULL;
       curr = head;

       while(prev != NULL)
       {
        ListNode *temp1 = curr -> next, *temp2 = prev -> next;
        curr -> next = prev;
        prev -> next = temp1;
        curr = temp1;
        prev = temp2;
       }
    }
};













