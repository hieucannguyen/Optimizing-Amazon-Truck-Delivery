/*

UTEID: hcn357
TACC USERNAME: hieunguyen

UTEID: rnr825
TACC USERNAME: rushilrandhar

UTEID: ss98799
TACC USERNAME: sharansethi

*/

#include "AmazonDeliveryTruckScheduling.hpp"

#include <iostream>
#include <string>
#include <algorithm>
using std::string;
#include <vector>
using std::vector;
using std::cout;

#include <cmath>
using std::sqrt;

// Address class
double Address::distance(Address other){
    double dx = other.i - i;
    double dy = other.j - j;
    return sqrt(dx*dx + dy*dy);
};
// Mark the address as done (delivery completed)
void Address::mark_done(){
    done = true;
};
// Check if the delivery to the address is done
bool Address::is_done(){
    return done;
};
// Check if the address is a prime address
bool Address::is_prime(){
    return prime;
};
// Compare if this address is equal to another
bool Address::equals(Address other){
    return i == other.i && j == other.j;
};
// print address info
void Address::print(){
    if(prime){
        cout << "(" << i << ", " << j << ", prime)";
    }else{
        cout << "(" << i << ", " << j << ") ";
    }
};

// AddressList class
void AddressList::add_address(Address address){
    for(Address a : address_list){
        if(a.equals(address)){
            return;
        }
    }
    address_list.push_back(address);
};
// find lengths of route
double AddressList::length(){
    double length = 0.0;
    for(int i = 0; i<address_list.size()-1; i++){
        // compute the distance between addresses in order
        length += address_list[i].distance(address_list[i+1]);
    }
    return length;
};
// return the vector
vector<Address> AddressList::get_vector(){
    return address_list;
};
void AddressList::remove(int i){
    address_list.erase(address_list.begin()+1,address_list.begin()+i+1);
};
// Find the address closest to a given target address
Address AddressList::index_closest_to(Address target){
    double smallest_distance = target.distance(address_list[0]);
    Address closest_address = address_list[0];
    for(int i = 1; i<address_list.size(); i++){
        double distance = target.distance(address_list[i]);
        if(smallest_distance > distance){
            smallest_distance = distance;
            closest_address = address_list[i];
        }
    }
    return closest_address;
};
// Generate a route based on the greedy algorithm
vector<Address> AddressList::greedy_route(){
    vector<Address> route;
    Address we_are_here(Address(0.,0.));
    route.push_back(we_are_here);
    while(route.size() < address_list.size()+1){
        double smallest_distance = std::numeric_limits<double>::max();
        // ultilize pointers to add Addresses from this vecotor to another
        Address* closest = nullptr;
        for(Address& other : address_list){
            // ensure addresses has not been traveled through
            if(!other.is_done()){                       
                double distance = we_are_here.distance(other);
                if(smallest_distance > distance){
                    smallest_distance = distance;
                    closest = &other;
                }
            }
            
        }
        route.push_back(*closest);
        (*closest).mark_done();
        we_are_here = *closest;
    }
    return route;
};
// print all address in the route
void AddressList::print(){
    for(Address other : address_list){
        other.print();
        cout << " ";
    }
};

