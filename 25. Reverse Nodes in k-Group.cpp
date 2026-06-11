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
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp){
            ListNode*nextNode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextNode;
        }
        return prev;
    }
    ListNode*getKthNode(ListNode*temp,int k){
        k-=1;
        while(temp && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode*temp=head;
        ListNode*prevLast=NULL;
        while(temp){
            ListNode*kthNode=getKthNode(temp,k);
            if(!kthNode){
                if(prevLast) prevLast->next=temp;
                break;
            }
            ListNode*nextNode=kthNode->next;
            kthNode->next=NULL;
            reverseLL(temp);
            if(temp==head) head=kthNode;
            else{
                if(prevLast) prevLast->next=kthNode;
            }
            prevLast=temp;
            temp=nextNode;
        }
        return head;
    }
};