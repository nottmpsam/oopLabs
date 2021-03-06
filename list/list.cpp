#include "list.h"
#include <iostream>

std::istream& operator>>(std::istream& in , List& temp) {
    int key;
    while (in >> key)
        temp.addtoEnd(key);
    return in;
}

std::ostream& operator<<(std::ostream& os, List& temp) {
    Node * current = temp.getHead();
    while (current != nullptr) {
        os << current -> getValue() << " ";
        current = current -> getNext();
    }
    return os;
}

List & List::operator=(const List& temp) {
    if (this != & temp) {
        clearList();
        Node * teddy = temp.head;
        while (teddy) {
            addtoEnd(teddy -> getValue());
            teddy = teddy -> getNext();
        }
    }
    return *this;
}

List::List(int* array, int Range) {
    head = tail = nullptr;
    size = 0;
    for (int i = 0; i < Range; ++i)
        addtoEnd(array[i]);
}

List::List(const List& temp) {
    head = tail = nullptr;
    size = 0;
    Node * teddy = temp.head;
    while (teddy) {
        addtoEnd(teddy -> getValue());
        teddy = teddy -> getNext();
    }
}

List List::operator+(const List& temp) const {
    List teddy = *this;
    Node * bear = temp.head;
    while (bear) {
        teddy.addtoEnd(bear -> getValue());
        bear = bear -> getNext();
    }
    return teddy;
}

bool List::operator==(const List& temp) const {
    if (temp.size != size)
        return false;
    Node * teddy = head;
    Node * bear = temp.head;
    while (teddy) {
        if (teddy -> getValue() != bear -> getValue())
            return false;
        teddy = teddy -> getNext();
        bear = bear -> getNext();
    }
    return false;
}

bool List::operator!=(const List& temp) const {
    return !( * this == temp);
}


int List::operator[](int index) const 
{
    if (index < 0 || index >= size)
        return head -> getValue();
    Node * temp = findNode(index + 1);
    return temp -> getValue();
}

int & List::operator[](int index){
    if (index < 0 || index >= size)
        return head -> getValue();
    Node * temp = findNode(index + 1);
    return temp -> getValue();
}

bool List::delFromPosition(int index) {
    if (index < 0 || index >= size)
        return false;
    if (index == 0)
        deleteHead();
    else if (index == size - 1)
        delEnd();
    else {
        Node * temp = findNode(index);
        Node * x = temp -> getNext();
        if (tail == nullptr) {
            temp -> getNext() = temp -> getNext() -> getNext();
            delete x;
        } else {
            x -> getNext() -> getPrev() = temp;
            temp -> getNext() = x -> getNext();
            delete x;
        }
        --size;
    }
    return true;
}

Node * List::findNode(int index) const {
    Node * temp = nullptr;
    int i;
    if (index <= size / 2 || tail == nullptr) {
        temp = head;
        i = 0;
        while (i++ != index - 1)
            temp = temp -> getNext();
    } else {
        temp = tail;
        i = size - index;
        while (i--)
            temp = temp -> getPrev();
    }
    return temp;
}

Node* List::findELem(int key) const {
    Node * startHead = head;
    Node * temp = nullptr;
    int index = 0;
    if (tail != nullptr) {
        Node * endTail = tail;
        while (index++ < getSize()) {
            if (startHead -> getValue() == key) {
                temp = startHead;
                break;
            }
            if (endTail -> getValue() == key) {
                temp = endTail;
                break;
            }
            startHead = startHead -> getNext();
            endTail = endTail -> getPrev();
        }
    } else {
        while (index++ < getSize()) {
            if (startHead -> getValue() == key) {
                temp = startHead;
                break;
            }
            startHead = startHead -> getNext();
        }
    }
    return temp;
}

void List::helpAdd(Node* temp, int key) {

    if (tail != nullptr) {
        Node * newNode = new Node(key, temp -> getNext(), temp);
        temp -> getPrev() = newNode;
        temp = newNode -> getPrev();
        temp -> getNext() = newNode;

    } else {
        Node * newNode = new Node(key, temp -> getNext());
        temp -> getNext() = newNode;
    }
    ++size;
}

bool List::addAfterKey(int insert, int key) {
    Node * temp = findELem(key);
    if (temp != nullptr) {
        if (temp -> getNext() == nullptr)
            addtoEnd(insert);
        else {
            helpAdd(temp, insert);
        }
        return true;
    }
    return false;
}

