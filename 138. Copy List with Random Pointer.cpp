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
    void insertBetween(Node*head){
        Node*temp=head;
        while(temp){
            Node*copy=new Node(temp->val);
            Node*nextNode=temp->next;
            copy->next=temp->next;
            temp->next=copy;
            temp=nextNode;
        }
        
    }
    void copyRandom(Node*head){
        Node*temp=head;
        while(temp){
            Node*copy=temp->next;
            if(temp->random){
                copy->random=temp->random->next;
            }else{
                copy->random=nullptr;
            }
            temp=temp->next->next;
        }
    
    }
    Node* getDeepCopy(Node*head){
        Node*temp=head;
        Node*dummyNode=new Node(-1);
        Node*res=dummyNode;
        while(temp){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }
    Node* copyRandomList(Node* head) {
        insertBetween(head);
        copyRandom(head);
        return getDeepCopy(head);
        
    }
};