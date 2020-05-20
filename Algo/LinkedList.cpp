#include "LinkedList.h"

LinkedList &LinkedList::insertBack(int elem) {
    auto newElem = new ListNode(elem);
    if (head == nullptr) {
        head = tail = newElem;
    } else {
        tail->next = newElem;
        tail = tail->next;
    }
    return *this;
}

LinkedList &LinkedList::insertN(int elem, int position) {
    auto currentPosition = 0;
    auto newElement = new ListNode(elem);
    auto p = head;
    if (head == tail or position = 0)
    {

    }
    while (currentPosition != position) {
        if (p->next == nullptr) {
            p->next = newElement;
            tail = p->next;
            return *this;
        }
        p = p->next;
        currentPosition++;
    }
    auto secondPart = p->next;
    p->next = newElement;
    newElement->next = secondPart;
}

int LinkedList::popFirst() {
    auto oldHead = head;
    auto returnValue = oldHead->value;
    head = oldHead->next;
    delete oldHead;
    return returnValue;
}

ostream &operator<<(ostream &os, const LinkedList &linkedList) {
    auto p = linkedList.head;
    while (p != nullptr) {
        os << p->value << " ";
        p = p->next;
    }
    return os;
}

ListNode::ListNode(int value) : value(value) {}

int main() {
    LinkedList list;
    list.insertBack(1).insertBack(3).insertBack(7);
    cout << list << endl;
    return 0;
}
