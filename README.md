# RPN-Calculator-and-Palindromic-Permutation
## Key Points Related to Data Structures/Algorithms

This assignment provided practical experience implementing and utilizing three fundamental abstract data types (ADTs): **Array**, **Stack**, and **Set**. The most valuable learning was understanding how these ADTs build upon each other - specifically how the **Set** ADT was implemented using the **Array** ADT as its underlying data structure. This hierarchical design demonstrates the power of abstraction in software engineering.

For the RPN calculator, I implemented the classic stack-based evaluation algorithm. The algorithm processes tokens sequentially, pushing operands onto the stack and performing operations when encountering operators. This exercise reinforced the LIFO (Last-In, First-Out) property of stacks and how they naturally fit expression evaluation problems.

The palindromic permutation problem was particularly interesting from an algorithmic perspective. The solution uses a set to track characters with odd frequencies. The key insight is that a string can be rearranged into a palindrome if and only if it contains at most one character with an odd frequency. This O(n) time complexity solution is both elegant and efficient compared to brute-force permutation approaches.

## Lessons Learned

**Debugging Challenges:** The most significant debugging challenge arose during RPN calculator implementation. Initially, I struggled with operator precedence in reverse Polish notation. Unlike infix notation, RPN eliminates the need for operator precedence, but careful consideration of operand order is crucial. For subtraction and division operations, I had to ensure the correct operand was popped first from the stack.

Another debugging issue occurred with the `set_remove()` function. My initial implementation didn't properly handle the case when removing an element required shifting all subsequent elements. Through debugging with `unit_set.c` test cases, I identified that the `array_remove()` function needed careful index management to avoid accessing out-of-bounds memory.

**Coding Insights:** I learned the importance of robust error handling in ADT implementations. For example, in the stack implementation, using `assert()` for operations like `stack_top()` on empty stacks helped catch logical errors early. This defensive programming approach proved valuable during testing phases.

## Use of AI

I utilized AI assistance in two specific areas during this assignment:

1. **Array ADT Design Flaw:** The `int array_at(Array *array, int index)` function presented a design challenge. The function signature returns `int`, but error handling for invalid indices becomes problematic. In a well-designed ADT, this function should either return a pointer (`int*`) that can be `NULL` for invalid indices or use a separate error reporting mechanism. The current design forces a compromise: returning a sentinel value like `-1` fails when `-1` is a legitimate array element. AI analysis confirmed this design inconsistency and helped me understand that this is a common trade-off in C programming where true exception handling isn't available.

2. **Character Handling in C:** For the `palindromic.c` implementation, I needed to handle case-insensitive character comparison. AI helped identify the appropriate C standard library function `tolower()` from `<ctype.h>` for this purpose. This was crucial for the palindromic permutation algorithm, as strings like "Aa" should be recognized as palindromic permutations despite the case difference.

## Code Review Notes for Exams

For exam preparation, I should focus on these critical implementations:

1. **Array Implementation (`array.c`):** Review the dynamic resizing logic in `array_append()` and `array_insert()`. Note how capacity doubles when full, and the careful memory management with `realloc()`. The `array_remove()` function demonstrates efficient element shifting.

2. **Stack Implementation (`stack.c`):** Study how the stack is built upon the array ADT. The `stack_pop()` and `stack_top()` functions illustrate the LIFO principle. Pay attention to the assertion in `stack_top()` that prevents access to empty stacks.

3. **Set Implementation (`set.c`):** Understand how set operations leverage array functions. The `set_contains()` function uses `array_index()`, demonstrating code reuse. The `set_add()` function shows how to maintain set uniqueness property.

4. **RPN Calculator (`rpn.c`):** The `evaluate_expression()` function showcases practical stack usage. Note the token parsing with `strtok()` and the switch statement for operator handling.

5. **Palindromic Check (`palindromic.c`):** The `is_palindromic()` algorithm elegantly solves the problem with O(n) complexity. Review how the set tracks odd/even character counts.

This assignment reinforced the importance of abstraction, modular design, and proper memory management in C programming. The layered ADT approach (Array → Stack/Set → Applications) demonstrates good software engineering practices worth remembering for future projects and exams.
