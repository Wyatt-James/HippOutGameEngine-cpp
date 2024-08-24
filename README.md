# HippOutGameEngine

HippOutGameEngine-cpp is a Game Engine written in C/C++. It is the port of and successor to [HippOutGameEngine](https://github.com/Wyatt-James/HippOutGameEngine), which will be released and likely discontinued soon.

## Build
The officially supported build system for Windows is `cmake` generating `MinGW Makefiles`. Linux is not yet supported.

The following instructions refer to building an executable. This will change in the near-future when the project is restructured to a library, but a self-test executable will likely be provided in the future.

1. Navigate to your project's base directory
2. From the project base directory, run `cmake -G "MinGW Makefiles" -S source -B build` to generate a build system for your platform. 
3. Run `cmake --build build --target HippOutGameEngine-cpp` to build the executable.

## Usage
Run the `build/HippOutGameEngine-cpp.exe`, optionally from the command line to see print output.

## Contributing
see [CONTRIBUTING.md](CONTRIBUTING.md).

## License
See [LICENSE.md](LICENSE.md).
