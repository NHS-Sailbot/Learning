
int main() {
    float x = 0.1;
    if (x * 10.0 == 1.0) { // This condition fails (is false)
        return 1;
    } else {
        return 2; // This is what gets called
    }
}

// to run example1.cpp, compile it with
// `g++ example1.cpp -o example1.exe` and run `example1` on Windows or
// `g++ example1.cpp -o example1` and run `./example1` on Mac/Linux
