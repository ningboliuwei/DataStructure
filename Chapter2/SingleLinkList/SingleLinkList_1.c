//
// Created by Liu Wei on 2018/9/4.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} Node, *LinkList;

// 头插法创建链表
LinkList CreateListF_L(LinkList linkList) {
    Node *newNode;
    int data = 0;

    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;
    linkList = head;

    while (1) {
        printf("Input a number, 0 to exit.");
        scanf("%d", &data);

        if (data != 0) {
            newNode = (Node *) malloc(sizeof(Node));
            newNode->data = data;
            newNode->next = head->next;
            head->next = newNode;
        } else {
            break;
        }
    }

    return linkList;
}

// 尾插法创建带头结点的链表
LinkList CreateListR_L(LinkList linkList) {
    Node *newNode;
    int data = 0;

    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;
    linkList = head;

    Node *tail = head;

    while (1) {
        printf("Input a number, 0 to exit.");
        scanf("%d", &data);

        if (data != 0) {
            newNode = (Node *) malloc(sizeof(Node));
            newNode->data = data;
            // 下一行代码不要漏掉
            newNode->next = NULL;
            tail->next = newNode;
            tail = newNode;
        } else {
            break;
        }
    }

    return linkList;
}


// 求带头结点的链表长度
int LengthList_L(LinkList linkList) {
    Node *p = linkList;

    int n = 0;
    while (p->next) {
        p = p->next;
        n++;
    }
    return n;
}

//显示带头结点的链表元素
void ShowList_L(LinkList linklist) {
    Node *p = linklist;

    while (p->next) {
        // 以下两行代码顺序不要颠倒
        p = p->next;
        printf("%d ", p->data);
    }
}

// 根据位置搜索链表中的元素
Node *SearchListByPos_L(LinkList linkList, int pos) {
    Node *p = linkList;
    int i = 0;

    while (p->next != NULL && i < pos) {
        p = p->next;
        i++;
    }

    if (i == pos) {
        return p;
    } else {
        return NULL;
    }
}

// 根据某元素搜索在链表中的位置
int SearchListByElement_L(LinkList linkList, int element) {
    Node *p = linkList->next;
    int pos = 1;

    while (p != NULL && p->data != element) {
        p = p->next;
        pos++;
    }

    if (p->data == element) {
        return pos;
    } else {
        return -1;
    }
}

// 删除链表中指定位置的元素
int DelList_L(LinkList linkList, int pos) {
    Node *p = linkList;
    int index = 0;

    while (p->next != NULL && index < pos - 1) {
        p = p->next;
        index++;
    }

    if (p->next == NULL || index > pos - 1) {
        return -1;
    } else {
        Node *q = p->next;
        p->next = q->next;
        free(q);

        return 1;
    }
}

// 我自己的写法
int DelList_L2(LinkList linkList, int pos) {
    Node *p = linkList;
    int index = 0;

    if (pos <= 0 || pos > LengthList_L(linkList)) {
        return -1;
    }

    // 这里的 p->next == NULL 判定可以精简吗？
    while (index < pos - 1) {
        p = p->next;
        index++;
    }

    Node *q = p->next;
    p->next = q->next;
    free(q);

    return 1;
}


int main() {
    LinkList linkList = CreateListR_L(linkList);

    printf("\n");
    printf("The elements of the linklist:");
    ShowList_L(linkList);
    printf("\n");

    int length = LengthList_L(linkList);
    printf("\n");
    printf("The length of the linklist is %d.", length);
    printf("\n");

//    printf("\n");
//    printf("Input a index you want to search.");
//    printf("\n");
//
//    int index = 0;
//    scanf("%d", &index);
//    Node *result = SearchListByPos_L(linkList, index);
//    printf("The found element is %d", result->data);
//
//    printf("\n");
//    printf("Input a element you want to search.");
//    printf("\n");
//
//    int element = 0;
//    scanf("%d", &element);
//    int pos = SearchListByElement_L(linkList, element);
//
//    printf("\n");
//    printf("The found position is %d", pos);

    int pos;
    printf("\n");
    printf("Input the position of element you want to delete");
    scanf("%d", &pos);
    int q = DelList_L2(linkList, pos);

    printf("%d\n", q);
    printf("The elements of the linklist after deletion:");
    ShowList_L(linkList);
    printf("\n");

    getchar();
}

