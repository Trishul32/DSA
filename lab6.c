#define SIZE 100

typedef struct {
    int q[SIZE];
    int front;
    int rear;
} Queue;

typedef struct {
    Queue q1, q2;
} MyStack;


int isFull(Queue *q) {
    return (q->rear == SIZE - 1);
}

int isEmpty(Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->q[q->rear] = value;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int value = q->q[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1; 
        }
        return value; 
    }
}

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1.front = stack->q1.rear = -1;
    stack->q2.front = stack->q2.rear = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q2, x);
    while (!isEmpty(&obj->q1)) {
        int no = dequeue(&obj->q1);
        enqueue(&obj->q2, no);
    }
    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q1);
}

int myStackTop(MyStack* obj) {
    if (isEmpty(&obj->q1)) {
        printf("Stack is empty!\n");
        return -1; 
    }
    return obj->q1.q[obj->q1.front]; 
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(&obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}
