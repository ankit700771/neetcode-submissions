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
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            curr = curr -> next;
            head->next = prev;
            prev = head;
            head = curr;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rev = reverseList(slow);
        ListNode* curr = head;

        while(rev->next != NULL) {
            ListNode* tempcurr = curr->next;
            curr->next = rev;
            ListNode* temprev = rev->next;
            rev->next = tempcurr;
            curr = tempcurr;
            rev = temprev;
        }
    }
};
