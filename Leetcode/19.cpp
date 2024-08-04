// * @param Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* fast = head; 
       ListNode* slow = head; 
       for (std::size_t i = 0; i < n; ++i)
       {
            fast = fast->next; 
       }
       if (fast == nullptr)
       {
            head = head->next; 
            delete slow; 
            return head; 
       }
       while (fast && fast->next)
       {
            fast = fast->next; 
            slow = slow->next; 
       }
        ListNode* remove = slow->next;
        slow->next = slow->next->next;
        return head;  
    }
};