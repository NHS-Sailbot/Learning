# Pointers

As said in the previous lesson, we brought up the analogy that memory is like a street. Pointers fit into this analogy because pointers are basically an integer that represent the house number, or in this case the memory address of some bytes. At the end of the previous lesson, I said that our array had a type of `int pointer`, meaning a pointer that points to an integer in memory. Appending a type to a pointer is similar to saying what kind of house is at an address on a street. Although providing a type is not necessary, it provides the ability for compile time checks to make sure your program isn't reading memory that does not belong to it, as well as allows the compiler to provide extra functionality. To create a variable that is a pointer, one would append an asterisk, or 'star' after the type of the variable, for example:

```cpp
int * my_ptr;
```

The variable `my_ptr` is a pointer. Note the spaces on either side of the asterisk. These are not necessary and it could have been written like this:

```cpp
int*my_ptr;
// or this:
int* my_ptr;
// or this:
int *my_ptr;
```

The way of writing this is personal preference, and there's a pretty even split between people writing the asterisk against the type and those who write the asterisk against the variable name. Not many people write it with no spaces or both spaces. You will see me write, in my code, pointers with the asterisk against the variable name, because when declaring multiple variables in a single line, one must write the asterisk for every variable declared, like this.

```cpp
int *my_ptr, *my_other_ptr;
// Omitting the asterisk in my_other_ptr's declaration would create an int, not an int pointer.
```

Because of this, I see the 'pointer-ness' as being intrinsic to the variable and not the type, and thus associate the asterisk with the variable name and not the type. My justification aside, notation is mostly _point_-less and you may write it however you'd like.

Pointers are the most differentiating feature of C/C++ from other languages because of the immense control over memory they give to the programmer. Pointers can be used to manipulate memory that was allocated in a large block, or to access memory from a different scope.

The most used form of a pointer would be one that we have already used, a character pointer or `char *`. This is what holds a string since when passing a string around, it is easier on the computer to send the address at which the string starts than to copy the whole string when, for example, passing it as an argument for a print function.

For simplicity reasons, one can assign a string literal, as denoted by quotes, directly to a variable of type `char *`.

```cpp
char *my_string = "Hello, Pointers!";
```

In the same way an array is indexable, since both a string and an array are fundimentally the same thing (a pointer), one can use the subscript operator to use an element from the pointer.

```cpp
char *my_string = "0123456789ABCDEF";
my_string[7] = 'B';
```

Using the index `[7]` will grab the 7th element in the 'array', which in this case, because I numbered each index, is conviniently the character '7' in the string.

One important thing to note is that indexing past the string will again possible invoke a read/write access violation, However, string literals add what is known as a null termination character, which is standardized by ascii to be (in binary) `0000 0000` or zero. This is what allows your program, usually the print function, to be able to find out the length of your string so that it can properly interact with it, and not cause any read/write access violations, since all you, as the programmer, provide to functions like `printf` are a pointer to a set of memory that the `printf` function expects a properly null terminated string owned by the program being run.

Because of this, if one wanted to instead declare a string as an array, they could, however functions like `printf` would require said array to end with an element equal to zero, thus if you manually create a string opposed to using a string literal, remember to add a null terminator at the end of the array.

