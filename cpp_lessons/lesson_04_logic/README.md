# Logic

So far, we've covered the main function, as well as splitting up repitive parts of our code into sub-functions, however we are only able to create a purely sequential program. In this lesson we will go over the different ways to introduce branching into our code. This lesson, by far, is my least favorite and IMO, the most boring. The skills from this lesson are in majority syntactical and can be learned by the usage of a resource like codeacademy.com.

There are a few different ways to control the flow of our program, all of which were inherited from C.

There are two different types of [branch statements](#Branch-statements)

- [If/Else statements](#If-and-else-statements)
- [Switch statements](#Switch-statements)

and two different types of [loops](#Loops)

- [For/Ranged For loops](#For-loops)
- [While/Do-While loops](#While-loops)

A conditional statement is just something that evaluates to a true or false. `a > 1`, `a == 5`, `a < b` and `a` are all valid conditional statements. The biggest takeaway from this is also probably the most surprising, which is that `a` is considered conditional. Since `a` represents something in memory, it must have a binary value. The conditional part is if `a`'s value in memory is exactly zero, the conditional is false, otherwise it is true. In the same way a variable, like `a`, can be evaluated as a conditional, so can the return value of a function.

## Branch statements

### If and else statements

If and else statements are the most used control flow elements of the language. They allow the programmer to choose whether to do something or something else based on a conditional.

To write an if statement, you start by writing the `if` keyword, followed by a statement that is enclosed in parenthesis. If the statement is true, the following code statement immediately after the parenthesis is ran. To exectute multiple lines of code (multiple statements), one must use a compound statement to ensure all the specified statements are evaluated after the conditional. For example:

```cpp
// Like this, where the statement is below the line
if (some_conditional_statement)
    some_action_statement;
// Or like this, where the action is on the same line.
if (some_conditional_statement) some_action_statement;
// Remember, in C++, excess whitespace is ignored, so
// this code, to the compiler is the same as the previous
// one, since the previous one just has a `\n` newline
// as well as a `\t` indent inbetween the conditional
// and the action.

// Or if one requires multiple action statements, one must
// use braces to enclose a compound statement.
if (some_conditional_statement) {
    some_action_statement;
    some_other_action_statement;
}
```

After the if statement's conditional is evaluated, the program will progress to run either the code in the statement directly after, or skip over it. When the action statement ends, the program progresses to the code afterwards. One can also write in an else clause, using the `else` keyword directly after the action statement following the initial if statement. For example:

```cpp
if (some_conditional_statement) {
    some_action_statement;
    some_other_action_statement;
} else {
    some_action_statement;
    some_other_action_statement;
}
```

If the initial condition evaluates to true, the first compound statement code is run, otherwise, the second set of compound statements are run.

### Switch statements

A switch statement's functionality is similar to an if statement, however it allows for an optimization on the hardware level for conditions. Say, for example, one would like to draw tiles to a screen, and needs some way to return the `texID` (which, let's say, is an `int`) of a tile based on its `tileID` (which is also an `int` in this theoretical example). Using an if statement to do this would look like this:

```cpp
int nullTexID = -1;
int texID_0 = 1, texID_1 = 0, texID_2 = 4, texID_3 = 2;

int getTexIDfromTileID(int tileID) {
    if (tileID == 0) return texID_0;
    if (tileID == 1) return texID_1;
    if (tileID == 2) return texID_2;
    if (tileID == 3) return texID_3;
    return nullTexID;
}
```

This, however, is actually really inefficient in the long run. If one were to have a lot of tiles/textures, and the `texID` in question were the last in the list, the computer would go through and do `N` if condition checks given `N` `tileID`'s. We could use a switch statement, in this case, to optimize our program. To write a switch statement, one puts the index to switch on in the parenthesis, and then a handful of case statements inside the braces. To use a switch statment in this example, it would look like this:

```cpp
int nullTexID = -1;
int texID_0 = 1, texID_1 = 0, texID_2 = 4, texID_3 = 2;

int getTexIDfromTileID(int tileID) {
    switch (tileID) {
        case 0:
            return texID_0;
        case 1:
            return texID_1;
        case 2:
            return texID_2;
        case 3:
            return texID_3;
        default:
            return nullTexID;
    }
}
```

Notice the `default:` case at the end, allowing for an unknown `tileID` to map to a `nullTexID`. Note that the value inside the switch statement (and the case labels) must be integral. This is due to how the logic is evaluated. Also, the numbers in the case labels must be a _"Compile-time evaluable constant expression"_. More on this in [lesson 8](https://github.com/NHS-Sailbot/teaching_cpp/tree/master/cpp_lessons/lesson_08_type_mods). When the switch statment is run, the program is actually able to 'jump' a variable number of 'lines' in the program. This allows the program to check only 1 condition (whether or not the given index is inside the case range) and then just jump the number of lines ahead given in the original statement. In our example, with a tileID of 3, the program checks whether or not a tileID of 3 is one of the case labels, and then skips directly to it. This is a simplification of what actually happens, but know that given a contiguous integral range, the compiler can easily optimize away many condition checks, allowing for a faster program. If in our theoretical example, we actually needed a texID for, say, 10,000 sprites on the screen, every single frame of a program, we would want to minimize greatly the time it takes to run said function because it would get called 600,000 times a second, given 60 frames per second.

## Loops

Loops allow us to do the same lines of code repeatedly. This is very useful for simplifying our code, allowing the programmer to not have to explicitly write out the function calls for an entire program.

### While loops

A while loop is the simplest kind of loop that we can write. A while loop runs the same set of code over and over until the given condition results in false. For example, say we would like to write a function that calculates the n-th fibonacci number given n.

```cpp
int fib(int n) {
    int a = 0, b = 1;
    while (n > 0) {
        int tempB = b;
        b += a;
        a = tempB;
        n--;
    }
    return a;
}
```

In this function, we check whether or not `n` is greater than 0. If this evaluates to true, the loop runs, incrementing `a` and `b` to the next numbers in the sequence, and decrements `n`. Because this decrements `n` every loop, the code inside the loop will only run `n` times.

### For loops

A for loop is the exact same thing as a while loop, and just provides a simpler way of writing one. In our previous example, we used a while loop to calculate the n-th element in the fibonacci sequence, and we could do the same in a for loop.

```cpp
int a = 0, b = 1;

for (int n = 0; n < 7; n++) {
    int tempB = b;
    b += a;
    a = tempB;
}
```

this will loop through all the values of `n` between 0 and 6 (6 because 6 is the last integer _**less than**_ 7). This will calculate the 7th element in the sequence, which will reside in `a`. For loops are mainly used for things that are indexed sequentially, and will commonly be used with arrays [lesson 6](https://github.com/NHS-Sailbot/teaching_cpp/tree/master/cpp_lessons/lesson_06_arrays).
