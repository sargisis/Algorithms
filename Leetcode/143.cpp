// * @param You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

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
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        ListNode* fast = head; 
        ListNode* slow = head; 

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next; 
            slow = slow->next; 
        }

        ListNode* current = slow; 
        ListNode* prev = nullptr; 
        ListNode* next = nullptr; 

        while (current != nullptr) {
            next = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
        }

        ListNode* first = head; 
        ListNode* second = prev;

        while (second->next != nullptr) {
            ListNode* temp1 = first->next; 
            ListNode* temp2 = second->next; 
            first->next = second; 
            second->next = temp1; 
            first = temp1; 
            second = temp2; 
        }
    }
};
