# Multiple Files

Up until now, we have only used a single C++ file in our project, compiling it on it's own and directly outputting the executable. This is not suitable for large projects, because they may require thousands of lines of code, and it would be a nuisance to scroll through a single enormous file instead of many *organized* smaller files.

Let's say, for example, we create a function `print_hello()` that prints out the statement `"Hello"`. This is extremely simple, and should not be split into multiple files, but for demonstration purposes, it will do. We will create a file called `hello.cpp` and a file called `main.cpp`. `hello.cpp` will define the `print_hello()` function, and `main.cpp` will impliment our main function (the entry point).

If this were all one file, it would look like this:

```cpp
// main_and_hello.cpp
#include <stdio.h>

void print_hello() {
    printf("Hello");
}

int main() {
    print_hello();
}
```

When we split this into multiple files, one may think that it would look like this:

```cpp
// hello.cpp
#include <stdio.h>

void print_hello() {
    printf("Hello");
}
```

```cpp
// main.cpp
int main() {
    print_hello();
}
```

However, when we compile this (which, by the way, would be done like so: `g++ main.cpp hello.cpp`, where you just supply all the files to compile), the compiler will give us an error that looks like this:

```sh
main.cpp: In function ‘int main()’:
main.cpp:3:5: error: ‘print_hello’ was not declared in this scope
    3 |     print_hello();
      |     ^~~~~~~~~~~
```

This is because of the way our compiler handles multiple files, which I haven't talked about yet. When the compiler compiles code, it compiles each 'translation unit' independently. In the case of our project here, a translation unit is the same thing as each file, so each file is independent of the last. A translation unit, however, contains all the code in the file, including the `#includes` inside, so `hello.cpp`'s translation unit is the entirety of the file after the preprocessor.

Back to the error message. It says that `print_hello` was not decalred in this scope. This means that the compiler cannot see that `print_hello()` exists. This makes sense when you know that the compiler compiles each translation unit independently, and this can be done manually. When we pass both `main.cpp` and `hello.cpp` to `g++`, we are saying that first, we want to *compile* each translation unit (units created by the file) and then we want to link those units together. `g++` does this for us, but like I said before, this can be done manually.

To invoke only the compiler when running `g++` on our code, we must say so. This is done via an extra argument, `-c`. So, to compile our code again, explicitly, let's run `g++ main.cpp hello.cpp -c`. Side note, the `-c` could have been written either before or after the file names, it doesn't matter. After doing this, although the same error is spit out, we will see a new file has been created in our directory, `hello.o`. This is the compiled binary form of `hello.cpp`, called an object file, and was created because the compiler succesfully compiled `hello.cpp`. `main.cpp` failed to compile and thus didn't generate a binary. This sheds a little more light as to why the compiler failed to compile `main.cpp`, because it's compilation is completely independent of `hello.cpp`, however it does not show how to fix the error.

So how is this fixed?

Well, currently the only solution is to declare before-hand, in every translation unit that uses `print_hello()`, the function signature of `print_hello()`. This comes down to hardware reasons, where the program will insert values into certain registers on the cpu for arguments and the return value. Because, in this case, even though our function has no arguments or return value, the compiler does not know that, and it needs to.

The way to tell the compiler the signature of `print_hello()` is to write, before it is called in the main function, the name, return type and argument list of the function, omitting the definition. So, if we change `main.cpp` to look like this:

```cpp
// main.cpp
void print_hello();

int main() {
    print_hello();
}
```

Now, when we compile our code, using `-c` to invoke only the compiler, we get both `main.o` and `hello.o`. This, however, is tedious, and requires the copying of the all necessary function signatures into every file that uses them. Because of this, we use what are known as 'headers', that contain only the declarations (or function signatures) of every function defined elsewhere, and no definitions. Because we're writing C++ code, I would advise you use the file extension `.hpp` for headers instead of `.h`. Although some people use `.h` files for C++ code, I'd recommend using `.h` for code that can be used with C and C++ code, and `.hpp` for C++ only code. When you see libraries that intend on supporting both C and C++ features, they will separate the files. For example, the Vulkan SDK has both a C and C++ API, and they use `vulkan.h` that is intended to be included in either C or C++ code, and `vulkan.hpp`, which will only compile with a C++ compiler. 

Anyways, let's create a header that contains the function signature of the `print_hello()` function. Because it will just be included into every file that requires it, we only need to write it once. This would make our project now look like so:

```cpp
// hello.cpp
#include <stdio.h>

void print_hello() {
    printf("Hello");
}
```

```cpp
// hello.hpp
void print_hello();
```

```cpp
// main.cpp
#include "hello.hpp"

int main() {
    print_hello();
}
```

Note that we used quotes instead of chevrons in our include directive, (`#include "hello.hpp"`). This means that we want to use a relative path to the file, and will search files that are in the same directory as `main.cpp`. If we instead used chevrons (`<hello.hpp>`), we would get a compiler error saying that the compiler could not find the file `hello.hpp`.

Now that our program compiles sucessfully, we can move on to linking the compiled binaries. This is doable either through `g++`, which will automatically detect that we just need to link the files, or through invoking the linker directly, which is the command `ld`. In this case, just write `g++ main.o hello.o` and it will link together these object files. Because we did not specify the desired name of our executable, like before, it will default to `a.exe` (or `a.out` on linux), but we could specify the name in just the same way as before, for example `g++ main.o hello.o -o my_program.exe`.

Now that we have done this, although we have a very, very simple project here, we already have a bunch of files that are created. The root directory of our project looks like this:

```
main.cpp
hello.cpp
hello.hpp
main.o
hello.o
my_program.exe
```

If we were to not specify the `-c` flag during compilation, object files are actually created only inside of our ram (or temp files if there are a lot) and then discarded after the fact, however we will be compiling with `-c` from now own, because it is faster in a future use case. This use case will be talked about in the next part of this lesson, about using a build system.
