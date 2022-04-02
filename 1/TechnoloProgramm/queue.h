#pragma once
#include <iostream>
#include <string>

class Node {
public:
    int data;
    Node* pNext;
    Node(int value, Node* pNext = nullptr) {
        this->data = value;
        this->pNext = pNext;
    }
};

class List {
public:
    List();
    ~List();
    void  Push_Back(int value);
    int&  operator[](const int index);
    void  operator +(const int& val);
    void  operator -(const int& val);
    void  operator *(const int& val);
    void  operator =(List& obj);
    friend void operator ==(List& Que,  List& obj);
    void  Pop_Front();
    void  SearchMax(List& obj);
    int   GetSize() { return size; };
    void  Copying(List& obj);
    void  Merge(List& obj, const List& obj2);
    Node* GetHead() { return head; };    
protected:
    Node* head;
    int size;
};

std::ostream& operator <<(std::ostream& os, List& obj);
std::istream& operator >>(std::istream& is, List& obj);