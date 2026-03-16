//
// Created by fishy on 2026/2/6.
//
#include "set.h"
#include <stdlib.h>

Set* set_create() {
    // TODO: Allocate a Set from the heap and initialize its size to 0 and capacity to ARRAY_DEFAULT_CAPACITY
    // 调用 array_create() 来创建 Set，因为 Set 是 Array 的别名
    return array_create();
}

void set_delete(Set *set) {
    // TODO: Free a set and its contents
    // 调用 array_delete() 来释放 Set
    array_delete(set);
}

bool set_contains(Set *set, int value) {
    // TODO: Test if a set contains an element of a given value
    // 使用 array_index() 检查值是否存在
    if (array_index(set, value) != -1) {
        return true;
    }
    return false;
}

void set_add(Set *set, int value) {
    // TODO: If an element is not already in a set, append it to the end of the array
    // 首先检查值是否已经存在
    if (!set_contains(set, value)) {
        // 如果不存在，添加到数组末尾
        array_append(set, value);
    }
    // 如果已存在，什么都不做
}

void set_remove(Set *set, int value) {
    // TODO: Remove an element with a given value from a set. (Do nothing if it is not in the set)
    // 找到值的索引
    int index = array_index(set, value);
    if (index != -1) {
        // 如果找到，移除该索引处的元素
        array_remove(set, index);
    }
    // 如果没找到，什么都不做
}