bool List::addToPosition(int key, int index) {
    if (index < 0 || index >= size)
        return false;
    if (index == 0)
        addToHead(key);
    else if (index == size - 1)
        addtoEnd(key);
    else {
        helpAdd(findNode(index), key);
    }
    return true;
}

int List::maxList() const {
    Node * startHead = head;
    int max = startHead -> getValue();
    if (tail) {
        Node * endTail = tail;
        while (startHead != endTail) {
            if (max < startHead -> getValue())
                max = startHead -> getValue();
            if (max < endTail -> getValue())
                max = endTail -> getValue();
            startHead = startHead -> getNext();
            endTail = endTail -> getPrev();
        }
    } else {
        while (startHead != nullptr) {
            if (max < startHead -> getValue())
                max = startHead -> getValue();
            startHead = startHead -> getNext();
        }
    }
    return max;
}

int List::minList() const {
    Node * startHead = head;
    int min = startHead -> getValue();
    if (tail) {
        Node * endTail = tail;
        while (startHead != endTail) {
            if (min > startHead -> getValue())
                min = startHead -> getValue();
            if (min > endTail -> getValue())
                min = endTail -> getValue();
            startHead = startHead -> getNext();
            endTail = endTail -> getPrev();
        }
    } else {
        while (startHead != nullptr) {
            if (min > startHead -> getValue())
                min = startHead -> getValue();
            startHead = startHead -> getNext();
        }
    }
    return min;
}

bool List::delWithKey(int key) {
    Node * temp = findELem(key);
    if (temp != nullptr) {
        if (temp -> getNext() == nullptr) {
            delEnd();
        } else {
            if (tail == nullptr) {
                Node * current = head;
                while (current -> getNext() != temp)
                    current = current -> getNext();
                current -> getNext() = temp -> getNext();
                delete temp;
            } else {
                temp -> getNext() -> getPrev() = temp -> getPrev();
                temp -> getPrev() -> getNext() = temp -> getNext();
                delete temp;
            }
            --size;
        }
        return true;
    }
    return false;
}

void List::addToHead(int key) {
    Node * temp = new Node(key, head);
    if (tail != nullptr) {
        head -> getPrev() = temp;
    }
    head = temp;
    ++size;
}

List::~List() {
    clearList();
}

void List::supportDouble() {
   
    if (!isEmpty()) { 
        Node * temp;
        temp = tail = head;
        while (tail -> getNext() != nullptr) {
            tail = tail -> getNext();
            tail -> getPrev() = temp;
            temp = temp -> getNext();
        }
    }
}

void List::addToTail(int key) {
    if (tail == nullptr && !isEmpty()) {
        supportDouble();
        Node * newNode = new Node(key, nullptr, tail);
        tail -> getNext() = newNode;
        tail = newNode;
    } else {
        Node * temp = new Node(key, nullptr, tail);
        if (isEmpty()) {
            head = tail = temp;
        } else {
            tail -> getNext() = temp;
            tail = temp;
        }
    }
    ++size;
}

bool List::isEmpty() const {
    return (head == nullptr ? true : false);
}

void List::clearList() {
    while(!isEmpty()) {
        deleteHead();
    }
}

void List::addtoEnd(int key) {
    if (isEmpty()) {
        addToHead(key);
    } else if (tail) {
        addToTail(key);
    } else {
        Node * temp = findNode(size);
        Node * newNode = new Node(key);
        temp -> getNext() = newNode;
        ++size;
    }
}

void List::delEnd() {
    if (!isEmpty()) { 
        if (size == 1) { 
            deleteHead();
        } else if (tail) {
            deleteTail();
        } else {
            Node * temp = findNode(size - 1);
            delete temp -> getNext();
            temp -> getNext() = nullptr;
            --size;
        }
    }
}

void List::deleteTail() {    
    if (!isEmpty()) { 
        if (size == 1) {
            deleteHead();
        } else if (tail == nullptr) {
                delEnd();
        } else {
            Node * temp = tail;
            tail = tail -> getPrev();
            tail -> getNext() = nullptr;
            delete temp;
            --size;
        }
    }
}

void List::deleteHead() {
    if (!isEmpty()) {     
        Node * temp = head;
        if (size != 1)
            head = head -> getNext();
        head -> getPrev() = nullptr;
        delete temp;
        --size;

        if (size == 0) {
            head = tail = nullptr;
        }
    }
}

List::List() {
    head = tail = nullptr;
    size = 0;
}

