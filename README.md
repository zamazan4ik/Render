# Simple Graph render

## What is it?
It is just yet another useless graph render. The reason why it was developed only one -
it is the task from WG Forge (for more details go to `task.md` file).

## Requirements for build environment
* C++17-compatible compiler (tested on Clang-7.0)
* Conan package manager
* CMake

## How to build
* Clone sources
* Go to the already cloned directory
* Run conan install .
* Run `cmake .` . Of course you can use another generator - it will change only the next step.
* Run `make -j ${NUM}` 

## How to use
At first you need to install `graphviz` package. How to do it? See instructions for your OS
(e.g. on UNIX-based OS you can use your favourite package manager).

The program takes one parameter - path to the graph. A graph must be presented as valid JSON
file. As output you (if you are lucky :) will get a `dot` file. You can print it with `grapviz`

## FAQ
* Your program does not work - open an issue on GitHub and provide me a brief description of
your problem case and test data.
* Do you have any roadmap? - No, I haven't. Wargaming has :)