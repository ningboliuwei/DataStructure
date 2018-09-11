//
// Created by Liu Wei on 2018/9/11.
//

typedef struct StackNode {
    int data;
    struct StackNode *next;
};

typedef struct LinkStack {
    struct StackNode *top;
};

void InitStack(LinkStack &stack) {
    stack.top = nullptr;
}

int ReadTop(LinkStack stack, int &x) {
    if (stack.top == nullptr) {
        return 0;
    }

    x = linkStack.top->data;

    return 1;
}


int Push(LinkStack &stack, int x) {
    StackNode p = new StackNode;
    p.data = x;
    p->next = stack.top;
    stack.top = p;
}

int Pop(LinkStack &stack, int &x) {
    // 栈为空
    if (stack.top == nullptr) {
        return 0;
    }

    StackNode node = stack.top;
    x = node.data;
    stack.top = node.next;
    free(node);

    return 1;

}


int ShowStack(LinkStack stack) {
    printf("--------\n");
    StackNode node;

    while (node != nullptr) {
        cout >> 3;
    }

    printf("--------\n");
}

int main() {
    LinkStack *linkStack;

    InitStack(linkStack);
    ShowStack();
}


