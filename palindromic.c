//
// Created by fishy on 2026/2/6.
//

#include "set.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024

void chomp(char *s) {
    // If string s ends with a newline (\n), replace it
    // with the end-of-string null character (\0)
    // TODO:
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

bool is_palindromic(char *s) {
    // Return true if string s is a palindromic permutation
    // Use a set as part of your solution
    // TODO:
    // 创建集合来跟踪出现奇数次的字符
    Set *odd_chars = set_create();

    // 遍历字符串中的每个字符
    for (int i = 0; s[i] != '\0'; i++) {
        // 获取字符（转换为小写以忽略大小写）
        char c = tolower(s[i]);

        // 检查字符是否已经在集合中
        if (set_contains(odd_chars, c)) {
            // 如果已经在集合中（表示之前出现奇数次）
            // 现在变成偶数次，所以从集合中移除
            set_remove(odd_chars, c);
        } else {
            // 如果不在集合中（表示第一次出现或之前出现偶数次）
            // 现在变成奇数次，所以添加到集合中
            set_add(odd_chars, c);
        }
    }

    // 检查集合大小：
    // - 如果所有字符都出现偶数次，集合为空 (size == 0)
    // - 如果最多一个字符出现奇数次，集合大小为 1 (size == 1)
    // 这两种情况都可以排列成回文
    bool result = (odd_chars->size <= 1);

    // 清理集合
    set_delete(odd_chars);

    return result;

}

int main() {
    char buffer[BUF_SIZE];
    while (fgets(buffer, BUF_SIZE, stdin)) {
        chomp(buffer);
        if (is_palindromic(buffer)) {
            puts("YEAH");
        } else {
            puts("NOPE");
        }
    }
    return 0;
}