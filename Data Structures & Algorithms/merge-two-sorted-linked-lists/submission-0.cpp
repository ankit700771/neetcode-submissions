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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* ans = new ListNode();
        ListNode* ansptr = ans;

        while(curr1 != NULL && curr2 != NULL) {

            if(curr1->val <= curr2->val) {
                ListNode* temp = new ListNode(curr1->val);
                ansptr->next = temp;
                ansptr = temp;
                curr1 = curr1->next;
            } else {
                ListNode* temp = new ListNode(curr2->val);
                ansptr->next = temp;
                ansptr = temp;
                curr2 = curr2->next;
            }
        }

        while(curr1 != NULL) {
            ListNode* temp = new ListNode(curr1->val);
            ansptr->next = temp;
            ansptr = temp;
            curr1 = curr1->next;
        } 

        while(curr2 != NULL) {
            ListNode* temp = new ListNode(curr2->val);
            ansptr->next = temp;
            ansptr = temp;
            curr2 = curr2 -> next;
        }

        return ans->next;
    }
};
