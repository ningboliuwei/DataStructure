//
// Created by Liu Wei on 2018/9/11.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNodeStruct {
    int data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) {
    stack->top = NULL;
}

int ReadTop(LinkStack *stack, int *x) {
    if (stack->top == NULL) {
        return 0;
    }

    *x = stack->top->data;

    return 1;
}


int Push(LinkStack *stack, int x) {
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

int Pop(LinkStack *stack, int *x) {
// 栈为空
    if (stack->top == NULL) {
        return 0;
    }

    StackNode *node = stack->top;
    *x = node->data;
    stack->top = node->next;
    free(node);

    return 1;
}


int ShowStack(LinkStack *stack) {
    printf("--------\n");
    StackNode *node;
    node = stack->top;

    while (node != NULL) {
        printf("%d", node->data);
        printf("\n");
        node = node->next;
    }

    printf("--------\n");
}

int main() {
    LinkStack *linkStack = (LinkStack *) malloc(sizeof(LinkStack));

    InitStack(linkStack);
    Push(linkStack, 1);
    Push(linkStack, 2);
    Push(linkStack, 3);

    int *x = (int *) malloc(sizeof(int));
    ReadTop(linkStack, x);
    printf("top: %d\n", *x);

    ShowStack(linkStack);

    Pop(linkStack, x);
    printf("Popped: %d\n", *x);
    Pop(linkStack, x);
    printf("Popped: %d\n", *x);
    Pop(linkStack, x);
    printf("Popped: %d\n", *x);

    if (ReadTop(linkStack, x)) {
        printf("top: %d\n", *x);
    } else {
        printf("empty stack");
    }

    ShowStack(linkStack);

    getchar();
}


