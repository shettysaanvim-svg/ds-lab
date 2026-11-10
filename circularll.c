#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, i, val;

    printf("Enter number of nodes: ");

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);

        if (scanf("%d", &val) != 1) {
            printf("Invalid data input.\n");
            return 1;
        }

        newNode = malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        newNode->data = val;

        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("Circular Linked List: ");

    if (head != NULL) {
        temp = head;

        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);

        printf("(head)\n");
    } else {
        printf("Empty List\n");
    }

    while (head != NULL) {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = head->next;
            free(head);
            head = temp->next;
        }
    }

    return 0;
}