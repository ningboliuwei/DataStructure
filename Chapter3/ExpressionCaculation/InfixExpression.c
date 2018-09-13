//
// Created by Liu Wei on 2018/9/13.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXP_MAX_LENGTH 20

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

char *Infix2Suffix(char *expression) {
    LinkStack *stack = (LinkStack *) malloc(sizeof(LinkStack));
    char result[EXP_MAX_LENGTH];

    InitStack(stack);

    for (int i = 0; i < strlen(expression); i++) {
        if ()
    }
}

int GetLevel(char op){
    if (op)
}

int main() {
    char *expression = (char *) malloc(sizeof(char) * EXP_MAX_LENGTH);

    printf("Input a infix expression.\n");
    gets(expression);
    puts(expression);
}