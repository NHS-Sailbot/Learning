# Logic

So far, we've covered the main function, as well as splitting up repitive parts of 
our code into sub-functions, however we are only able to create a purely sequential
program. In this lesson we will go over the different ways to introduce branching 
into our code.

There are a few different ways to control the flow of our program, all of which were
inherited from C.

There are two different [branch statements](#Branch-statements)
 - [If/Else statements](#If-and-else-statements)
 - [Switch statements](#Switch-statements)

and two different types of [loops](#Loops)
 - [For/Ranged For loops](#For-loops)
 - [While/Do-While loops](#While-loops)

A conditional statement is just something that evaluates to a true or false. `a > 1`, 
`a == 5`, `a < b` and `a` are all valid conditional statements. The biggest takeaway from
this is also probably the most surprising, which is that `a` is considered conditional.
Since `a` represents something in memory, it must have a binary value. The conditional 
part is if `a`'s value in memory is exactly zero, the conditional is false, otherwise
it is true. In the same way a variable, like `a`, can be evaluated as a conditional,
so can the return value of a function.

# Branch statements

## If and else statements

If and else statements are the most used control flow elements of the language. They 
allow the programmer to choose whether to do something or something else based on a
conditional.

To write an if statement, you start by writing the `if` keyword, followed by a statement
that is enclosed in parenthesis. If the statement is true, the following code statement 
immediately after the parenthesis is ran. To exectute multiple lines of code (multiple
statements), one must use a compound statement to ensure all the specified statements
are evaluated after the conditional. For example:

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

After the if statement's conditional is evaluated, the program will progress to run
either the code in the statement directly after, or skip over it. When the action 
statement ends, the program progresses to the code afterwards.

One can also write in an else clause, using the `else` keyword directly after the 
action statement following the initial if statement. For example:

```cpp
if (some_conditional_statement) {
    some_action_statement;
    some_other_action_statement;
} else {
    some_action_statement;
    some_other_action_statement;
}
```

If the initial condition evaluates to true, the first compound statement code is run,
otherwise, the second set of compound statements are run.

## Switch statements

# Loops

## For loops

## While loops
