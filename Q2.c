/**
Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers (struct ListNode* l1, struct ListNode* l2)
{
  int carry=0;
  struct ListNode *head1, *head2, *head, *tmp;

  head1=l1;
  head2=l2;
  tmp=head=(struct ListNode *) malloc(sizeof(struct ListNode));

  while(l1!=0 || l2!=0 || carry)
  {
    carry=(l1?(l1->val):0) + (l2?(l2->val):0) + carry;
    tmp->val=carry%10;
    carry=carry/10;
    if(l1) l1=l1->next;
    if(l2) l2=l2->next;
    if(l1 || l2 || carry>0)
    {
      tmp->next=(struct ListNode *) malloc(sizeof(struct ListNode));
      tmp=tmp->next;
    }
    else
      tmp->next=0;
  }
  
  return head;
}
