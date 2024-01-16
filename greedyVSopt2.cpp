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

AddressList generateData(int num){
    AddressList addresses;
    for(int i = 0; i<num; i++){
        int x = rand() % (10 - 1) + 1;
        int y = rand() % (10 - 1) + 1;
        addresses.add_address(Address(x, y));
    }
    return addresses;
}
// SCENARIO
// EACH ROUTE HAS X NUMBER OF ADDRESSES
// CHANGE NUM PRIMES IN EACH ROUTE
int main(){
    srand(time(NULL));
    for(int i = 1; i<=10; i++){
        Route route;
        auto random_addresses = generateData(10);
        vector<Address> addresses = random_addresses.get_vector();
        for(auto address : addresses){
            route.add_address(address);
        }
        cout << "Scenario " << i << '\n';
        cout << "Original Route ";
        route.print();
        cout << '\n';
        cout << "Length: " << route.length() << '\n';
        cout << "Greedy optimization: ";
        auto greedy = route.greedy_route();
        greedy.print();
        cout << '\n';
        cout << "Length: " << greedy.length() << '\n';
        cout << "opt2 optimization: ";
        auto opt2 = route.opt2();
        opt2.print();
        cout << '\n' << "Length: " << opt2.length() << '\n' << '\n';
    }

    return 0;
}