#include <stdio.h>
#include <conio.h>

void push(int);
int pop();
void display();
int SIZE = 5;
int arr[5];
int top = -1;

void main() {
    while(1) {
        int c;
        printf("Enter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display\n");
        printf("Enter 4 to break\n");
        scanf("%d", &c);

        if(c == 1) {
            int a;
            printf("Enter the element to push\n");
            scanf("%d", &a);
            push(a);
        } else if(c == 2) {
            int x = pop();
            if(x != -1) {
                printf("The popped element is %d\n", x);
            }
        } else if(c == 3) {
            display();
        } else {
            break;
        }
    }
}

void push(int val) {
    if(top == SIZE - 1) {
        printf("Stack Overflow! Cannot add more elements.\n");
        return;
    }
    top = top + 1;
    arr[top] = val;
    printf("Pushed %d onto the stack\n", val);  // To confirm push action
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1;
    }
    int val = arr[top];
    top--;
    return val;
}

void display() {
    if(top == -1) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack contents from top to bottom:\n");
    int i = top;
    while(i >= 0) {
        printf("%d\n", arr[i]);
        i--;
    }
}
