Resource to allow mods to control how spell tomes work

## Requirements
* [CMake](https://cmake.org/)
	* Add this to your `PATH`
* [PowerShell](https://github.com/PowerShell/PowerShell/releases/latest)
* [Vcpkg](https://github.com/microsoft/vcpkg)
	* Add the environment variable `VCPKG_ROOT` with the value as the path to the folder containing vcpkg
* [Visual Studio Community 2019](https://visualstudio.microsoft.com/)
	* C++ Clang tools for Windows
	* Desktop development with C++
* [Xbyak](https://github.com/herumi/xbyak)

## Register Visual Studio as a Generator
* Open `x64 Native Tools Command Prompt`
* Run `cmake`
* Close the cmd window

## Building
```
git clone https://github.com/Exit-9B/Dont-Eat-Spell-Tomes
cd Dont-Eat-Spell-Tomes
git submodule update --init --recursive
git submodule update --recursive --remote
cmake -B build -S .
```
