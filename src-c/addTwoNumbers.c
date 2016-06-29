#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* p = l1, q = l2;
	struct ListNode* head = new ListNode(0);
	// struct ListNode* pre1 = NULL;
	// struct ListNode* pre2 = NULL;
	// int flag = 0;

	// while (l1 != NULL && l2 != NULL) {
	// 	pre1 = l1;
	// 	pre2 = l2;
	// 	int i = l1->val + l2->val + flag;
	// 	if (i >= 10)
	// 		flag = 1;
	// 	else
	// 		flag = 0;
	// 	l1->val = i % 10;
	// 	l1 = l1 -> next;
	// 	l2 = l2 -> next;

	// }

	// if (l1 != NULL && flag > 0)
	// 	l1->val = l1->val + flag;
	// else if(l2 != NULL) {
	// 	if (flag > 0)
	// 		l2->val = l2->val + flag;
	// 	pre1->next = l2;
	// }

	// return p;
}

int main(int argc, char** argv) {
	struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode) * 3);
	struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode) * 3);

	struct ListNode* p = l1;
	int i = 0;

	while(i < 3) {
		p->val = 
	}

	return 0;
}
