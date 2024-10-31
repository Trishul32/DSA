#include <stdio.h>
#define MAX 5
int queue[MAX];

void Insert(int* front, int* rear);
void Delete(int* front, int* rear);
void Display(int* front, int* rear);

int main() {
    int front,rear=-1;
    
    int option;

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                Insert(&front, &rear);
                break;
            case 2:
                Delete(&front, &rear);
                break;
            case 3:
                Display(&front, &rear);
                break;
            case 4:
		return 0;
            default:
                printf("Invalid option!\n");
                break;
        }
    }
}

void Insert(int* front, int* rear) {
    if (*rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (*front == -1 && *rear==-1) {
        *front = 0;
    }

    int val;
    printf("Enter the value: ");
    scanf("%d", &val);

    queue[++(*rear)] = val;
}

void Delete(int* front, int* rear) {
    if (*front == -1 || *front > *rear) {
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[*front]);
    (*front)++;
}

void Display(int* front, int* rear) {
    if (*front == -1 || *front > *rear) {
        printf("Empty queue\n");
        return;
    }

    printf("\n Elements in Queue are :  ");
    for (int i = *front; i <= *rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


