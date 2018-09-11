//
// Created by Liu Wei on 2018/9/7.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 10

typedef struct StackNode {
    // 用于存放栈元素的数组
    int data[MAX_LENGTH];
    // 栈顶元素的位置
    int top;
} *SeqStack;

int InitStack(SeqStack *s) {
    // 注意 sizeof 的对象
    *s = (SeqStack) malloc(sizeof(struct StackNode));
    (*s)->top = -1;

    return 1;
}

// 判断栈是否是空栈
int IsEmpty(SeqStack s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

////若栈不空，则用 x 返回 s 的栈顶元素，并返回 1，否则返回 0
int ReadTop(SeqStack s, int *x) {
    if (IsEmpty(s) == 1) {
        return 0;
    }

    *x = s->data[s->top];

    return 1;
}
//
//// 若栈不空，则删除st的栈顶元素，用x返回其值，
//// 并返回1；否则返回0
int Pop(SeqStack *s, int *x) {
    if (IsEmpty(*s) == 1) {
        return 0;
    }

    *x = (*s)->data[(*s)->top];
    (*s)->top--;

    return 1;
}

int Push(SeqStack *s, int x) {
    if ((*s)->top == MAX_LENGTH - 1) {
        return 0;
    } else {
        (*s)->top++;
        (*s)->data[(*s)->top] = x;

        return 1;
    }
}

int ShowStack(SeqStack s) {
    printf("--------\n");

    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }

    printf("--------\n");
}

int main() {
    SeqStack *s = (SeqStack *) malloc(sizeof(struct StackNode));
    InitStack(s);

    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    Push(s, 4);

    ShowStack(*s);

    // malloc 不能省略
    int *result = (int *) malloc(sizeof(int));

    Pop(s, result);
    printf("Popped: %d\n", *result);
    Pop(s, result);
    printf("Popped: %d\n", *result);

    ReadTop(*s, result);
    printf("Top: %d\n", *result);

    ShowStack(*s);
}
