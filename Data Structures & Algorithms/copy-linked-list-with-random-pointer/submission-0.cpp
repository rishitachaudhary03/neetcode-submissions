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
        unordered_map <Node*,Node*> oldtonew;
        oldtonew[NULL]=NULL;
        Node* cur=head;
        while(cur != nullptr){
            Node* copy =new Node(cur->val);
            oldtonew[cur]= copy;
            cur=cur->next;
        }
        cur = head;
        while(cur !=nullptr){
            Node* copy = oldtonew[cur];
            copy->next=oldtonew[cur->next];
            copy->random=oldtonew[cur->random];
            cur =cur->next;
        }
        return oldtonew[head];
    }
};
