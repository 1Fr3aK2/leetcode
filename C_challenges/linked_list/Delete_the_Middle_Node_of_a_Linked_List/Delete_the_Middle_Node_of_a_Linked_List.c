#include <stdlib.h>
#include <stdio.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* curr = head;

    if (!head || !head->next)
        return NULL;
    while (fast && fast->next)
    {
        curr = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    curr->next = slow->next;
    return head;
}

int main()
{
    struct ListNode* head = (struct ListNode *)malloc(sizeof(struct ListNode *));
    head->val = 1;
    head->next = NULL;
    struct ListNode* temp = head;
    for (int i = 2; i < 8; i++)
    {
        struct ListNode* curr = (struct ListNode *)malloc(sizeof(struct ListNode *));
        curr->val = i;
        curr->next = NULL;
        temp->next = curr;
        temp = temp->next;
    }
    temp = head;
    printf("head before F():\n");
    while (temp != NULL)
    {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
    head = deleteMiddle(head);
    printf("head after F():\n");
    while (head != NULL)
    {
        printf("%d\n", head->val);
        head = head->next;
    }

}