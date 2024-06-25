/*Question:
Given the head of a singly linked list, reverse the list, and return the reversed list.*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;    // Store the next node
            curr->next = prev;    // Reverse the current node's pointer
            prev = curr;          // Move prev and curr one step forward
            curr = next;
        }
        
        return prev;  // Prev now points to the new head of the reversed list
    }
};