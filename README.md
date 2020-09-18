# Jim

Experiments with writing a text editor from scratch, kind of.

# Building

## Dependencies

This project depends on [gtkmm](https://www.gtkmm.org/en/), version 3+, so you'll need to have those libraries
somehow before you can build / run the project.

## CMake

[CMake](https://cmake.org/) is used to build the project.

The first time you download the project, or if the build file has changed since you've last downloaded it,
you'll need to run the following command:

```
cmake -S . -B build
```

this will have CMake generate a build directory from the configuration file.

From then on, you can use:

```
cmake --build build
```

to build the project.

This will create an executable `build/jim` which you should be able to run immediately.

