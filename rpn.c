//
// Created by fishy on 2026/2/6.
//
/* rpn.c: Reverse Polish Notation Calculator */

#include "stack.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * If string s ends with a newline (\n), replace it with the end-of-string null character (\0)
 **/
void chomp(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

/**
 * Evaluate the given RPN expression using a stack.
 *
 * @param   expression	String containing RPN expression.
 * @return  Result of evaluating RPN expression using stack.
 **/
int evaluate_expression(char *expression) {
    // TODO
    // create a stack and declare other variables
    // Use strtok to get first token
    // while token available, process it using a stack
    // Get result, clean up, and return
    // create a stack
    Stack *stack = stack_create();

    // Use strtok to split expression into tokens
    const char *delimiters = " \t\n";  // 空格、制表符、换行符作为分隔符
    char *token = strtok(expression, delimiters);

    while (token != NULL) {
        // 检查 token 是否是操作符
        if (strlen(token) == 1 &&
            (token[0] == '+' || token[0] == '-' ||
             token[0] == '*' || token[0] == '/')) {

            // 确保栈中至少有两个操作数
            if (stack->size < 2) {
                // 错误情况：操作符没有足够的操作数
                stack_delete(stack);
                return 0;  // 返回默认值
            }

            // 弹出两个操作数
            int b = stack_pop(stack);
            int a = stack_pop(stack);
            int result = 0;

            // 执行运算
            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        // 除以零错误
                        stack_delete(stack);
                        return 0;
                    }
                    result = a / b;  // 整数除法
                    break;
            }

            // 将结果压回栈中
            stack_push(stack, result);
        } else {
            // token 应该是数字
            int value;
            if (sscanf(token, "%d", &value) == 1) {
                // 成功解析为数字，压入栈中
                stack_push(stack, value);
            } else {
                // 无法解析为数字
                stack_delete(stack);
                return 0;
            }
        }

        // 获取下一个 token
        token = strtok(NULL, delimiters);
    }

    // 表达式结束后，栈顶应该是结果
    int final_result = 0;
    if (!stack_empty(stack)) {
        final_result = stack_pop(stack);
    }

    // 栈应该是空的（如果表达式正确）
    if (!stack_empty(stack)) {
        // 表达式有问题，栈中还有多余的元素
        while (!stack_empty(stack)) {
            stack_pop(stack);
        }
    }
    // 清理栈并返回结果
    stack_delete(stack);
    return final_result;
}

/* Main Execution */
int main() {
    // TODO: For each line in standard input, evaluate the RPN expression
    char line[1024];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // 移除末尾的换行符
        chomp(line);
        // 评估表达式
        int result = evaluate_expression(line);
        // 输出结果
        printf("%d\n", result);
    }
    return 0;
}
