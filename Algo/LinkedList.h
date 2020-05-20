#include <ostream>
#include "../common_design.h"

struct ListNode {
    int value;
    ListNode* next = nullptr;
~ListNode(){cout<<"Deleting node with value: "<<value<<endl;}
    ListNode(int value);
};

struct LinkedList {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    LinkedList& insertBack(int elem);
    LinkedList& insertN(int elem, int position);
    int popFirst();

    friend ostream &operator<<(ostream &os, const LinkedList &linkedList);
};