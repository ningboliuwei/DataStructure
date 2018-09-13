//
// Created by Liu Wei on 2018/9/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int IsEmptyStack(LinkStack *stack) {
    if (stack->top == NULL) {
        return 1;
    }
    return 0;
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

int NumberConvertion(int number, int scale) {
    LinkStack *stack = (LinkStack *) malloc(sizeof(LinkStack));

    InitStack(stack);

    while (number != 0) {
        int temp = number % scale;
        number = number / scale;
        Push(stack, temp);
    }

    printf("After conversion.");

    while (!IsEmptyStack(stack)) {
        int *topNumber = (int *) malloc(sizeof(int));

        Pop(stack, topNumber);

        printf("%d", *topNumber);
    }
}

int main() {
    int number = 0;
    int scale = 0;

    printf("Input a number.\n");
    scanf("%d", &number);
    printf("Input the scale.\n");
    scanf("%d", &scale);

    NumberConvertion(number, scale);

    getchar();
}