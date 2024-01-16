/*

UTEID: hcn357
TACC USERNAME: hieunguyen

UTEID: rnr825
TACC USERNAME: rushilrandhar

UTEID: ss98799
TACC USERNAME: sharansethi

*/
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
#include <ctime>
#include <algorithm>

#include "AmazonDeliveryTruckScheduling.hpp"

// Generate data given amount of addresses and amount of prime addresses
AddressList generateData(int num, int numOfPrime){
    AddressList addresses;
    for(int i = 0; i<numOfPrime; i++){
        int x = rand() % (10 - 1) + 1;
        int y = rand() % (10 - 1) + 1;
        //double random  = double(rand()) / RAND_MAX;
        addresses.add_address(Address(x, y,true));     
    }
    for(int i = numOfPrime; i<num; i++){
        int x = rand() % (10 - 1) + 1;
        int y = rand() % (10 - 1) + 1;
        //double random  = double(rand()) / RAND_MAX;
        addresses.add_address(Address(x, y));     
    }
    return addresses;
}
// ADDITION OF PRIME ADDRESS
// AIMS TO FIND THE AVERAGE DISTANCE AS THE PRIME ADDRESS RATIO IN ROUTES GO UP
int main(){
    srand(time(NULL));
    vector<double> avg_dist;
    // loop through num prime addresses
    for(int j = 0; j < 10; j++){
        double total_dist = 0;
        // generate data and compute average optimized total distance
        for(int i = 1; i<=1000; i++){
            Route route1;
            Route route2;
            auto random_addresses1 = generateData(10, j);
            vector<Address> addresses1 = random_addresses1.get_vector();
            for(auto address : addresses1){
                route1.add_address(address);
            }
            auto random_addresses2 = generateData(10, j);
            vector<Address> addresses2 = random_addresses2.get_vector();
            for(auto address : addresses2){
                route2.add_address(address);
            }
            /*
            cout << "Scenario " << i << " Prime addresses: " << j << '\n';
            cout << "Original Routes: " << '\n';
            route1.print();
            cout << '\n';
            route2.print();
            cout << '\n';
            cout << "route1 Length: " << route1.length() << " " << "route2 Length: " << route2.length() << '\n';
            cout << "Multi opt2 optimization: " << '\n';
            auto multiopt2 = route1.multi_opt2(route2);
            multiopt2.print();
            cout << '\n';
            route2.print();
            cout << '\n';
            cout << "route1 Length: " << multiopt2.length() << " " << "route2 Length: " << route2.length() << '\n' << '\n';
            */
            auto multiopt2 = route1.multi_opt2(route2);
            total_dist += multiopt2.length() + route2.length();
        }
        avg_dist.push_back(total_dist/1000.0);
    }
    // print our data
    // not very specific but will do for now
    for(auto n:avg_dist){
        cout << n << " \n";
    }
    

    return 0;
}