// Route class
void Route::add_address(Address other){
    address_list.insert(address_list.end()-1, other);
};
int Route::size(){
    return address_list.size();
};
// Generate a greedy route
Route Route::greedy_route(){
    Route route;
    Address we_are_here(Address(0.,0.));
    while(route.size() < address_list.size()){
        double smallest_distance = std::numeric_limits<double>::max();
        // ultilize pointers to add Addresses from this Route object to another
        Address *closest = nullptr;
        for(int i = 1; i < address_list.size()-1; i++){
            Address &other = address_list[i];
            if(!other.is_done()){                       
                double distance = we_are_here.distance(other);
                if(smallest_distance > distance){
                    smallest_distance = distance;
                    closest = &other;
                    
                }
            }
            
        }
        route.add_address(*closest);
        (*closest).mark_done();
        we_are_here = *closest;
    }
    return route;
};
// Perform a 2-opt swap 
void Route::opt2_swap(int i, int j){
    // works by specifying a [start, end) and reversing that part of the vector
    std::reverse(begin(address_list) + i, begin(address_list) + j + 1);
};
// Optimize the route using the 2-opt algorithm
Route Route::opt2(){
    Route route = *this;
    double smallest_length = route.length();
    bool found_improvement = true;
    while(found_improvement){
        found_improvement = false;
        double current_length = route.length();
        // loop through every possible segment
        for(int i = 1; i<address_list.size()-2; i++){
            for(int j = i+1; j<address_list.size()-1; j++){
                // swap
                Route prev = route;
                prev.opt2_swap(i, j);
                current_length = prev.length();
                // keep if smallest
                if(smallest_length > current_length){
                    route = prev;
                    smallest_length = current_length;
                    found_improvement = true;
                }
            }
        }
    }
    return route;
};
// Reverse the route
void Route::reverse_route(){
    std::reverse(address_list.begin(), address_list.end());
};
// Try a multi-opt2 swap between two routes
bool Route::try_multi_opt2_swap(Route& route1, Route& route2, int i, int j, int k, int l, bool reverse_first, bool reverse_second){
    double original_route1_distance = route1.length();
    double original_route2_distance = route2.length();
    Route new_route_1(route1);
    Route new_route_2(route2);
    // for the different scenarios
    if(reverse_first){
        new_route_1.reverse_route();
    }
    if(reverse_second){
        new_route_2.reverse_route();
    }
    // check bounds so that the swap stays within the route
    if((j-i) <= route1.size()-2 && (l-k) <= route2.size()-2 && i<route1.size()-1 && j<=route1.size()-1 && k<route2.size()-1 && l<=route2.size()-1){
        std::vector<Address> segment_1(new_route_1.address_list.begin() + i, new_route_1.address_list.begin() + j);
        std::vector<Address> segment_2(new_route_2.address_list.begin() + k, new_route_2.address_list.begin() + l);
        for(Address a : segment_1){
            if(a.is_prime()){
                return false;
            }
        }
        for(Address a : segment_2){
            if(a.is_prime()){
                return false;
            }
        }
        // Perform swapping by erasing and inserting segments
        // How it works erase: easres this iterval [start, end) 
        // insert: goes through this interval [start] and appends the specified segment 
        new_route_1.address_list.erase(new_route_1.address_list.begin() + i, new_route_1.address_list.begin() + j);
        new_route_1.address_list.insert(new_route_1.address_list.begin() + i, segment_2.begin(), segment_2.end());

        new_route_2.address_list.erase(new_route_2.address_list.begin() + k, new_route_2.address_list.begin() + l);
        new_route_2.address_list.insert(new_route_2.address_list.begin() + k, segment_1.begin(), segment_1.end());
    }else{
        return false;
    }
    // keep if new distance is smaller
    double new_distance1 = new_route_1.length();
    double new_distance2 = new_route_2.length();
    if(original_route1_distance > new_distance1 && original_route2_distance > new_distance2){
        route1 = new_route_1;
        route2 = new_route_2;
        return true;
    }
    return false;
};
// Optimize two routes using the multi-opt2 method
Route Route::multi_opt2(Route &other){
    Route route = *this;
    bool found_improvement = true;
    while(found_improvement){
        found_improvement = false;
        for(int i = 1; i<address_list.size()-2; i++){
            for(int j = i+1; j<address_list.size()-1; j++){
                for(int k = 1; k<other.address_list.size()-2; k++){
                    for(int l = k+1; l<other.address_list.size()-1; l++){
                        // try four different scenarios
                        // 1. no reverse, 2. reverse one route then swap
                        // 3. reverse the other route then swap 4. reverse both routes and swap
                        if(try_multi_opt2_swap(route, other, i, j, k, l, false, false) ||
                            try_multi_opt2_swap(route, other, i, j, k, l, true, false) ||
                                try_multi_opt2_swap(route, other, i, j, k, l, false, true) ||
                                    try_multi_opt2_swap(route, other, i, j, k, l, true, true)){
                                        found_improvement = true;
                                    }
                    }         
                }
            }
        }
    }
    return route;
};
