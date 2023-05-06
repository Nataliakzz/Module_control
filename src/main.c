#include "calculator.h"

int main() {
    char expr[100];
    printf("Enter expression: ");
    scanf("%s", expr);
    printf("Result: %d\n", eval_expr(expr));
    return 0;
}
