/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);
        int carried=0;
        ListNode *p1=l1, *p2=l2;
        ListNode* cur=head;
        while(p1 || p2){
            int num1=p1 ? p1->val:0;
            int num2=p2 ? p2->val:0;
            cur->next=new ListNode((num1+num2+carried)%10);
            carried=(num1+num2+carried)/10;
            cur=cur->next;
            p1=p1?p1->next:NULL;
            p2=p2?p2->next:NULL;
        }
        cur->next=carried ? new ListNode(1):NULL;
        ListNode* res=head->next;
        delete head;
        return res;
    }
};