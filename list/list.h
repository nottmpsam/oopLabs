#pragma once
#include <iostream>
class Node {
    int value;
    Node* next;
    Node* prev;

public:

    explicit Node(int key = 0, Node* next_ = nullptr, Node* prev_ = nullptr) {
        value = key;
        next = next_;
        prev = prev_;
    }

    int& getValue() {
        return value;
    }

    void setValue(int value_) {
        value = value_;
    }

    Node*& getNext() {
        return next;
    }

    Node*& getPrev() {
        return prev;
    }

};

class List {

    Node* head, * tail;
    int size;
    void helpAdd(Node* temp, int key);
    Node* findNode(int index) const; 
public:
    List();
    List(int* array, int Range);
    List& operator = (const List& temp);
    List(const List& temp);
    List operator+(const List& temp) const;
    int operator[](int index) const;
    int& operator[](int index);
    void addToHead(int key);
    void addToTail(int key);

    int getSize() const {
        return size;
    }

    void deleteHead();
    void deleteTail();
    void addtoEnd(int key);
    bool addToPosition(int key, int index);
    Node* findELem(int key) const;
    bool addAfterKey(int insert, int key);
    bool delFromPosition(int index);
    void delEnd();
    bool delWithKey(int key);
    ~List();
    int minList() const;
    int maxList() const;
    bool isEmpty() const;
    void clearList();
    bool operator==(const List & temp) const;
    bool operator!=(const List & temp) const;
    void supportDouble();
    friend std::ostream& operator<<(std::ostream& os, List& temp);
    friend std::istream& operator>>(std::istream& in , List& temp);
    Node* getHead() {
        return head;
    }
};

