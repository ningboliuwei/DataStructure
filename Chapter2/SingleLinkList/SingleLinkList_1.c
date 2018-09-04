//
// Created by Liu Wei on 2018/9/4.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

//头插法创建链表
LinkList CreateListF_L(LinkList head) {
    LinkList s;
    int x;

    head = malloc(sizeof(Node));
    head->next = NULL;

    printf("please input a character, press x to exit\n");
    while (1) {
        scanf("%d", &x);

        if (x != 0) {
            s = malloc(sizeof(Node));
            s->data = x;
            s->next = head->next;
            head->next = s;
        } else {
            break;
        }
    }
    return head;
}

//求表长（带头结点的链表）
int LengthLst_L(LinkList head) {
    LinkList p = head;

    int n = 0;
    while (p->next) {
        p = p->next;
        n++;
    }
    return n;
}

int main() {
    LinkList linkList = NULL;
    linkList = CreateListF_L(linkList);
    int length = 0;
    length = LengthLst_L(linkList);
    printf("%d", length);
    getchar();
}

