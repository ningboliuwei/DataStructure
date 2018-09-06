//
// Created by Liu Wei on 2018/9/6.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct DoubleLinkNode {
    int data;
    struct DoubleLinkNode *previous;
    struct DoubleLinkNode *next;
} DoubleNode, *DoubleLinkList;

// 尾插法创建带头结点的双向链表
DoubleLinkList CreateListR_L(DoubleLinkList DoubleLinkList) {
    DoubleNode *newDoubleNode;
    int data = 0;

    DoubleNode *head = (DoubleNode *) malloc(sizeof(DoubleNode));
    head->next = NULL;
    head->previous = NULL;
    DoubleLinkList = head;

    DoubleNode *tail = head;

    while (1) {
        printf("Input a number, 0 to exit.");
        scanf("%d", &data);

        if (data != 0) {
            newDoubleNode = (DoubleNode *) malloc(sizeof(DoubleNode));
            newDoubleNode->data = data;
            newDoubleNode->previous = tail;
            // 下一行代码不要漏掉
            newDoubleNode->next = NULL;
            tail->next = newDoubleNode;
            tail = newDoubleNode;
        } else {
            break;
        }
    }

    return DoubleLinkList;
}

//显示带头结点的链表元素
void ShowList_L(DoubleLinkList doubleLinkList) {
    DoubleNode *p = doubleLinkList;

    while (p->next) {
        // 以下两行代码顺序不要颠倒
        p = p->next;
        printf("%d ", p->data);
    }
}

int main() {
    DoubleLinkList doubleLinkList = CreateListR_L(doubleLinkList);

    printf("\n");
    printf("The elements of the linklist:");
    ShowList_L(doubleLinkList);
    printf("\n");
}