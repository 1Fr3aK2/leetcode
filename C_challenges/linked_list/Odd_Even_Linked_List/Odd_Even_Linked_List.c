#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head)
{
    if (!head || !head->next)
        return (head);
    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* curr = even;
    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = curr;
    return head;
}


int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;
    struct ListNode *temp = head;
    for (int i = 2; i <= 6; i++)
    {
        struct ListNode *curr = (struct ListNode *)malloc(sizeof(struct ListNode));
        curr->val = i;
        curr->next = NULL;
        temp->next = curr;
        temp = temp->next;
    }
    head = oddEvenList(head);
    temp = head;
    while (temp != NULL)
    {
        printf("temp: %d  ", temp->val);
        temp = temp->next;
    }
    printf("\n");

}