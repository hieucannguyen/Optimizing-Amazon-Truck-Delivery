# Optimizing-Amazon-Truck-Delivery
## Introduction

This project aims to address the complexities of optimizing Amazon’s delivery truck scheduling, particularly focusing on the unique challenges posed by the Traveling Salesman Problem (TSP) and additionally implementing the Multiple Traveling Salesman Problem (MTSP)

For an in-depth explanation of the project read our [writeup](TSP_writeup.pdf) 
## Table of Contents
- [File Descriptions](#file-descriptions)
- [Dependencies](#dependencies)
- [How to Use](#how-to-use)
- [Optimizing Two Paths Simultaneously](#optimizing-two-paths-simultaneously)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## File Descriptions

Briefly describe the purpose of each major file in your project. Provide a high-level overview to help users understand the structure of your project.

- `main.cpp`: Contains the implementation of the multi-path version of the opt2 heuristic for optimizing two paths simultaneously.

- `address_struct.hpp`: Defines the structure representing addresses with x and y coordinates.

- `helper_functions.hpp`: Includes helper functions such as distance calculation and 2-opt swap.

## Dependencies

List any dependencies or prerequisites that users need to have installed before running your program. Include information on libraries, compilers, or other tools that are necessary for your project to function correctly.

## How to Use

Provide clear and detailed instructions on how users can set up and run your program. Include information on:

1. **Compilation**: Instructions for compiling your C++ code.
2. **Input**: How to input addresses and initial paths.
3. **Execution**: Steps to run the program.
4. **Output**: Description of the output, e.g., optimized paths.
