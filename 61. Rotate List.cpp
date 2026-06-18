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
    ListNode*helper(ListNode*head,int k){
        ListNode*temp=head;
        int count=1;
        while(temp){
            if(count==k) return temp;
            count++;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        ListNode*tail=head;
        int len=1;
        while(tail->next){
            len++;
            tail=tail->next;
        }
        k=k%len;
        if(k==0) return head;
        tail->next=head;
        ListNode*newLast=helper(head,len-k);
        head=newLast->next;
        newLast->next=NULL;
        return head;
        
    }
};