#include "bt.h"

int main() {
    string infix;
    cout << "����ǥ����� : ";
    cin >> infix;
    BTreeNode* eTree = MakeExpTree(infixToPostfix(infix));
    double res = EvaluateExpTree(eTree);
    cout << res;
}