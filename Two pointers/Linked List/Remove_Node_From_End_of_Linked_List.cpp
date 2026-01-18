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

//Brute Force Approach O(n) time and O(n) space
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* curr = head;

        while(curr != nullptr){
            nodes.push_back(curr);
            curr = curr->next;
        }

        int removedIndex = nodes.size() - n;

        //if we found removedIdx 0 found
        if(removedIndex == 0){
            return head->next;
        }

        nodes[removedIndex - 1]->next = nodes[removedIndex]->next;
        return head;
    }
};

//Optimal Approach using two pointers O(n) time and O(1) space
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);   
        ListNode* left = dummy;
        ListNode* right = head;

        //Place the right pointer to the nth place 
        while(n > 0){
            right = right->next;
            n--;
        }

        // ab right pointer ko last tk le kr jao 
        while(right != nullptr){
            left = left->next;
            right = right->next;
        }

        //Ab ham na left wala pointer ko attack krna ha 2nd place pointer ka saat
        left->next = left->next->next;

        return dummy->next;
    }
};
