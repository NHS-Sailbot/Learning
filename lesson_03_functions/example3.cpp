
int my_func() {
    return 5;
}

int main() {
    // notice the type of the variable is the same
    // as the return type of 'my_func'.
    // 'my_variable' will be assigned the value 5.
    int my_variable = my_func();

    // 'my_func' can also be called without it's
    // return value being used.
    my_func();
}

// to run example2.cpp, compile it with
// `g++ example3.cpp -o example3.exe` and run `example3` on Windows or
// `g++ example3.cpp -o example3` and run `./example3` on Mac/Linux
