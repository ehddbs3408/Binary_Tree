#include "bt.h"

int main() {
    string infix;
    cout << "중위표기수식 : ";
    cin >> infix;
    BTreeNode* eTree = MakeExpTree(infix);
    double res = EvaluateExpTree(eTree);
    cout << res;
}