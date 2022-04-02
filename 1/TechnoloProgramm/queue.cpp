#include "queue.h"
#include <iostream>

using namespace std;

int CheckInt() {
    int digit;
    while (true) {
        cin >> digit;
        if (cin.fail() || cin.get() != '\n') {
            cout << "Некорректный ввод, пожалуйста, введите снова>>";
            cin.clear();
            cin.ignore(32767, '\n');
            continue;
        }
        return digit;
    }
}

List::List() 
{
        head = nullptr;
        size = 0;   
}

List::~List() 
{
    while (size != 0) 
    {    
        Node* temp = head;
        head = temp->pNext;
        delete temp;
        size--;
    }
}

void List::Push_Back(int value)
{
    if (head == nullptr)
        head = new Node(value);
    else 
    {
        Node* current = this->head;
        while (current->pNext != nullptr) 
        {   
            current = current->pNext;
        }
        current->pNext = new Node(value);
    }
    size++;
}

int& List::operator[](const int index)
{

    int counter = 0;
    Node* current = this->head;

    while (current->pNext != nullptr) {
        if (counter == index) return current->data;
        current = current->pNext;
        counter++;
    }
}

void List::operator+(const int& val)
{
    this->Push_Back(val);
}

void List::operator-(const int& val)
{
    cout << "Удаляем элемент " << val << " из очереди..." << endl;
    Node* temp = head;
    if (head->data == val) 
    {
        head = head->pNext;
        delete temp;
        size--;
        return;
    }
    while (temp->pNext != nullptr) 
    {
        if (temp->data == val) 
        {
            delete temp;
            size--;
        }
        temp = temp->pNext;
    }
}

void List::operator*(const int& val)
{
   
    Node* temp = head;
    while (temp->pNext) {
        temp->data *= val;
        temp = temp->pNext;
    }
    temp->data *= val;
}

void List::operator=(List& obj)
{
    this->Copying(obj);
}

void List::Pop_Front()
{
   
    Node* temp = head;
    head = head->pNext;
    delete temp;
    size--;

}

void List::SearchMax(List& obj) 
{

    Node* current = this->head;
   

    int MAX = this->head->data;

    while (current != nullptr) {

        if (current->data > MAX) {
            
            MAX = current->data;
            
        }
            
        current = current->pNext;
    
    }

    cout << MAX << endl << endl;

}

void List::Copying( List& obj) 
{

    int temp[100];
    Node* current = obj.head;

    for (int i = 0; i < obj.size; i++) {

        temp[i] = current->data;
        current = current->pNext;

    }

    for (int i = 0; i < obj.size; i++) {

        Push_Back(temp[i]);

    }
}

void List::Merge( List& obj, const List& obj2) 
{
    
    int temp[100];
    Node* current = obj.head;

    for (int i = 0; i < obj.size; i++) {

        temp[i] = current->data;
        current = current->pNext;

    }

    int lenght = obj2.size + obj.size;
    Node* current2 = obj2.head;

    for (int i = obj.size; i < lenght; i++) {

        temp[i] = current2->data;
        current2 = current2->pNext;

    }
    
    for (int i = 0; i < lenght; i++) {

        Push_Back(temp[i]);

    }
}

void operator==( List& Que,  List& obj)
{
    Node* temp1 = obj.head;
    Node* temp2 = Que.head;
    while (temp2 != nullptr) {
        cout << temp2->data << " == " << temp1->data << " - ";
        if (temp1->data == temp2->data)
            cout << "true\t";
        else cout << "false\t";
        temp2 = temp2->pNext;
        temp1 = temp1->pNext;
    }
    cout << "\n";
}

std::istream& operator>>(std::istream& is, List& obj)
{
    int value;
    while (true) {
        is >> value;
        if (is.fail() || is.get() != '\n') {
            cout << "Некорректный ввод, пожалуйста, введите снова>>";
            is.clear();
            is.ignore(32767, '\n');
            continue;
        }
        obj + value;
        return is;
    }
}

std::ostream& operator<<(std::ostream& os, List& obj) 
{
    Node* temp = obj.GetHead();
    while (temp) {
        os << temp->data << "<--";
        temp = temp->pNext;
    }
    os << endl;
    return os;
}
