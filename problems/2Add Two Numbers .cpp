#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
     struct ListNode *p, *q;
    p = (struct ListNode*) malloc(sizeof(struct ListNode));
    q = p;
    int cnt = 0, sum = 0, flag = 0;
    while(l1 != NULL) {
        if(l2 == NULL) flag = 1;
        if(!flag)
            sum = l1->val + l2->val + cnt;
        else
            sum = l1->val + cnt;
        cnt = sum/10;
        q->val = sum%10;
        if(l1->next != NULL) {
            q->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            q = q->next;
        } else q->next = NULL;
        l1 = l1->next;
        if(!flag)
            l2 = l2->next;  
    }

    while(l2 != NULL) {
        sum = l2->val + cnt;
        cnt = sum/10;
        q->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        q = q->next;
        q->val = sum%10;
        q->next = NULL;
        l2 = l2->next;
    }

    if(cnt > 0) {
        q->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        q = q->next;
        q->val = cnt;
        q->next = NULL;
    }

    return p; 
}
