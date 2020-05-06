#include <string>
#include <ostream>
#include <iostream>

using namespace std;

struct Person {
    friend ostream &operator<<(ostream &os, const Person &person) {
        os << "\nid: " << person.id << " name: " << person.name;
        return os;
    }

    int id;
    string name;
};

class PersonFactoryBase {

public:
    virtual Person create_person(const string &name) = 0;

    static int counter;

};

int PersonFactoryBase::counter = 0;

class DoctorFactory : public PersonFactoryBase {

public:
    int &counterRef;

    DoctorFactory() : counterRef(counter) {}

    Person create_person(const string &name) override {
        return Person{counterRef++, "Dr " + name};
    }
};

class MsFactory : public PersonFactoryBase {

public:
    int &counterRef;

    MsFactory() : counterRef(counter) {}

    Person create_person(const string &name) override {
        return Person{counterRef++, "Ms " + name};
    }
};


int main() {

    auto msF = MsFactory{};
    auto drF = DoctorFactory{};
    cout << msF.create_person("John");
    cout << msF.create_person("Mary");
    cout << drF.create_person("Filip");
    return 0;
}