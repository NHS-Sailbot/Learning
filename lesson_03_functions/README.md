# Functions

## How functions are used.
Functions are a way to organize and modularize our code.
They allow us to write some procedure once, and have an
easy to write (and easy to remember) alias when we require
such functionality.

*For example,*

```cpp
void my_func() {
    // does stuff
}

int main() {
    // 'my_func' can be called as often as
    // you would like, and does the same thing
    // every time.

    my_func();
    my_func();
}

// Compilation instructions are inside example1.cpp
```

This is nice to free up some repetition in our code, however it 
isn't very useful. To make `my_func` more useful, we can add 
two things to it:

- [Parameters or 'arguments'](#Parameters)
- [A return type](#Return-types)

## Parameters
Function parameters allow the user to pass data from where they're calling the 
function to inside the function where the function can use the data however it likes.

```cpp
void my_func(int my_parameter, float my_other_parameter) {
	// do stuff with 'my_parameter' and 'my_other_parameter'
}
```

Functions, like most things in C++ inhereted their 'grammar' from C, 
where the function's parameters are listed inside parenthesis after the
name of the function. Each parameter in C++ is separated by a comma.

Now when I call `my_func`, I can put parameters into the parenthesis
to pass any data I would like.

```cpp
int main() {
	my_func(7, 2.5);
}

// Compilation instructions are inside example2.cpp
```

## Return types
Function return types allow the function to pass data from inside the function
back to where it was called from.
Functions are a way to organize and modularize our code.
They allow us to write some procedure once, and have an
easy to write (and easy to remember) alias when we require
such functionality.


A function's return type is listed first, with the name or alias
following. When a return type is given to a function, it must return a value.
This is done by typing `return` followed by the data to be returned.

You'll notice that my example of `my_func` up until this point has had
a return type of `void`, which is actually one of the only two times the keyword
`void` can be used. In this case, the term void just means that the function would
not return a value. 

As well as this, you may have noticed that the main function actually states it
returns an int, however we never write a return statement inside of it. This is because
the main function is actually a special function that does not actually require a return
statement. Because of this, the compiler defaults the return value to be `0`. This return
value is used to signify to the operating system the success/failure state of the program 
as it ends.  

```cpp
// If I change the return type to int, I must return an int
int my_func() {
	return 5;
}
```

When you get the return value back from the function into where it was called from, 
the value can either be assigned to something or even just discarded. 

When the return value of `my_func` is not used, it is still loaded into the appropriate
register (assuming it's not optimized away) but nothing is done with the value in that
register. I plan on talking about memory and how the CPU works in the future, so it is 
completely alright if you don't know what I mean when I say 'register'.

```cpp
int main() {
	// notice the type of the variable is the same 
	// as the return type of 'my_func'. 
	// 'my_variable' will be assigned the value 5.
	int my_variable = my_func();

	// 'my_func' can also be called without it's 
	// return value being used. 
	my_func();
}

// Compilation instructions are inside example3.cpp
```

Finally, I will give an example of a function that may be useful.

```cpp
int cube_volume(int side_length) {
	return side_length * side_length * side_length;
}

int main() {
    // v1 is assigned the value 5^3 or 125
	int v1 = cube_volume(5);
}

// Compilation instructions are inside example4.cpp
```