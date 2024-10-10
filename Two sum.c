#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
void List1(struct node** head, int data) {
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    if (NewNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    NewNode->data = data;
    NewNode->next = *head;
    *head = NewNode;
}
void List2(struct node** head, int data) {
    struct node* NewNode = (struct node*)malloc(sizeof(struct node));
    if (NewNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    NewNode->data = data;
    NewNode->next = *head;
    *head = NewNode;
}
void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct node* addLists(struct node* head1, struct node* head2) {
    struct node* result = NULL;
    struct node* temp1 = head1;
    struct node* temp2 = head2;
    while (temp1 != NULL || temp2 != NULL) {
        int sum = 0;
        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        struct node* NewNode = (struct node*)malloc(sizeof(struct node));
        NewNode->data = sum;
        NewNode->next = result;
        result = NewNode;
    }
    return result;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    struct node* resultList = NULL;
    int choice, data;

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add to List1\n");
        printf("2. Add to List2\n");
        printf("3. Display List1\n");
        printf("4. Display List2\n");
        printf("5. Add and Display Result List (List1 + List2)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to add to List1: ");
                scanf("%d", &data);
                List1(&head1, data);
                break;
            case 2:
                printf("Enter data to add to List2: ");
                scanf("%d", &data);
                List2(&head2, data);
                break;
            case 3:
                printf("List1: ");
                printList(head1);
                break;
            case 4:
                printf("List2: ");
                printList(head2);
                break;
            case 5:
                resultList = addLists(head1, head2);
                printf("Result (List1 + List2): ");
                printList(resultList);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
