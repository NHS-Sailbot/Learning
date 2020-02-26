# Building C++ Code

Up until now, we have been compiling our code manually, by running the necessary commands in the terminal, in the correct order, in order to compile and run our code. This, although it shows, somewhat, the underlying mechanics when our code is built, is extremely tedious. We could automate this easily with a batch script (or shell script) that runs all these commands for us, because they're the same every time.

An example batch script that builds and runs a program for us could look like this:

```sh
# running_with_scripts/build.bat
g++ main.cpp hello.cpp -c
g++ main.o hello.o -o main.exe
.\main.exe
```

However, if we wanted to compile this on linux, we would have to write a shell script because batch scripts are proprietary to the Windows OS. This could look like so:

```sh
# running_with_scripts/build.sh
g++ main.cpp hello.cpp -c
g++ main.o hello.o -o main
./main
```

Because of this, we would need a script for every operating system that required one, and this leaves extra, unnecessary clutter in our project. You may think to get around this by creating a folder in your projects root directory so that you keep all the build scripts hidden until they're necessary. This works, but doesn't solve the problem where we have to create a build script for every platform. To solve this, we can use what is known as a build system. C++ does not come with a build system by default, and this has forced the community that uses it to create their own. Because of this, there are many different build systems to choose from, and companies sometimes even create their own in order to deal with their own, in house, projects. The build system I would like to talk about is called CMake.

## CMake

CMake is undoubtably the most used build system in the C and C++ community, and, for that reason, I am going to teach it. This will allow you to *simply* use different libraries that are out there that use CMake to build. Using CMake will also solve all of our issues from the first part of this lesson, where we had many object files and, depending on our project, many executables and libraries in our root directory.

So, how do we use CMake?

- First, we'll need to have CMake installed on our computer.
- Then, we will write a CMake script that outlines our project structure.
- And lastly, we'll invoke CMake through the command line to build and run our executable.

## Installing on Windows

On Windows, one would either download it from the CMake website, or install it through Visual Studio. I will cover the global installation in this tutorial because if we were to install it through Visual Studio, we'd only be able to use it inside of Visual Studio. 

Head to the [CMake website's download page](https://cmake.org/download/) and download the Windows installer file (the one with the .msi extension) for the architecture on your machine (this is most likely x64, and I would be surprised if your machine/operating system was 32 bit in this day and age). Once it has downloaded, run through the installer and if it asks to modify the system's `PATH`, say yes. Otherwise, you will have to add the filepath of the directory containing all the binaries (probably `C:\Program Files\CMake\bin`) to the `PATH` environment variable manually.

## Installing on Linux

Installing CMake on Linux should be as simple as just using the package manager for your distrobution. For example, on Ubuntu and Debian based distros, `sudo apt install cmake` should do the trick.

## Verifying the installation

In order to see if our installation was successful, just run `cmake --version` in the console. You should see something like this:

```
cmake version 3.16.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).
```