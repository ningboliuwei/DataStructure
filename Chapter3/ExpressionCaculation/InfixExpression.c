//
// Created by Liu Wei on 2018/9/13.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXP_MAX_LENGTH 20

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

int ReadTop(LinkStack *stack, char *topElement) {
    if (stack->top == NULL) {
        return 0;
    }

    *topElement = stack->top->data;

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


int GetOperatorLevel(char op) {
    if (op == '#') {
        return 0;
    }

    if (op == '(' || op == ')') {
        return 1;
    }

    if (op == '+' || op == '-') {
        return 2;
    }

    if (op == '*' || op == '/') {
        return 3;
    }

    return -1;
}

int ShowStack(LinkStack *stack) {
    StackNode *node;
    node = stack->top;

    while (node != NULL) {
        printf("%c\n", node->data);
        node = node->next;
    }

    printf("--------\n");
}

int Infix2Suffix(char *expression, char *result) {
    LinkStack *stack = (LinkStack *) malloc(sizeof(LinkStack));
    char index = 0;
    char *topElement = (char *) malloc(sizeof(char));

    InitStack(stack);

    for (int i = 0; i < strlen(expression); i++) {
        char current = expression[i];

        // 非运算符
        if (GetOperatorLevel(current) == -1) {
            result[index] = current;
            index++;
        }// 运算符
        else {
            ShowStack(stack);

            if (current == '(') {
                Push(stack, current);
            } else if (current == ')') {
                do {
                    Pop(stack, topElement);

                    if (*topElement != '(') {
                        result[index] = *topElement;
                        index++;
                    }
                } while (*topElement != '(');
            } else {
                ReadTop(stack, topElement);

                if (GetOperatorLevel(current) > GetOperatorLevel(*topElement)) {
                    Push(stack, current);
                } else {
                    Pop(stack, topElement);
                    result[index] = *topElement;
                    index++;

                    ReadTop(stack, topElement);

                    if (GetOperatorLevel(current) > GetOperatorLevel(*topElement)) {
                        Push(stack, current);
                    }
                }
            }
        }
    }
    while (!IsEmptyStack(stack)) {
        Pop(stack, topElement);

        if (*topElement != ')') {
            result[index] = *topElement;
            index++;
        }
    }

    result[index] = '\n';

    return 1;
}

int main() {
    char *expression = (char *) malloc(sizeof(char) * EXP_MAX_LENGTH);
    char result[EXP_MAX_LENGTH];

    printf("Input a infix expression.\n");
    gets(expression);
    Infix2Suffix(expression, result);
    puts(result);
    getchar();
}