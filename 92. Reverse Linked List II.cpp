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
     ListNode*reverseLL(ListNode*head){
        if(!head) return NULL;
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr){
            ListNode*front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       if(!head) return NULL;
       if(!head->next ||  left==right) return head;
       ListNode*dummy=new ListNode(0);
       dummy->next=head;
       ListNode*prev=dummy;
       ListNode*curr=head;
       for(int i=1;i<left;i++){
        prev=prev->next;
       }
       ListNode*leftn=prev->next;
       ListNode*rightn=dummy;
       for(int i=0;i<right;i++){
        rightn=rightn->next;
       }
       ListNode*front=rightn->next;
       rightn->next=NULL;
       prev->next=NULL;
       ListNode*newSubHead=reverseLL(leftn);
       prev->next=newSubHead;
       leftn->next=front;
       return dummy->next;

    }
};