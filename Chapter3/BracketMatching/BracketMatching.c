//
// Created by Liu Wei on 2018/9/12.
//

//
// Created by Liu Wei on 2018/9/11.
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

int MatchBracket(char *exp) {
    int flag = 1;
    int i = 0;
    LinkStack *stack = (LinkStack *) malloc(sizeof(LinkStack));

    InitStack(stack);

    while (i < strlen(exp) && flag) {
        switch (exp[i]) {
            case '(': {
                Push(stack, exp[i]);
                i++;
                break;
            }
            case ')': {
                char *top = (char *) malloc(sizeof(char));
                ReadTop(stack, top);
                if (!IsEmptyStack(stack) && *top == '(') {
                    Pop(stack, top);
                    i++;
                } else {
                    flag = 0;

                }
                break;
            }
        }
    }

    // 遍历了栈中所有的括号
    if (flag && IsEmptyStack(stack)) {
        return 1;
    }

    return 0;
}

int MatchBracket2(char *exp) {
    int flag = 1;
    int i = 0;
    LinkStack *stack = (LinkStack *) malloc(sizeof(LinkStack));

    InitStack(stack);

    while (i < strlen(exp) && flag) {
        char current = exp[i];

        if (current == '(' || current == '[' || current == '{') {

            Push(stack, exp[i]);
            i++;

        } else {
            char *top = (char *) malloc(sizeof(char));
            ReadTop(stack, top);
            if (!IsEmptyStack(stack) &&
                ((*top == '(' && current == ')')
                 || (*top == '[' && current == ']')
                 || (*top == '{' && current == '}'))) {
                Pop(stack, top);
                i++;
            } else {
                flag = 0;
            }
        }
    }

    // 遍历了栈中所有的括号
    if (flag &&
        IsEmptyStack(stack)
            ) {
        return 1;
    }

    return 0;
}

int main() {
    char *exp = (char *) malloc(sizeof(char) * EXP_MAX_LENGTH);
    printf("Input brackets\n");
    gets(exp);

    if (MatchBracket2(exp)) {
        printf("Matching");
    } else {
        printf("Not matching");
    }

    getchar();
}


