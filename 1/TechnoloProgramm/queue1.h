#pragma once
#include "queue.h"

class List_private : private List {
public:
    void  Push_Back(int value);
    int&  operator[](const int index); 
    void  operator +(const int& val);
    void  operator -(const int& val);
    void  operator *(const int& val);
    void  operator =(List& obj);
    friend void operator ==( List& Que, List& obj);
    void  Pop_Front();
    void  SearchMax(List_private& obj);
    int   GetSize() { return size; };
    void  Copying(List_private& obj);
    void  Merge(List_private& obj, List_private& obj2);
    Node* GetHead() { return head; };
};

class List_protected : protected List {
public:
    void  Push_Back(int value);
    int&  operator[](const int index);
    void  operator +(const int& val);
    void  operator -(const int& val);    
    void  operator *(const int& val);
    void  operator =(List& obj);
    friend void operator ==(  List& Que,  List& obj);
    void  Pop_Front();
    void  SearchMax(List_protected& obj);
    int   GetSize() { return size; };
    void  Copying(List_protected& obj);
    void  Merge(List_protected& obj, List_protected& obj2);
    Node* GetHead() { return head; };
};

class List_public : public List {};