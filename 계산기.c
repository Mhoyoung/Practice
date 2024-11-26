#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

int main() {
    int (*operations[4])(int, int) = { add, subtract, multiply, divide};
    char op;
    int a, b, result = 0;a

    scanf("%d%c%d", &a, &op, &b);

    int index = (op == '+') * 1 + (op == '-') * 2 + (op == '*') * 3 + (op == '/') * 4 - 1;

    result = operations[index](a, b);
    printf("Result: %d\n", result);
    return 0;
}
