//
// Created by Liu Wei on 2018/9/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXP_MAX_LENGTH 100

typedef struct StackNodeStruct {
    char data;
    struct StackNodeStruct *next;
} StackNode;

typedef struct {
    StackNode *top;
} LinkStack;

void InitStack(LinkStack *stack) {
    stack->top = NULL;
}

int ReadTop(LinkStack *stack, char *x) {
    if (stack->top == NULL) {
        return 0;
    }

    *x = stack->top->data;

    return 1;
}


int Push(LinkStack *stack, char x) {
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
    node->data = x;
    node->next = stack->top;
    stack->top = node;
}

int Pop(LinkStack *stack, char *x) {
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
    StackNode *node;
    node = stack->top;

    while (node != NULL) {
        printf("%c", node->data);
        node = node->next;
    }
}

void ClearStack(LinkStack *stack) {
    StackNode *node = stack->top;
    char *c = (char *) malloc(sizeof(char));

    while (IsEmptyStack(stack)) {
        Pop(stack, c);
    }

    printf("--------\n");
}

void LineEdit() {
    LinkStack *stack = (LinkStack *) malloc(sizeof(LinkStack));
    InitStack(stack);

    char ch = getchar();

    while (ch != EOF) {
        while (ch != EOF && ch != '\n') {
            char *topch = (char *) malloc(sizeof(char));

            if (ch == '#') {
                Pop(stack, topch);
            }

            if (ch == '@') {
                ClearStack(stack);
            }

            Push(stack, ch);
            ch = getchar();
        }
        ClearStack(stack);

        if (ch != EOF) {
            ch = getchar();
        }
    }

    ShowStack(stack);

}

int main() {
    LineEdit();
    getchar();
}
