#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGTH 10
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN


typedef struct {
    int values[STACK_LENGTH];
    int top;
} stack;


bool push(stack *mystack, int value) {
    if (mystack->top >= STACK_LENGTH-1) return false;

    mystack->top++;
    mystack->values[mystack->top] = value;
    return true;
}

int pop(stack *mystack) {
    if (mystack->top == EMPTY) return STACK_EMPTY;

    int result = mystack->values[mystack->top];
    mystack->top--;
    return result;
}

int main() {
    stack s1;
    s1.top = EMPTY;
    stack s2;
    s2.top = EMPTY;
    stack s3;
    s3.top = EMPTY;

    push(&s1, 56);
    push(&s2, 78);
    push(&s2, 178);
    push(&s2, 8);
    push(&s3, 13);

    int t;
    while ((t = pop(&s2)) != STACK_EMPTY) {
    printf("t = %d\n",t);
    }
}