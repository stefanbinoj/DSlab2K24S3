#include<stdio.h>
#include<stdlib.h>

#define MAX 50
int que[MAX];
int front = -1, rear = -1;
void check(int n);
void insert(int n) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        que[front] = n;
    } 
    else if (rear == MAX - 1) {
        printf("Overflow\n");
    } 
    else {
        check(n);
        rear++;
    }
}

void check(int n) {
    int i, j;
    for (i = 0; i <= rear; i++) {
        // Insert at the appropriate position if the element has higher priority (larger value)
        if (n >= que[i]) {
            // Shift elements to make space
            for (j = rear; j >= i; j--) {
                que[j + 1] = que[j];
            }
            que[i] = n;
            return;
        }
    }
    // If no position was found, insert at the end
    que[rear + 1] = n;
}

void delete(int n) {
    int i, j;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    for (i = front; i <= rear; i++) {
        if (que[i] == n) {
            // Shift elements after deletion
            for (j = i; j < rear; j++) {
                que[j] = que[j + 1];
            }
            que[rear] = -99;  // Optional: Mark the last element as deleted (not necessary)
            rear--;

            if (rear == -1) {
                front = -1;
            }
            return;
        }
    }
    printf("Element not found\n");
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", que[i]);
    }
    printf("\n");
}

int main() {
    int n, ch;

    while (1) {
        printf("\n1 - Insert an element into queue\n");
        printf("2 - Delete an element from queue\n");
        printf("3 - Display queue elements\n");
        printf("4 - Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter value to be inserted: ");
                scanf("%d", &n);
                insert(n);
                break;

            case 2:
                printf("\nEnter value to delete: ");
                scanf("%d", &n);
                delete(n);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nIncorrect choice, please enter a valid choice.\n");
        }
    }

    return 0;
}
