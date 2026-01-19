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

// Brute Force Approach O(max(m,n)) time and O(max(m,n)) space 
class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};

// Challenge is that can we perform this in O(1) space
// Optimal Approach O(max(m,n)) time and O(1) space
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        int carry = 0;
        ListNode* head = NULL;
        ListNode* prev = NULL;
        while(l1 || l2) {
            sum = carry + (l1?l1->val:0) + (l2?l2->val:0);
            carry = (sum>=10)?1:0;
            int digit  = sum%10;
            ListNode* temp = new ListNode(digit);
            if(head == NULL) {
                head = temp;
                prev = head;
            } else {
                prev->next = temp;
            }
            prev = temp;
            
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        if(carry == 1) {
            ListNode* temp = new ListNode(1);
            prev->next = temp;
        }
        return head;
    }
};