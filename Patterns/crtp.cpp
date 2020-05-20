#include "../common_design.h"

struct Person {
    virtual void speak() { cout << "\nPerson speaking"; }
};

struct Chinese : Person {
    void speak() override {
        Person::speak();
        cout << " in chinese\n";
    }
};

template<typename Derived>
struct Vehicle {
    void interface() {
        run();
        static_cast<Derived *>(this)->run();
    }

    void run() { cout << "\nVehicle moving"; }
};

struct Car : Vehicle<Car> {
    void run() { cout << " on a road\n"; }
};

struct Bike : Vehicle<Bike> {
    void run() {cout <<" on a bikeroad\n";}
};

int main() {
    Person *p = new Chinese();
    p->speak();
    Car car;
    Bike bike; // Vehicle<Bike>
    car.interface();
    bike.interface();
}