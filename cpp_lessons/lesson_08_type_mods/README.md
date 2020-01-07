# Data Type Modifiers

Now is a good time to bring up what modifiers can be used when declaring or defining variables. Similar to how the `unsigned` keyword can be used to modify the data type that a integral varible is, there are many other modifiers that apply to all variables.

- [const](#Const)
- [static](#Static)
- [constexpr](#Constexpr)
- [inline](#Inline)

## Const

The const modifier can be used on both variable types, argument types and function return types. It tells the compiler that the variables data can be allocated in a read only sector of memory, since its value will not change throughout the runtime of the program. An example of const's usage in a variable definition is as follows:

```cpp
const int a = 10;
a = 14;
```

The second line results in a compiler error, since we are attempting to assign to a const variable. Something to note is that an uninitialized variable that is declared const will also result in a compiler error, since later on in the program we would have to assign something to it.

When declaring a function as const, it is more or less meaningless, since the return type from a function is always an r-value, and is not something stored in memory, except for when returning a reference (which is almost never) it is different. I have _never_ written code in which I am returning a const reference, however it could happen.

For pointers, one can apply `const`-ness in two different ways, one applying to the type of data the pointer is pointing to, as well as the pointer's value itself. This is because a pointer can still be modifiable while pointing to read only memory, or can be pointing to mutable memory but still cannot be changed what it is pointing to, where the actual value of the pointer, aka the memory address, is stored in read only memory. To write this,one would do so like this:

```cpp
const int a1 = 10, a2 = 15;
const int *const b = a1;

// both of these next lines are illegal
*b = 20; // error, assignment to a const int
b = a2; // error, assignment to a *const

// The only thing doable in this case is reading
// from b and the contents pointed to by b
int c = *b;
const int *c = b;
```

Note that when assigning the value of `b` to `c` as a pointer, that `c` must point to a `const int`. This is because `b` points to a sector in memory that is possibly read-only, and if we could assign `b` to a non-`const int *`, we could write to values that were originally in read-only memory, which could lead to bad things.

## Static

Static is a modifier keyword that is strange because it's mnemonic is not very apt to its meaning. The static modifier makes the variable or function that it is used on _constrained to the translation unit_ that it's inside. The concept of translation units has not yet come up, however one can think of it as being the file that the code is written in. Static also has another use relevant to object orientation, however that will be mentioned in a later lesson.

When the static keyword is used, it tells the compiler that no external linkage is necessary, and thus further optimizations, including completely removing a function or variable from the compiled binary.

```cpp
static void my_func() {
    // does some stuff
}

int main() {
    // does not call my_func()
}
```

In this example, `my_func()` is not ever called. If `my_func()` were not labelled as static, the compiler would still include it in the executable that is compiled because `my_func()` could be called from another executable along side ours. Since we created `my_func()` and we don't want or expect other code to be calling it, we can label it `static`, meaning it will only be visible inside this TU, or in this case, `.cpp` file, thus, in this case, only `main()` can call `my_func()`. Because in the example, `main()` does _not_ call `my_func()`, the compiler knows that it can remove `my_func()` entirely from the executable.

`static` cannot be applied to function parameters, for it would not make sense.

## Constexpr

Constexpr is one of my favorite parts of C++, and is one of the main reasons that I write in C++ over C. The constexpr modifier allows the programmer specify whether a variable or function (or possibly a func. param. in the future, since discussions over this were had during the C++20 ISO meetings) should be evaluated at compile time. This means that something could be pre-evaluated and would not impact runtime performance, allowing for significant optimizations over program speed and writing speed. To mark a variable or function as a constexpr, one would write `constexpr` before the type of the variable or before the return type of a function like so:

```cpp
constexpr int my_var = 10;
constexpr int my_func() {
    return 10;
}
```

This, however, neglects the usefulness of the compile time evaluation that constexpr provides. A great example of this would be to write a function that performs some calculations, that you know would not be affected by the runtime of a program, eg. input or external manipulation, that when used could be evaluated before hand, for example:

```cpp
constexpr int sq(int a) {
    return a * a;
}

constexpr int my_area = sq(16);
```

One major difference between a constexpr function and a constexpr variable is one that may change in the near future (as again discussed for C++20 or later), being that a constexpr variable must be evaluated at compile time, however a constexpr function is more or less a _maybe_ evaluated at compile time. If evaluated entirely in the constexpr context, a constexpr function will be evaluated at compile time, like in the example above, however, if there were keyboard input or commandline arguments that affected the argument in the `sq` function, the code would have to be evaluated at runtime, since there would be no way of knowing what the resulting value would be. This theoretical example would also cause a compiler error, since the value returned from calling `sq` would not result in a compile time constant, and thus `my_area`, which is marked constexpr, would not be evaluated at compile time, which as I said earlier, is 'illegal'.

## Inline

The inline keyword only applies to functions (and, as of the C++17 standard, member variables, which are again relevant to object orientation and will be talked about later). It tells the compiler that a function _should_ be inlined when possible, or simply inserted, line by line, into the place where it is called. This is useful for optimization purposes, where short snippets of code can be put into a function for organizational purposes without the imposition of a runtime impact from a function call. To mark a function inline, one would put the keyword inline somewhere before the function name, like so:

```cpp
inline void my_func() {
    // does some stuff
}
```

As said before, one would mark a function only containing short snippets of code as inline, because when the entirety of a large function is inlined in many places, it can drastically increase the size of the executable generated.

A variable can be marked both `static` and `constexpr` (and `const`), and thus the question arises, 'which should be written first?'. You will see that in the Sailbot code that `static` comes before `constexpr`, and this was a concious descision made by me, for the order does not affect the code, however, I see `constexpr` being intrinsic to the type of a variable/return type of a function, thus I put it directly behind the type. In a function, one may use all four modifiers, and I would put them in order like so, for example:

```cpp
static constexpr /* const */ int a = 10;
static inline constexpr /* const */ int func() {
    return 10;
}
```

note that I omitted the use of `const` when declaring something `constexpr`. This is because the compiler may implicitly declare something as `const` when marked `constexpr`, as well as, since it is going to be evaluated at compile time, there would be no value that is stored in read only memory.
