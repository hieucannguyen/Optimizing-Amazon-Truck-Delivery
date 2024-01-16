# Optimizing-Amazon-Truck-Delivery
COE 322 Final Project
## Introduction
This project aims to address the complexities of optimizing Amazon’s delivery truck scheduling, particularly focusing on the unique challenges posed by the Traveling Salesman Problem (TSP) and additionally implementing a solution to the Multiple Traveling Salesman Problem (MTSP)

For an in-depth explanation of the project read our [writeup](TSP_writeup.pdf)

## File Descriptions
- [TSP_writeup.pdf](TSP_writeup.pdf): In-depth explanation of the project
- [AmazonDeliveryTruckScheduling.cpp](AmazonDeliveryTruckScheduling.cpp): Code implementing the Traveling Salesman Problem
- [AmazonDeliveryTruckScheduling.hpp](AmazonDeliveryTruckScheduling.hpp): Header file defining classes 
- [MTSP.cpp](MTSP.cpp): Simulation to test our solution to the Multiple Traveling Salesman Problem
- [PrimeAddressesScenario.cpp](PrimeAddressesScenario.cpp): Simulate the implications of some addresses having an Amazon Prime membership
- [greedyVSopt2.cpp](greedyVSopt2.cpp): Compare the route optimizations between the Greedy algorithm vs. the 2-opt algorithm
- [test.cpp](test.cpp): test functionality
- [CMakeLists.txt](CMakeLists.txt): Run executables

## How to run executables
Use cmake on `CMakeLists.txt` to generate executables
1. clone and navigate into directory
2. create build directory `mkdir build`
3. run cmake `cmake ../CMakeLists.txt`
4. make `make`
5. run executables `./executable` 
