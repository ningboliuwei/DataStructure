//
// Created by Liu Wei on 2018/9/6.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

typedef struct {
    int data[MAX_LENGTH];
    int last;
} SeqList;

SeqList *CreateList_Seq() {
    SeqList *list = (SeqList *) malloc(sizeof(SeqList));
    // 空表时，list->last 设为 -1
    list->last = -1;

    return list;
}

int InsList_Seq(SeqList *list, int pos, int newElement) {
    int index;

    // 当前线性表已满，不允许插入
    if (list->last == MAX_LENGTH - 1) {
        return 0;
    }
    // 判断插入位置（pos）是否合法
    if (pos < 1 || pos > list->last + 2) {
        return 0;
    }

    for (index = list->last; index >= pos - 1; index--) {
        list->data[index + 1] = list->data[index];
    }

    list->data[pos - 1] = newElement;
    list->last++;

    return 1;
}

int DelList_Seq(SeqList *list, int pos) {
    int index = 0;

    // 空表，不允许删除
    if (list->last == -1) {
        return 0;
    }
    // 判断删除位置（pos）是否合法
    if (pos < 1 || pos > list->last + 2) {
        return 0;
    }

    for (index = pos - 1; index < list->last; index++) {
        list->data[index] = list->data[index + 1];
    }

    list->last--;

    return 1;
}

// 得到顺序表的长度
int LengthList_Seq(SeqList *list) {
    return list->last + 1;
}

//显示带头结点的顺序表元素
void ShowList_Seq(SeqList *list) {
    for (int i = 0; i <= list->last; i++) {
        printf("%d ", list->data[i]);
    }
}

// 有问题的查找版本
int SearchListByElement_Seq(SeqList *list, int element) {
    int index = 0;

    // 如果不加 index <= list->last，则会导致无限循环
    // 指针法直接改为 *p++ != element
    while (index <= list->last && list->data[index] != element) {
        index++;
    }

    // 思路：如果到最后一个还没找到，就是不存在这个要找的元素
    if (index <= list->last) {
        return index + 1;
    } else {
        return -1;
    }
}

void CommonElements(SeqList *list1, SeqList *list2, SeqList *resultList) {
    int i = 0;
    int j = 0;

    for (i = 0; i < list1->last; i++) {
        // 不写下一行会怎么样？
        j = 0;

        while (j < list2->last && list2->data[j] != list1->data[i]) {
            j++;
        }

        if (j <= list2->last) {
            resultList->data[resultList->last + 1] = list1->data[i];
            resultList->last++;
        }
    }
}

void CommonElementsUsingFunction(SeqList *list1, SeqList *list2, SeqList *resultList) {
    int i = 0;
    int j = 0;

    for (i = 0; i <= list1->last; i++) {

        if (SearchListByElement_Seq(list2, list1->data[i]) != -1) {
            InsList_Seq(resultList, resultList->last + 2, list1->data[i]);
        }
    }
}

void InputElements(SeqList *list) {
    int data = 0;

    while (1) {
        printf("Input a number, 0 to exit.");
        scanf("%d", &data);

        if (data != 0) {
            // 注意下一行的 last + 2，也就是在当前最后一个元素的后面位置插入
            InsList_Seq(list, list->last + 2, data);
        } else {
            break;
        }
    }

    printf("\n");
    printf("The elements of the sequence list:");
    ShowList_Seq(list);
    printf("\n");
}


void GetCommonElements() {
    SeqList *list1 = CreateList_Seq();
    SeqList *list2 = CreateList_Seq();
    SeqList *resultList = CreateList_Seq();

    InputElements(list1);
    InputElements(list2);

    CommonElementsUsingFunction(list1, list2, resultList);

    printf("\n");
    printf("The common elements: ");
    ShowList_Seq(resultList);
    printf("\n");
}

int MergeList(SeqList *list1, SeqList *list2, SeqList *resultList) {
    int i = 0;
    int j = 0;

    while (i <= list1->last) {
        while (j <= list2->last) {
            if (list1->data[i] < list2->data[j]) {
                InsList_Seq(resultList, resultList->last + 2, list1->data[i]);
                i++;
            } else {
                InsList_Seq(resultList, resultList->last + 2, list2->data[j]);
                j++;
            }

            if (i > list1->last || j > list2->last){
                break;
            }
        }
        break;
    }

    if (i > list1->last) {
        while (j <= list2->last) {
            InsList_Seq(resultList, resultList->last + 2, list2->data[j]);
            j++;
        }
    }

    if (j > list2->last) {
        while (i <= list1->last) {
            InsList_Seq(resultList, resultList->last + 2, list1->data[i]);
            i++;
        }
    }
}

void GetMergedList() {
    SeqList *list1 = CreateList_Seq();
    SeqList *list2 = CreateList_Seq();
    SeqList *resultList = CreateList_Seq();

    InputElements(list1);
    InputElements(list2);

    MergeList(list1, list2, resultList);

    printf("\n");
    printf("The merged list: ");
    ShowList_Seq(resultList);
    printf("\n");
}

int main() {
//    SeqList *list = CreateList_Seq();
//    int data = 0;

//    while (1) {
//        printf("Input a number, 0 to exit.");
//        scanf("%d", &data);
//
//        if (data != 0) {
//            // 注意下一行的 last + 2，也就是在当前最后一个元素的后面位置插入
//            InsList_Seq(list, list->last + 2, data);
//        } else {
//            break;
//        }
//    }

//    printf("\n");
//    printf("The elements of the sequence list:");
//    ShowList_Seq(list);
//    printf("\n");

//    int pos;
//    printf("\n");
//    printf("Input the position of element you want to delete");
//    scanf("%d", &pos);
//    int q = DelList_Seq(list, pos);
//
//    printf("%d\n", q);
//    printf("The elements of the linklist after deletion:");
//    ShowList_Seq(list);
//    printf("\n");
//
//    int newElement;
//    pos;
//    printf("\n");
//    printf("Input the new element.");
//    scanf("%d", &newElement);
//    printf("Input the position you want to insert.");
//    scanf("%d", &pos);
//    q = InsList_Seq(list, pos, newElement);
//
//    printf("%d\n", q);
//    printf("The elements of the linklist after insertion:");
//    ShowList_Seq(list);
//    printf("\n");

//    printf("\n");
//    printf("Input a element you want to search.");
//    printf("\n");
//
//    int element = 0;
//    scanf("%d", &element);
//    int pos = SearchListByElement_Seq(list, element);
//
//    printf("\n");
//    printf("The found position is %d", pos);

//    GetCommonElements();
    GetMergedList();
}