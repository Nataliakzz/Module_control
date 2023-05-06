#include "calculator.h"

int eval_parentheses(const char *expr) {
    int pos = 1;
    int value = eval_expr(expr + pos);
    while (expr[pos] != ')') {                 // Перевірка на закриття дужок
        if (expr[pos] == '\0') {
            printf("Error: missing ')'\n");
            exit(1);
        }
        if (expr[pos] == '*') {                               // Перевірка на операцію множення, ділення, взяття за модулем або взведення до степеню
            value *= eval_same_precedence(expr, &pos);
        } else if (expr[pos] == '/') {
            int divisor = eval_same_precedence(expr, &pos);
            if (divisor == 0) {
                printf("Error: division by zero\n");
                exit(1);
            }
            value /= divisor;
        } else if (expr[pos] == '%') {
            int divisor = eval_same_precedence(expr, &pos);
            if (divisor == 0) {
                printf("Error: division by zero\n");
                exit(1);
            }
            value %= divisor;
        } else if (expr[pos] == '^') {
            int exponent = eval_same_precedence(expr, &pos);
            int result = 1;
            for (int i = 0; i < exponent; i++) {
                result *= value;
            }
            value = result;
        } else {
            printf("Error: invalid operator '%c'\n", expr[pos]);
            exit(1);
        }
    }
    return value;
}

int parse_number(const char *expr, int *pos) {
    int value = 0;
    while (isdigit(expr[*pos])) {                        // доти, поки поточний символ є цифрою
        value = value * 10 + (expr[*pos] - '0');
        (*pos)++;
    }
    return value;
}

int eval_same_precedence(const char *expr, int *pos) {
    char op;
    int value = parse_number(expr, pos);
    while ((op = expr[*pos]) == '*' || op == '/' || op == '%' || op == '^') {    // доти, поки оператор має такий же пріоритет
        (*pos)++;
        int right = parse_number(expr, pos);      // зчитує наступне число з виразу
        if (op == '*') {
            value *= right;
        } else if (op == '/') {
            if (right == 0) {
                printf("Error: division by zero\n");
                exit(1);
            }
            value /= right;
        } else if (op == '%') {
            int divisor = right;
            if (divisor == 0) {
                printf("Error: division by zero\n");
                exit(1);
            }
            value %= divisor;
        } else if (op == '^') {
            value = pow(value, right);
        }
    }
    return value;
}

int eval_expr(const char *expr) {
    int pos = 0;
    int value = eval_same_precedence(expr, &pos);     // обчислює вираз з операторами з однаковим пріоритетом
    while (expr[pos] != '\0' && expr[pos] != ')') {   //  доти, поки не дойдено до кінця рядку або до закриваючої дужки
        char op = expr[pos];                          // зчитує наступний оператор
        if (op != '+' && op != '-') {                 // перевіряє, чи це правильний оператор
            printf("Error: invalid operator '%c'\n", op);
            exit(1);
        }
        pos++;                                         // переходть до наступного символу
        int right = eval_same_precedence(expr, &pos);  // обчислює вираз з операторами з однаковим пріоритетом, що йдуть за поточним оператором
        if (op == '+') {
            value += right;
        } else {
            value -= right;
        }
    }
    return value;
}