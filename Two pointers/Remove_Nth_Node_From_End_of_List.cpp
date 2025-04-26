#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // Dummy node chahya jo head ko point kre
    ListNode *Dummy = new ListNode(0);
    Dummy->next = head;

    ListNode *pointer1 = Dummy;
    ListNode *pointer2 = Dummy;
    for (int i = 0; i <= n; i++)
    {
        pointer2 = pointer2->next;
    }

    while (pointer2 != nullptr)
    {
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }

    ListNode *isDelete = pointer1->next;
    pointer1->next = pointer1->next->next;
    delete isDelete;

    return Dummy->next;
}

int main()
{
    cout << "Remove Nth Node From End of List" << endl;

    // Manually create the linked list [1,2,3,4,5]
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;

    cout << "Original List: ";
    printList(head);

    ListNode *result = removeNthFromEnd(head, n);

    cout << "After Removal: ";
    printList(result);

    return 0;
}