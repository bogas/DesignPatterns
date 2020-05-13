#include "common_design.h"

class Router {
public:
    void work();
private:
    class RoutingImplementation;
    RoutingImplementation* impl;
};
