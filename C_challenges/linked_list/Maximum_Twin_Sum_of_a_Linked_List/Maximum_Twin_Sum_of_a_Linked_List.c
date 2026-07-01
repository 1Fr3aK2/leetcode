#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverse(struct ListNode *head)
{
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    while (curr != NULL)
    {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int pairSum(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    int max = -1;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* second = reverse(slow);
    struct ListNode* first = head;
    while (second != NULL)
    {
        int twin = first->val + second->val;
        max = (twin > max) ? twin : max;
        first = first->next;
        second = second->next;
    }
    return max;
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;
    struct ListNode *temp = head; 
    for (int i = 2; i <= 8; i++)
    {
        struct ListNode *curr = (struct ListNode *)malloc(sizeof(struct ListNode));
        curr->val = i;
        curr->next = NULL;
        temp->next = curr;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("temp: %d  ", temp->val);
        temp = temp->next;
    }
    printf("\n");
    printf("max: %d\n", pairSum(head));
    
}