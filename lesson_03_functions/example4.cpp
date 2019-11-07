
int cube_volume(int side_length) {
    return side_length * side_length * side_length;
}

int main() {
    // v1 is assigned the value 5^3 or 125
    int v1 = cube_volume(5);
}

// to run example1.cpp, compile it with
// `g++ example4.cpp -o example4.exe` and run `example4` on Windows or
// `g++ example4.cpp -o example4` and run `./example4` on Mac/Linux
