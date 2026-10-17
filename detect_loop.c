// Detect Loop in Linked List - Qualcomm Embedded
// Floyd Cycle Detection
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("Loop detected!\n");
            return 1;
        }
    }
    printf("No loop\n");
    return 0;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    // head->next->next->next = head->next; // Uncomment to create loop
    
    detectLoop(head);
    return 0;
}