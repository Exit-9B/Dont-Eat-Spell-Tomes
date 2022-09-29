Resource to allow mods to control how spell tomes work

## Requirements
* [CMake](https://cmake.org/)
	* Add this to your `PATH`
* [PowerShell](https://github.com/PowerShell/PowerShell/releases/latest)
* [Vcpkg](https://github.com/microsoft/vcpkg)
	* Add the environment variable `VCPKG_ROOT` with the value as the path to the folder containing vcpkg
* [Visual Studio Community 2022](https://visualstudio.microsoft.com/)
	* Desktop development with C++
* [SKSE64 SDK](https://skse.silverlock.org/)
	* Add the environment variable `SKSE64Path`

## Register Visual Studio as a Generator
* Open `x64 Native Tools Command Prompt`
* Run `cmake`
* Close the cmd window

## Building
```
git clone https://github.com/Exit-9B/Dont-Eat-Spell-Tomes
cd Dont-Eat-Spell-Tomes
git submodule update --init --recursive

# Skyrim SE
cmake --preset vs2022-windows
cmake --build build --config Release

# Skyrim VR
cmake --preset vs2022-windows-vr
cmake --build buildVR --config Release
```
