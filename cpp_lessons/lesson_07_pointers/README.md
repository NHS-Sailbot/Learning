# Pointers

As said in the previous lesson, we brought up the analogy that memory
is like a street. Pointers fit into this analogy because pointers are
basically an integer that represent the house number, or in this case
the memory address of some bytes. At the end of the previous lesson,
I said that our array had a type of `int pointer`, meaning a pointer
that points to an integer in memory. Appending a type to a pointer is
similar to saying what kind of house is at an address on a street.
Although providing a type is not necessary, it provides the ability for
compile time checks to make sure your program isn't reading memory that
does not belong to it, as well as allows the compiler to provide extra
functionality.

To create a variable that is a pointer, one would append an asterisk,
or 'star' after the type of the variable, for example:

```cpp
int * my_ptr;
```

The variable `my_ptr` is a pointer. Note the spaces on either side of
the asterisk. These are not necessary and it could have been written...

```cpp
// like this:
int*my_ptr;
// this,
int* my_ptr;
// or this
int *my_ptr;
```

The way of writing this is personal preference, and there's a pretty
even split between people writing the asterisk against the type and those
who write the asterisk against the variable name. Not many people write
it with no spaces or both spaces. You will see me write, in my code, pointers
with the asterisk against the variable name, because when declaring multiple
variables in a single line, one must write the asterisk for every variable
declared, like this.

```cpp
int *my_ptr, *my_other_ptr;
// Omitting the asterisk in my_other_ptr's declaration would
// create an int, not an int pointer.
```

Because of this, I see the 'pointer-ness' as being intrinsic to the
variable and not the type, and thus associate the asterisk with the
variable name and not the type. My justification aside, notation is
mostly _point_-less and you may write it however you'd like.

Pointers are the most differentiating feature of C/C++ from other
languages because of the immense control over memory they give to
the programmer. Pointers can be used to manipulate memory that was
allocated in a large block, or to access memory from a different
scope.

The most used form of a pointer would be one that we have already
used, a character pointer or `char *`. This is what holds a string
since when passing a string around, it is easier on the computer to
send the address at which the string starts than to copy the whole
string when, for example, passing it as an argument for a print function.

For simplicity reasons, one can assign a string literal, as denoted
by quotes, directly to a variable of type `char *`.

```cpp
char *my_string = "Hello, Pointers!";
```

In the same way an array is indexable, since both a string and an array
are fundimentally the same thing (a pointer), one can use the subscript
operator to use an element from the pointer.

```cpp
char *my_string = "0123456789ABCDEF";
my_string[7] = 'B';
```

Using the index `[7]` will grab the 7th element in the 'array', which
in this case, because I numbered each index, is conviniently the character
'7' in the string.

One important thing to note is that indexing past the string will again
possible invoke a read/write access violation, However, string literals
add what is known as a null termination character, which is standardized
by ascii to be (in binary) `0000 0000` or zero. This is what allows your
program, usually the print function, to be able to find out the length
of your string so that it can properly interact with it, and not cause
any read/write access violations, since all you, as the programmer,
provide to functions like `printf` are a pointer to a set of memory that
the `printf` function expects a properly null terminated string owned
by the program being run.

Because of this, if one wanted to instead declare a string as an array,
they could, however functions like `printf` would require said array to
end with an element equal to zero, thus if you manually create a string
opposed to using a string literal, remember to add a null terminator at
the end of the array.

```cpp
char my_string[] = {'H', 'e', 'l', 'l', 'o', 0};
// or
char my_string[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

As I said previously, the type to which the pointer points to is not
necessary, and because of this, one could create a pointer that is
devoid of a type. To do so, one would use the second of the two uses of
the `void` keyword as a type.

```cpp
void *my_ptr;
```

However, since no type is given, using the subscript operator `[]` will
result in a compiler error. This is because the compiler will not know
how far apart, in bytes, each element is in your array, and will not know
what type to return from the indexing.

Other useful functionality of pointers, that are lost when using a void
pointer, include referencing/dereferencing and offsetting.

Dereferencing is simply saying you wish to interact with the memory
pointed to by the address being dereferenced, Referencing is the same
thing as grabbing the address of some variable. For example,

```cpp
int a = 10;
int *b = &a;
// using the reference operator '&' to get the address of variable 'a'.
int c = *b;
// using the dereference operator '*' to use the value pointed to by
// variable 'b'. This will assign the value 10 to c, because 'b' points
// to 'a', and a = 10
```

Offsetting a pointer can be thought of as shifting or adding/subtracting
the address which the pointer points to, for example:

```cpp
char *my_string = "0123456789ABCDEF";
my_string += 2;
```

This would make it so that the `my_string` variable, which holds a pointer,
is now pointing to an address that is 2 greater than before. In this example,
this means that the 'string', if used in a function like `printf`, would be
interpreted as starting two characters later. This is why the subscript
