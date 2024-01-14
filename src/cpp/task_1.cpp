/*
 * Author: Mukhammadkhon Asrorov
 * Date: 14/01/2024
 * Name: hw-10
 */

class Problem1 {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ptr1=head->next;
        ListNode *ptr2=head;
        int value=0;
        while(ptr1!=NULL)
        {
            if(ptr1->val==0)
            {
                ptr2->val=value;
                if(ptr1->next!=NULL)
                    ptr2=ptr2->next;
                value=0;
            }
            else
            {
                value=value+ptr1->val;
            }
            ptr1=ptr1->next;
        }
        ptr2->next=NULL;
        return head;
    }
};