```cpp
char my_string[] = {'H', 'e', 'l', 'l', 'o', 0};
// or
char my_string[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

As I said previously, the type to which the pointer points to is not necessary, and because of this, one could create a pointer that is devoid of a type. To do so, one would use the second of the two uses of the `void` keyword as a type.

```cpp
void *my_ptr;
```

However, since no type is given, using the subscript operator `[]` will result in a compiler error. This is because the compiler will not know how far apart, in bytes, each element is in your array, and will not know what type to return from the indexing.

Other useful functionality of pointers, that are lost when using a void pointer, include referencing/dereferencing and offsetting.

Dereferencing is simply saying you wish to interact with the memory pointed to by the address being dereferenced, Referencing is the same thing as grabbing the address of some variable. For example,

```cpp
int a = 10;
int *b = &a;
// using the reference operator '&' to get the address of variable 'a'.
int c = *b;
// using the dereference operator '*' to use the value pointed to by variable 'b'. This will assign the value 10 to c, because 'b' points to 'a', and a = 10
```

Note the two new operators, the reference operator `&` and the dereference operator `*`. Although the same character (`*`) is used to dereference as to declare a pointer, the compiler can tell which is being used based on context. As alluded to in the comments of the code, the reference operator must be used on something in code that is addressable. This is known as an l-value, a concept that people usually find very confusing when learning C++. The concept of an l-value, and its counterpart, r-value, are very simple in that they can be described as, 1. An l-value is any expression that results in something addressable in memory, and 2. an r-value is everything else. An example of an l-value is a variable name, since the variable is stored in memory, and an example of an r-value is a numeric or string literal, like `10` or `"Hello"`. l-values and r-values are important to know since it is common to see them referenced in compiler warnings or errors. On the other hand, the dereference operator must be used on a memory address, or more simply, a pointer.

Offsetting a pointer can be thought of as shifting or adding/subtracting the address which the pointer points to, for example:

```cpp
char *my_string = "0123456789ABCDEF";
my_string += 2;
```

This would make it so that the `my_string` variable, which holds a pointer, is now pointing to an address that is 2 greater than before. In this example, this means that the 'string', if used in a function like `printf`, would be interpreted as starting two characters later. This is why the subscript operator index begins at 0, since it is the same as first adding the index inside the brackets _to the pointer_, then dereferencing it, for example:

```cpp
int my_array_which_is_a_pointer[] = {1, 3, 4, 2, 4};

// This is the same as
*(my_array_which_is_a_pointer + 2) = 10;
// using the subscript operator with index 2
my_array_which_is_a_pointer[2] = 10;
```

Pointers are present in both C and C++, however C++ introduces a concept that simplifies the usage of pointers, and makes them safer for new programmers, which are references. References can be denoted by using an ampersand in the variable declaration, similar to a pointer. To simplify our example from before, we can use references as such:

```cpp
int a = 10;
int &b = a;
int c = b;
```

Like before, variable `c` is assigned the same value that `a` is, since `b` is a reference to `a`. This is much simpler to read and learn for new programmers because it hides all of the syntax required for getting the address of `a` as well as dereferencing `b` when wanting to extract the value to which it points. Because of this, they are less powerful, but still useful in some cases.

An example where one may use a reference as opposed to a pointer is as follows:

```cpp
void fib(int &a_ref, int &b_ref) {
    int temp = a_ref;
    a_ref = b_ref;
    b_ref += temp;

}

int main() {
    int a = 0, b = 1;
    fib(a, b);
    // a = 1, b = 1;
    fib(a, b);
    // a = 1, b = 2;
    fib(a, b);
    // a = 2, b = 3;
    fib(a, b);
    // a = 3, b = 5;
    fib(a, b);
    // a = 5, b = 8;
}
```

In this example, every time that the `fib` function is called using `a` and `b` results in both `a` and `b` progressing to the next term in the fibonacci sequence. This is because both `a` and `b` are taken into the function by reference, so when we use the assignment operator (`=`) inside `fib`, it assigns not to `a_ref` and `b_ref`, but to the value 'pointed' to by, or to what both arguments _reference_. This means that when assigning to `a_ref`, we are actually modifying `a`, which resides inside of the main function. This could be done using pointers, however, since all we require is that `fib` can modify `a` and `b`, this code is more simply expressed using references and will be easier to read for the future.

If you wanted to write this with pointers instead of references, the code would look a bit more complicated, but would functionally be the same:

```cpp
void fib(int *a_ptr, int *b_ptr) {
    int temp = *a_ptr;
    *a_ptr = *b_ptr;
    *b_ptr += temp;
}

int main() {
    int a = 0, b = 1;
    fib(&a, &b);
    // a = 1, b = 1;
    fib(&a, &b);
    // a = 1, b = 2;
    fib(&a, &b);
    // a = 2, b = 3;
    fib(&a, &b);
    // a = 3, b = 5;
    fib(&a, &b);
    // a = 5, b = 8;
}
```
