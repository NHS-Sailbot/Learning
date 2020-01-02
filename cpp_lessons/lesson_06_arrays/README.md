# Arrays

Arrays in C++, like most things, are much simpler than in other languages
with regards to how they work. I've talked a little about memory, but have
not talked explicitly about memory addresses.

To use an array in C++, all one needs to do is append a pair of brackets
following their variable declaration, for example:

```cpp
int my_array[];
```

This, however, will not compile. This is because of specific hardware
optimization reasons, in short, The compiler must know the size of the
array at compile time. To solve this, one can either explicitly state
how large the array is (in, in this case, `int` count, not bytes) by
putting said number inside the brackets,

```cpp
int my_array[5];

// One can also force the compiler to implicitly infer the size of the array
// by giving a set of values to it. The set of numbers inside the braces
// following the declaration are what is called an 'initializer list'

int my_array[] = {1, 4, 2, 3, 7};
```

Both of these will allocate 5 integers, which are (on a modern x86/64
processor) 4 bytes and thus will allocate 20 bytes in memory. I will go
into further explaination about memory structure in the future, however,
for now it's best to think of memory about a very long street, where
each house is a single byte in memory. As talked about in _lesson 2: variables_,
the computer reserves the necessary amount of bytes in memory when the
programmer declares a variable. When one declares an array of `N` integers,
the computer must allocate `N * sizeof(int)` bytes. The most modern C++
(and C) standards require for this allocation to be completely contiguous,
meaning all of the integers are back to back in memory.

`sizeof` is a keyword allowing for the measurement of the size given type
in bytes.

If one has declared an array, said array's size and type cannot change
throughout the runtime of the program, for the same hardware reasons as
before, which is that they are being allocated in a sector of memory
called _the stack_, which is a topic for another day. As I said before,
think of memory as a street.

Anyways, once said array has been allocated, one _can_ change the contents
of each element in the array. This is done using the same brackets as before.
Using these brackets with an index in it will result in the statement being
equivalent to a normal, integral, variable name.

```cpp
int my_var = 10;
int my_array[] = {1, 3, 4, 6};

int my_var1 = my_var + my_array[0]; // my_var1 = 10 + 1 or 11
int my_var2 = my_var + my_array[3]; // my_var2 = 10 + 6 or 16

my_array[2] = 10; // will change the third element to 10
```

Notice the indexing starts with zero, which is standard for many languages, and
is for a reason that should be detailed in the lesson about pointers. Because
it starts at zero, that means the last index (in this specific array) is specified
using index `3`. Because of this, attempting to index this array with an index of
`4` or greater will _invoke_ something called undefined behavior, or UB for short.
Because the program we wrote does not necessarily own the memory immediately
following the array we created, we could be attempting to read or write to memory
that does not belong to us. This could result in a segmentation fault, the program
crashing, and/or, in a worst case scenario, even a corruption of memory belonging
to the operating system, possibly leading to the crashing of your computer.

This begs the question of what the 'type' of `my_array` actually is. In a language
like Java, arrays are what are known as `objects` , which is not necessarily a bad
thing, however unlike C++, Java allocates 100% of their objects on a different,
slower sector of memory called _the heap_, making them vastly inferior. What's
great about C++ is that the programmer can do just about anything with it, including
creating both stack allocated and heap allocated arrays (or more generally, objects).
There are upsides to both the stack and the heap, however the inability to control
them both is where languages like java fall behind.

Anyway, the type of `my_array` in this case is what is called a `pointer`, or more
specifically, an `int pointer`.
