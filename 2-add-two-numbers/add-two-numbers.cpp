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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* T1=l1;
        ListNode* T2 =l2;
        int curr_sum;
        ListNode* head=new ListNode(0);
        int carry=0;
        ListNode*curr_node=head;
       while(T1!=NULL||T2!=NULL)
        {
             int val1 = (T1 != NULL) ? T1->val : 0;
            int val2 = (T2 != NULL) ? T2->val : 0;
             
             curr_sum=val1+val2;
            curr_sum+=carry;

            if(curr_sum<=9)
            {
                curr_node->val=curr_sum;
                carry=0;
            }
            else 
            {
                int temp=curr_sum/10;  
                temp=curr_sum-(temp*10);
                curr_node->val=temp;    //ones digit
                carry=1;
            }
             if(T1!=NULL)
            {
               T1=T1->next;
            }
            if (T2!=NULL)
            {
               T2=T2->next;
            }
            if(T1==NULL&&T2==NULL&&carry==0)
            break;
             if(T1==NULL&&T2==NULL&&carry!=0)
             {
                  curr_node->next=new ListNode(1);
                  break;
             }
            curr_node->next=new ListNode(0);
            curr_node=curr_node->next;
        }
        return head;
    }
};