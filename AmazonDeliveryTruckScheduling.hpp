/*

UTEID: hcn357
TACC USERNAME: hieunguyen

UTEID: rnr825
TACC USERNAME: rushilrandhar

UTEID: ss98799
TACC USERNAME: sharansethi

*/
#include <string>
using std::string;
#include <vector>
using std::vector;

class Address{
    private:
        double i;
        double j;
        bool done;
        bool prime = false;
    public:
        Address(){}
        Address(double i_coord, double j_coord)
        : i(i_coord), j(j_coord), done(false) {};
        Address(double i_coord, double j_coord, bool is_prime)
        : i(i_coord), j(j_coord), done(false), prime(is_prime) {};
        double distance(Address other);
        void mark_done();
        bool is_done();
        bool is_prime();
        bool equals(Address other);
        void print();
};

class AddressList{
    protected:
        vector<Address> address_list;
    public:
        AddressList(){};
        void add_address(Address address);
        double length();
        vector<Address> get_vector();
        void remove(int i);
        Address index_closest_to(Address target);
        vector<Address> greedy_route();
        void print();
};

class Route : public AddressList {
    private:
        Address depot;
    public:
        Route(){
            depot = Address(0.,0.);
            address_list.push_back(depot);
            address_list.push_back(depot);
        }
        Route(Address start){
            depot = start;
            address_list.push_back(depot);
            address_list.push_back(depot);
        };
        void add_address(Address other);
        int size();
        Route greedy_route();
        void opt2_swap(int i, int j);
        Route opt2();
        void reverse_route();
        bool try_multi_opt2_swap(Route& route1, Route& route2, int i, int j, int k, int l, bool reverse_first, bool reverse_second);
        void multi_swap(Route& route1, Route& route2, int i, int j, int n, int m);
        Route multi_opt2(Route &other);
};
