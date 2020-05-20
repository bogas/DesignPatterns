#include <ostream>
#include "../common_design.h"
//#pragma pack(1)

struct S {
    char x;
    char *y;
    int z;
};


struct Y {
    short a;
    int c;
    short b;
};

struct ListNode {
    ListNode(int elem) : value(elem) { next = nullptr; }

    ~ListNode() { cout << "Deleting " << value << endl; }

    int value;
    ListNode *next;

};

struct MyList {
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    void print() {
        auto p = head;
        //cout<<p<<endl;
        while (p != nullptr) {
            cout << p->value << " ";
            p = p->next;
        }
    }

    void insertBack(int element) {
        auto newElem = new ListNode(element);
        if (head == nullptr) {
            head = newElem;
            tail = newElem;
            return;
        }
        tail->next = newElem;
        tail = tail->next;
        cout << "Adding value " << element << endl;
    }

    int getFirst() {
        auto result = head;
        int value = head->value;
        head = head->next;
        cout << "Deleting value " << value << endl;
        delete result;
        return value;
    }
};

template<typename B, typename D>
bool isDerivedFrom(B &base, D &derived) {
    try {
        dynamic_cast<B &>(derived);
        return true;
    }
    catch (...) {
        return false;
    }
}

struct A {
    virtual void foo() {};
};

struct B : A {
};
struct C {
};

//template<typename Base, typename Der, class = typename enable_if<is_base_of<Base, Der>::value>::type>
//bool _isDerivedFrom() { return true; }
//
//template<typename Base, typename Der, typename enable_if<!is_base_of<Base, Der>::value>::type>
//bool _isDerivedFrom() { return false; }
template<typename Base, typename Der>
bool _isDerivedFrom(){return is_base_of<Base,Der>();}

int main() {
    MyList myList;
    myList.insertBack(10);
    myList.insertBack(11);
    myList.insertBack(12);
    myList.getFirst();
    myList.getFirst();

    A a;
    B b;
    C c;
    cout << isDerivedFrom(a, b) << " " << isDerivedFrom(b, a) << " " << isDerivedFrom(c, b) << " " << endl;
    cout << _isDerivedFrom<A,B>() << " "
            << _isDerivedFrom<B,A>() << " "
                    << _isDerivedFrom<C,B>() << " " << endl;
}