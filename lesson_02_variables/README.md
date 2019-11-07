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
`bool`      |    8 | [Integral](#Integers-and-the-binary-number-system:)
`char`      |    8 | [Integral](#Integers-and-the-binary-number-system:)
`short`     |   16 | [Integral](#Integers-and-the-binary-number-system:)
`int`       |   32 | [Integral](#Integers-and-the-binary-number-system:)
`long`      |  *32 | [Integral](#Integers-and-the-binary-number-system:)
`long long` |   64 | [Integral](#Integers-and-the-binary-number-system:)
`float`     |   32 | [Floating point](#Floating-point-numbers-in-memory:)
`double`    |   64 | [Floating point](#Floating-point-numbers-in-memory:)

# So how does the computer store numbers?
The computer stores numbers in memory with `1`s and `0`s. This is both because, technologically, 
storing a `1` or a `0` is trivial, as well as because implimenting circuitry to perform operations 
on `1`s and `0`s is much simpler. A number in memory is a consecutive string of bits. As to how 
these bits are interpreted is dependent on the aforementioned type of memory representation.

There are two main memory representation types on most modern systems, 
[Integral](#Integers-and-the-binary-number-system:) and [Floating point](#Floating-point-numbers-in-memory:).

### Integers and the binary number system:
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

type          | maximum
--------------|---------------:
 `*bool`      |              *1
 `*char`      |             255
 `*short`     |          65,535
 `*int`       |   4,294,967,295
 `*long`      |  *4,294,967,295
 `*long long` | ~18 quintillion

##### the asterisk (*) before the types will be addressed over these next paragraphs.

This, however, does not account for negative numbers. An integer in memory that can hold a negative
quantity has a slightly different representation than just the digits. One may think that it there is
not much of a point having a slightly different number system for negative numbers since one could just
programmatically interpret the range of numbers differently. For instance, in an 8 bit integer, saying 
that 0-127 is just -128 to -1 and 128-255 is 0-127. This however is unoptimal for all situations and 
adds a layer of unnecessary abstraction. Luckily, there is another way. Instead of storing all the numbers
from 0-255, we store 0-127 with the first 7 bits, and then use the final bit to store the sign. This is not
the whole story however, since that would imply there being 2 zeros, a positive zero and a negative zero.
To solve this issue, we need to be thinking of how the numbers are stored. Instead of storing 0 to 127 and 
then -0 to -127, we keep the lower range as 0 to 127, but change the upper range is changed to be -128 to -1.
This system was discovered kind of accidentally, where someone was experimenting with how to find a system
where operations like addition were preserved. This system is called the two's complement where the 
negative version of a number in base 2 is the same as taking the positive version, inverting all the
bits and adding 1. This miraculously preserves the truth of mathematical operations such as addition.

One would expect a negative number added to a positive number to subtract the absolute value of the negative 
number from the positive one. Like I said, this is still true when adding a two's complement number to a 
normal number.

*For example,*
addition | base 10 
---:|---
 01001001 | (73)
+11010101 | (-43) (-00101011 with the two's complement)
~~1~~00011110 | 30

Notice that the first digit of the resulting number is crossed out. This is because we added two 8 bit 
numbers, and the resulting number would require 9 bits. The most significant bit (highest) is discarded 
in this case.

### So how do we denote a 'can be negative', or 'signed', number in code?

Actually, by default, all integral types in C++ are signed. Because of this, to tell the compiler we 
don't want a signed number, we write the keyword `unsigned` before the type. Unsigned numbers can hold
the full range listed above, `0` to `2^N-1`, and signed numbers, while having the same breadth, have
a range from `-2^(N-1)` to `2^(N-1)-1`. This is why there is an asterisk on the table above, since
the actual maximum of, for example, a char is actually 127 instead of 255, even though there is still
256 possible numbers.

## Floating point numbers in memory:

Floating point numbers are much more complicated than integers. A great way to explain how the computer
stores fractional quantities is scientific notation. For example, if you were to store a number in a 
`float`, which consists of 32 bits, a portion of those bits (8 bits, according to the IEEE-754 standard) 
would go to storing an exponent to which 2 is raised, as well as a portion (23 bits) for a multiplier
(what they call a mantissa) and one bit for a sign. Custom circuitry is required both for doing 
mathematical operations on floating point numbers, as well as converting to and from integers.

If we think about scientific notation, it is standard to keep the multiplier out front only ranging from
1 through 9.99. This is because a number less than one could be represented in the 1-9.99 by decreasing 
the exponent by one, or increasing it on the opposite case. Since in base 2 we only have to think about
having a number ranging from 1 through 1.99, the standard only stores the fractional part of the mantissa. 
For example, if the computer wanted to store a 10.0 as a floating point number, it would 3 in the exponent
portion, as well as 0.25 in the mantissa. This is because `(0.25 + 1) * 2^3` equals `10`.

One thing to note about floating point numbers is that the precision as the number gets greater diminishes
in the same way it would in scientific notation. Imagine having (in base 10) two decimal places for your
number, such as `3.16 * 10^4`. In such a case, with an exponent of 2, each hundredth in the multiplier
would represent a whole integer, and increasing the exponent would render the hundredths in the multiplier
even less precise.

![Diagram of floating point accuracy per whole number](http://blog.reverberate.org/img/FloatingPoint/FloatVsInteger1.png)

Notice the precision falling below that of an integer when representing a number above 2^23, since the
mantissa, or multiplier, in a 32 bit float consists of 23 bits, aka 23 binary 'decimal' places.

Another very important thing to know about floating point numbers is that it falls into the same pitfalls
as normal scientific notation, where it cannot even represent fractional quantities like how 1/3 (in base
10), the decimal expansion is 0.333 repeating (Fun fact, 1/3 in binary is 0.01010101 repeating). This is
important to be thinking about while writing your code because when writing a floating point literal into
your code, such as `float x = 0.1`, you may think that `x` actually equals exactly `0.1`, however, the 
binary representation of 0.1 is 0.000110011001100...

Because of this, in the following program, the main function will return the value `2`.

```cpp
int main() {
    float x = 0.1;
    if (x * 10.0 == 1.0) { // This condition fails (is false)
        return 1;
    } else {
        return 2; // This is what gets called
    }
}

// Compilation instructions are inside example1.cpp
```

This is because multiplying 0.000110011001100.. (binary 0.1) by 1010 (binary 10) results in (in base 10)
`1.000000014901..`. This is the same concept as multiplying 0.33333.. by 3 and getting 0.99999.., not 1.
