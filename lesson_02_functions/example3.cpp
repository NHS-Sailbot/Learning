
int my_func() {
    return 5;
}

int main() {
    // notice the type of the variable is the same
    // as the return type of 'my_func'.
    // 'my_variable' will be assigned the value 5.
    int my_variable = my_func();
}

// to run example2.cpp, compile it with
// `g++ example2.cpp -o example2.exe` and run `example2` on Windows or
// `g++ example2.cpp -o example2` and run `./example2` on Linux
