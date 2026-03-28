#include "List.h"
#include <sstream>


List::Node::Node(int value, Node* prev, Node* next)
    : value(value), prev(prev), next(next) {}

int List::Node::getValue() const { return value; }
void List::Node::setValue(int value) { this->value = value; }

List::Node* List::Node::getNext() const { return next; }
void List::Node::setNext(Node* next) { this->next = next; }

List::Node* List::Node::getPrev() const { return prev; }
void List::Node::setPrev(Node* prev) { this->prev = prev; }

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::List(const List& other) : head(nullptr), tail(nullptr), size(0) {
    addAll(other);
}

List& List::operator=(const List& other) {
    if (this != &other) {
        removeAll();
        addAll(other);
    }
    return *this;
}

List::~List() {
    removeAll();
}

void List::add(int value) {
    Node* node = new Node(value, tail, nullptr);
    if (tail) {
        tail->setNext(node);
    } else {
        head = node;
    }
    tail = node;
    size++;
}

void List::addAll(const List& other) {
    for (Node* n = other.head; n != nullptr; n = n->getNext()) {
        add(n->getValue());
    }
}

int List::first() const {
    return head->getValue();
}

void List::removeFirst() {
    if (!head) return;
    Node* old = head;
    head = head->getNext();
    if (head) {
        head->setPrev(nullptr);
    } else {
        tail = nullptr;
    }
    delete old;
    size--;
}

void List::removeAll() {
    while (!isEmpty()) {
        removeFirst();
    }
}

size_t List::getSize() const { return size; }
bool List::isEmpty() const { return size == 0; }

List List::getReversed(List l) {
    List reversed;
    while (!l.isEmpty()) {
        Node* node = new Node(l.first(), nullptr, reversed.head);
        if (reversed.head) {
            reversed.head->setPrev(node);
        } else {
            reversed.tail = node;
        }
        reversed.head = node;
        reversed.size++;
        l.removeFirst();
    }
    return reversed;
}

std::string List::toString() const {
    std::ostringstream oss;
    for (Node* n = head; n != nullptr; n = n->getNext()) {
        if (n != head) oss << " ";
        oss << n->getValue();
    }
    return oss.str();
}

List& List::operator<<(const int& value) {
    add(value);
    return *this;
}

List& List::operator<<(const List& other) {
    addAll(other);
    return *this;
}
