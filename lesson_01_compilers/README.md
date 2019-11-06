# Compilers

## What is a compiler?
A compiler is a program that converts the human written code (in a high level language) 
to machine code (a low level language). 

There are four main steps for compilation:
- Pre-processing
- Tokenization
- Syntactic verification
- Code generation / Optimization 

## Pre-processing
Instructions to the pre-processor can be written in code and are called pre-processing directives.
A pre-processing directive can perform operations on the code that you've written such as copy and
pasting snippets of code or adding and removing sections of code. 

Not every language has a preprocessor, so this is not the most important point of the lesson,
however, in C++ the preprocessor is used very frequently so understanding what it is and
how it works is important.

Every pre-processing directive in C++ is prefaced with a `#` symbol. The `#` symbol has to be the
first *token on the line, as well as there can only be one pre-processing directive per line
so that pre-processing is a simple and quick as possible as to not hold up compilation.

An example of a pre-processing directive used often is the `#include` directive.

`#include` statements require a filename to follow the directive itself, for example `#include <iostream>`.
`iostream` is a text file containing code somewhere on your computer that is accessible to the compiler. 
I will talk more about how files can be accesible to the compiler when I talk about multiple files. All 
the `#include` directive does is directly copy paste the contents of the specified file *into* the file 
being compiled.

Here is a list of all the pre-processing directives in C++

include, if/elif/else/endif, ifdef/ifndef, define/undef, error/line

After pre-processing, all directives are removed for the next stage of compilation

## Tokenization
During the tokenization stage of compilation, the compiler separates words and punctuation so that the 
code can be "read" by the compiler.
