#include "bt.h"

int main() {
    string infix;
    cout << "����ǥ����� : ";
    cin >> infix;
    BTreeNode* eTree = MakeExpTree(infix);
    double res = EvaluateExpTree(eTree);
    cout << res;
}