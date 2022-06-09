#include "bt.h"

BTreeNode* MakeBTreeNode(void)
{
    BTreeNode* nd = new BTreeNode; //make binary tree
    nd->left = NULL; //initialize
    nd->right = NULL; //initialize
    return nd; //return pointer
}

void DeleteBTreeNode(BTreeNode* bt) {
    delete bt;
}

int GetData(BTreeNode* bt) {
    return bt->data;
}

void SetData(BTreeNode* bt, int data) {
    bt->data = data;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt) {
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
    return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
    if (main->left != NULL)
    {
        delete main->left;
    }
    main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
    if (main->right != NULL)
    {
        delete main->right;
    }
    main->right = sub;
}

void PreorderTraverse(BTreeNode* bt)
{
    if (bt == NULL)
        return;
    cout << bt->data << " ";
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

void InorderTraverse(BTreeNode* bt)
{
    if (bt == NULL)
        return;
    PreorderTraverse(bt->left);
    cout << bt->data << " ";
    PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
    if (bt == NULL)
        return;

    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
    cout << bt->data << " ";
}
BTreeNode* MakeExpTree(string exp)
{
    stack<BTreeNode*> stack;
    int one = 0, two = 0;
    BTreeNode* node;
    for (int i = 0; i < exp.length(); i++)
    {
        node = MakeBTreeNode();
        if (isdigit(exp[i]))
        {
            SetData(node, exp[i] - '0');
        }
        else
        {
            SetData(node, exp[i]);
            MakeRightSubTree(node, stack.top());
            stack.pop();
            MakeLeftSubTree(node, stack.top());
            stack.pop();
        }
        stack.push(node);
    }
    node = stack.top();
    stack.pop();
    return node;
    
    
}

int EvaluateExpTree(BTreeNode* bt)
{
    int op1, op2;
    if (GetLeftSubTree(bt) == NULL&& GetRightSubTree(bt)==NULL)
    {
        return GetData(bt);
    }
    op1 = EvaluateExpTree(GetLeftSubTree(bt));;
    op2 = EvaluateExpTree(GetRightSubTree(bt));
    switch (GetData(bt))
    {
    case '+':
        return op1 + op2;
        break;
    case '-':
        return op1 - op2;
        break;
    case '*':
        return op1 * op2;
        break;
    case '/':
        return op1 / op2;
        break;
    default:
        break;
    }
    return 0;
}

//int prec(char op) {
//    // 구현해보자!
//}
//string infixToPostfix(string infix) {
//    // 구현해보자!
//}