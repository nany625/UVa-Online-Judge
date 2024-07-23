#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
    int data;
    struct listNode *next;
} ListNode;

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        if(n == 1)
            puts("Discarded cards:\nRemaining card: 1");
        else {
            fputs("Discarded cards:", stdout);
            ListNode *head = (ListNode*)malloc(sizeof(ListNode));
            head->data = 1;
            head->next = NULL;
            ListNode *tail = head;
            for(int i = 2; i <= n; ++i) {
                ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
                newNode->data = i;
                newNode->next = NULL;
                tail->next = newNode;
                tail = newNode;
            }
            while(head->next->next) {
                printf(" %d,", head->data);
                ListNode *temp = head;
                head = head->next;
                free(temp);
                temp = head;
                head = head->next;
                temp->next = NULL;
                tail->next = temp;
                tail = temp;
            }
            printf(" %d\nRemaining card: %d\n", head->data, head->next->data);
            ListNode *temp = head;
            head = head->next;
            free(temp);
            free(head);
        }
    }
    return 0;
}
