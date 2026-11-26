/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        unordered_map<Node*,Node*> m;
        Node* NewHead = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = NewHead;
        m[head] = NewHead;

        while(oldtemp != nullptr){
            Node* copynode = new Node(oldtemp->val);
            m[oldtemp] = copynode;
            newtemp->next = copynode;
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        oldtemp = head;
        newtemp = NewHead;
        while(oldtemp != nullptr){
            newtemp->random = m[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        return NewHead;
        
        
    }
};
