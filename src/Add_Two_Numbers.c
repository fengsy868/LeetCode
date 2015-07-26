/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* lresult = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* head = lresult;
    int carry = 0;
    int lval1, lval2;

    if(l1 == NULL | l2 == NULL)
    {
        printf("Input is NULL\n");
        return NULL;
    }

    lresult->val = (l1->val + l2->val + carry)%10;
    carry = (l1->val + l2->val) >= 10 ? 1: 0; 
    while(l1->next != NULL | l2->next != NULL)
    {
        struct ListNode* tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        
        if(l1->next != NULL) 
        {
            l1 = l1->next;
            lval1 = l1->val;
        }else 
        {lval1 = 0;}
        
        if(l2->next != NULL) 
        {
            l2 = l2->next;
            lval2 = l2->val;
        }else 
        {lval2 = 0;}
        
        tmp->val = (lval1 + lval2 + carry)%10;
        carry = (lval1 + lval2 + carry) >= 10 ? 1 : 0;
        tmp->next = NULL;
        
        lresult->next= tmp;
        lresult = lresult->next;
    }

    if(l1->next == NULL & l2->next == NULL & carry != 0)
    {
        struct ListNode* tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val = 1;
        tmp->next = NULL;
        lresult->next= tmp;
        lresult = lresult->next;
    }
    return head;
}

int main() {
    struct ListNode *l1 = (struct ListNode *)calloc(3, sizeof(struct ListNode));
    struct ListNode *p1 = l1;
    p1->val = 2;
    p1->next = p1 + 1;
    p1++;

    p1->val = 4;
    p1->next = p1 + 1;
    p1++;

    p1->val = 5;
    p1->next = NULL;

    struct ListNode *l2 = (struct ListNode *)calloc(5, sizeof(struct ListNode));
    struct ListNode *p2 = l2;
    p2->val = 5;
    p2->next = p2 + 1;
    p2++;

    p2->val = 6;
    p2->next = p2 + 1;
    p2++;

    p2->val = 4;
    p2->next = p2 + 1;
    p2++;

    p2->val = 9;
    p2->next = p2 + 1;
    p2++;

    p2->val = 9;
    p2->next = NULL;

    struct ListNode *p = addTwoNumbers(l1, l2);
    
    /* 542 + 99465 = 100007 */
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}