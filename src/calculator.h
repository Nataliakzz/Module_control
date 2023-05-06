#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/**
 *  Функція для обчислення виразу в дужках
 * @param expr - вираз
 * @return Результат обчислення виразу
 */
int eval_parentheses(const char *expr);

/**
 * Функція яка шукає числа в рядку
 * @param expr - вираз
 * @param pos  - показує поточну позицію у рядку виразу
 * @return повертає ціле число, яке знаходиться в рядку починаючи з позиції pos.
 */
int parse_number(const char *expr, int *pos);

/**
 * Функція для обчислення значення виразу з однаковим пріоритетом операторів
 * @param expr - рядок
 * @param pos - позиція в рядку
 * @return результат обчислення виразу
 */
int eval_same_precedence(const char *expr, int *pos);

/**
 * Функція для обчислення значення виразу з різним пріоритетом операторів
 * @param expr - рядок
 * @return результат обчислення
 */
int eval_expr(const char *expr);