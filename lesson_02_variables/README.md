# Variables

## How variables are used
Variables are used to store data, and are the first thing relevant to memory in this course.
Memory is **the** most important thing in programming (closely followed by logic) so there 
will be many lessons on how memory can be used and manipulated. Variables have both a type 
and a name, allowing the programmer to reference the allocated data easily.

To create a variable, you first write the type and then the name you would like to give it, *for example:*

```cpp
int my_variable;
```

This allocates a fixed size of memory on the stack, allowing for data to be stored in a 
location that *to the programmer* is labeled by the name of the variable.

Side note, as well as being able to allocate the memory, you can immediately assign some
data into the location. This is done by using the assignment operator `=`, *for example:*

```cpp
int my_variable = 4;
```

## So what is a type?
In C++, because there is so much freedom with what the programmer can do directly to memory,
the most important thing to know about a type is the size in memory that is allocated when 
declaring a variable with such type. Different variable types can have different sizes for 
optimization purposes, allowing the programmer to create a program with a fixed size down 
to the byte.

### A list of the different sizes of all the different types:
type        | size | memory representation
------------|-----:|----------------------
`bool`      |    8 | Integral
`char`      |    8 | Integral
`short`     |   16 | Integral
`int`       |   32 | Integral
`long`      |  *32 | Integral
`long long` |   64 | Integral
`float`     |   32 | Floating point
`double`    |   64 | Floating point

## So how does the computer store numbers?
The computer stores numbers in memory with `1`s and `0`s. This is both because, technologically, 
storing a `1` or a `0` is trivial, as well as because implimenting circuitry to perform operations 
on `1`s and `0`s is much simpler. A number in memory is a consecutive string of bits. As to how 
these bits are interpreted is dependent on the aforementioned type of memory representation.

There are two main memory representation types on most modern systems, **Integral** and **Floating point**.

## Integral numbers in memory
### The binary number system: 
Integers are stored in memory in a very familiar way to how we think of numbers from day to day.
When you think of counting, you probably think of '0, 1, 2, 3, ...' and that each consecutive number
represents a quantity 1 greater than the previous. Something to note is that we do not have a unique
symbol for every single number, instead, we have 10. When we reach the eleventh quantity, we use a
combination of symbols, a `1` and a `0`. This is called base 10 positional notation. 

Computers store integers in base 2 positional notation, where there are only two symbols. Because of 
this, counting looks like this: '0, 1, 10, 11, 100, 101, ...'. The size in memory that different
types take up represent a different maximum number that an integer can hold. This is because the set
of bits allocated for the variable *represent* the place values, or digits, of the number. For example, 
in base 10, the largest possible number represented by 8 digits is 99,999,999. Notice this number is 
`10^8-1`. Similarly, the largest number represented by 8 digits in base 2 is (in base 10) 255, where 
`2^8-1 = 255`.

In conclusion, a binary integer with `N` bits can hold a number from `0` to `2^N-1`

This, however, does not account for negative numbers. An integer in memory that can hold a negative
quantity has a slightly different representation than just the digits. 