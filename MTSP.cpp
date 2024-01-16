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
// TEST greedy alg vs opt2 alg
int main(){
    srand(time(NULL));
    double dist = 0.;
    for(int i = 1; i<=10; i++){
        Route route1;
        Route route2;
        auto random_addresses1 = generateData(6);
        vector<Address> addresses1 = random_addresses1.get_vector();
        for(auto address : addresses1){
            route1.add_address(address);
        }
        auto random_addresses2 = generateData(6);
        vector<Address> addresses2 = random_addresses2.get_vector();
        for(auto address : addresses2){
            route2.add_address(address);
        }
        cout << "Scenario " << i << '\n';
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
        dist += multiopt2.length() + route2.length();
    }
    cout << dist/1000.;

    return 0;
}