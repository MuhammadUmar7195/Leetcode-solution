#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Brute Force Approach where space is O(n) and time is O(n) also.
class Solution {
public:
    void reorderList(ListNode* head) {
        
        vector<ListNode*> nodes;
        ListNode* curr = head;

        while(curr){
            nodes.push_back(curr);
            curr = curr->next;
        }

        int i = 0, j = nodes.size() - 1;
        while(i < j){
            nodes[i]->next = nodes[j];
            i++;
            if(i >= j) break;
            nodes[j]->next = nodes[i];
            j--;
        }

        nodes[i]->next = nullptr;
    }
};

// Optimal Approach where space is O(1) and time is O(n).
class Solution {
public:
    void reorderList(ListNode* head) {
        // Base case
        if(head == nullptr || head->next == nullptr)
            return;
        
        // Find the midpoint of List using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr; 
        
        while(curr != nullptr){
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        // Now prev is the head of reversed second half
        ListNode* secondHalf = prev;
        ListNode* firstHalf = head;
        
        // Merge the two halves
        while(secondHalf != nullptr){
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;
            
            firstHalf->next = secondHalf;
            secondHalf->next = temp1;
            
            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};
