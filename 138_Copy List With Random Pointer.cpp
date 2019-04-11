/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*>mp;
    Node *copyRandomList(Node *head) 
    {
        if(!head) return NULL;
        if(mp[head]!=NULL) return mp[head];
        mp[head] = new Node(head->val);
        mp[head] -> next = copyRandomList(head->next);
        mp[head] -> random = copyRandomList(head->random);
        return mp[head];
    }
};