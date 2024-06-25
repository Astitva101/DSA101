/*Question:
Given the head of a linked list,
remove the nth node from the end of the list and return its head.*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move fast pointer n steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both slow and fast pointers until fast reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Remove the nth node from the end
        ListNode* toRemove = slow->next;
        slow->next = slow->next->next;
        delete toRemove;
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};