class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr; //base case

        //we store purana node ka address or new node ka address in upcoming loop
        unordered_map<Node*, Node*> map; 

        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = head;

        map[head] = newHead;
        
        newTemp = newHead;

        // Creating copy nodes and mapping old nodes to new nodes
        while(oldTemp != nullptr){
            Node* copyNode = new Node(oldTemp->val);
            map[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;

        // Setting up random pointers for the copied nodes
        while(oldTemp != nullptr){
            newTemp->random = map[oldTemp->random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }

        return newHead;
    }
};