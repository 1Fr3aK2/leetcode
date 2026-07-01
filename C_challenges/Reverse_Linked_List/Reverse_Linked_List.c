#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* curr;
    struct ListNode* prev = NULL;
    curr = head;
    while (curr != NULL)
    {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
    res->next = NULL;
    res->val = 1;
    struct ListNode *temp = res;
    for (int i = 2; i <= 5; i++)
    {
        struct ListNode *curr = (struct ListNode *)malloc(sizeof(struct ListNode));
        curr->val = i;
        curr->next = NULL;
        temp->next = curr;
        printf("%d  ", temp->val);
        temp = temp->next;
        printf("next: %d  ", temp->val);
    }
    printf("\n");
    for (struct ListNode* temp1 = res; temp1 != NULL; temp1 = temp1->next)
    {
        printf("res: %d  ", temp1->val);
    }
    printf("\n");
    printf("final: \n");
    res = reverseList(res);
    printf("aqui\n");
    while (res != NULL)
    {
        printf("res: %d  ", res->val);
        res = res->next;
    }
}