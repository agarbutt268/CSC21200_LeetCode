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
    ListNode* reverseList(ListNode* head) {
        // If the list is empty or has only one node, just return it base case 
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // We need three pointers to keep track of things
        ListNode* prev = nullptr;    // The node before current
        ListNode* current = head;    // The node we're working on
        ListNode* next = nullptr;    // The node after current
        
        // Keep going until we've processed all nodes
        while (current != nullptr) {
            //  Save the next nodezzz4
            next = current->next;
            
            // Reverse the pointer make current point backwards
            current->next = prev;
            
            //  Move our pointers forward for the next iteration
            prev = current;
            current = next;
        }
        
        // When we're done, prev will be pointing at the new head
        return prev;
    }
};