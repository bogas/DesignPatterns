#include "PImpl.h"
class Router::RoutingImplementation {
    friend class Router;
    void check_state() {cout<< "\nChecking state\n";}
    void probe_ports() {cout<< "\nProbing ports\n";}
    void start_protocols() {cout<< "\nStarting protocols\n";}
    void wait_and_route() {cout<< "\nWaiting routing\n";}
};

void Router::work() {
    impl->check_state();
    impl->probe_ports();
    impl->start_protocols();
    impl->wait_and_route();
}

int main()
{
    Router ro;
    ro.work();
}

