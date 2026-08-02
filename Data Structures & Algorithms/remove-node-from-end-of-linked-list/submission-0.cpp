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
        int count = 0;
        ListNode* temp = head;
        ListNode* prev = head;
        while(temp) {
            count++;
            temp =temp->next;
        }

        if(count == n) {
            return head->next;
        }

        int k = count - n - 1;

        while(k--) {
            prev = prev->next;
        }
        prev->next = prev->next->next; 

        return head;
    }
};
