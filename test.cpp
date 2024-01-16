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

int main(){
    // Test Address class
    cout << "Testing Address class...\n";
    Address a1(1, 2, true); // Assume Address constructor takes coordinates and a prime flag
    Address a2(3, 4, false);
    cout << "Distance between a1 and a2: " << a1.distance(a2) << "\n";
    cout << "Is a1 prime? " << a1.is_prime() << "\n";
    cout << "Is a1 done? " << a1.is_done() << "\n";
    a1.mark_done();
    cout << "Is a1 done after marking done? " << a1.is_done() << "\n";
    cout << "Does a1 equal a2? " << a1.equals(a2) << "\n";
    cout << "a1: "; a1.print(); std::cout << "\n";

    // Test AddressList class
    cout << "\nTesting AddressList class...\n";
    AddressList list;
    list.add_address(a1);
    list.add_address(a2);
    cout << "Length of AddressList: " << list.length() << "\n";
    cout << "AddressList vector size: " << list.get_vector().size() << "\n";
    list.remove(1); // Assuming this removes the address at index 1
    cout << "AddressList vector size after remove: " << list.get_vector().size() << "\n";
    cout << "Closest to (0,0): "; list.index_closest_to(Address(0, 0)).print(); std::cout << "\n";

    return 0;
}