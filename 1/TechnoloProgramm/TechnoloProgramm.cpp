#include "queue.h"
#include "queue1.h"
#include <iostream>
#include <string>;
using namespace std;

int IsInt() {

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


void Merge(List* Que) {
    
    int number1, number2, number3;
    cout << "Выберите очереди которые обьединятся" << endl;
    number1 = IsInt(); 
    number2 = IsInt(); 
    cout << endl;
    cout << "Выберите куда произойдет слияние двух очередей" << endl;
    number3 = IsInt();
    Que[number3].Merge(Que[number1], Que[number2]);

}


void Copy(List* Que, List& obj) {
    
    int number;
    cout << "Куда скопировать?" << endl;
    number = IsInt();
    Que[number] = obj;

}


void IsEqual(List* Que, List& obj) {
   
    cout << "С какой очередью сравнить?" << endl;
    int number = IsInt();
    Que[number] == obj;

}

int ChooseQueue(int num) {
   
    cout << "Введите номер очереди" << endl;
    int choice;
    choice = IsInt();
    if (choice > num) {
        cout << "Очереди №" + to_string(choice) + " не существует, попробуйте снова." << endl;
        ChooseQueue(num);
    }
    system("cls");
    return choice;

}


bool IsEmpty(List& obj) {
    
    if (obj.GetHead() == nullptr) {
        cout << "Очередь пуста, задание невыполнимо" << endl;
        system("pause");
        return 1;
    }

}


void FindMaxElem(List& obj, const int number) {
    
    if (IsEmpty(obj)) {
        return;
    }
    cout << "Максимальный элемент очереди №" + to_string(number) << endl;
    obj.SearchMax(obj);

}


void DelElem(List& obj) {
    
    if (IsEmpty(obj)) {
        return;
    }
    int val;
    cout << "Введите элемент на удаление>>";
    val = IsInt();
    obj - val;
}


void Del(List& obj) {
    
    if (IsEmpty(obj)) {
        return;
    }
    obj.Pop_Front();

}


void Show(List& obj, const int number) {

    cout << "Очередь №" + to_string(number) << endl;
    cout << obj;

}


void Multiply(List& obj) {

    if (IsEmpty(obj)) {
        return;
    }
    cout << "Введите множитель для очереди>>";
    int val = IsInt();
    obj*val;
}


void Add(List& obj, const int number) {

    cout << "Добавить элемент в текущую очередь №" + to_string(number) << endl;
    cout << "Введите значение: ";
    cin >> obj;
}


void Menu(List* QueList, int num) {

    int choice = 0;
    int c;
    int work = 1;
    
    while (work) {

        cout << "Главное меню" << endl;
        cout << "1.  Добавление элемента очереди" << endl;
        cout << "2.  Извлечение первого элемента очереди" << endl;
        cout << "3.  Извлечение элемента очереди по значению" << endl;
        cout << "4.  Вывод очереди на экран" << endl;
        cout << "5.  Нахождение максимального элемента очереди" << endl;
        cout << "6.  Выбор очереди для работы" << endl;
        cout << "7.  Создание копии очереди" << endl;
        cout << "8.  Слияние двух очередей" << endl;
        cout << "9.  Увеличить элементы очереди в пользовательское число раз" << endl;
        cout << "10. Сравнение двух очередей" << endl;
        cout << "0.  Завершить работу программы" << endl;
        cout << "Выберите пункт меню >>";
        c = IsInt();
        
        system("cls");

        switch (c) {
        case 1:  

            Add(QueList[choice], choice);
            break;

        case 2:

            Del(QueList[choice]);
            break;

        case 3:

            DelElem(QueList[choice]);
            break;

        case 4:

            Show(QueList[choice], choice);
            break;

        case 5:

            FindMaxElem(QueList[choice], choice);
            break;

        case 6:

            choice = ChooseQueue(num);
            break;

        case 7:

            Copy(QueList, QueList[choice]);
            break;

        case 8: 

            Merge(QueList);
            break;

        case 9:
             
            Multiply(QueList[choice]);
            break;

        case 10:

            IsEqual(QueList, QueList[choice]);
            break;

        case 0: 

            exit(0);
            break;

        default:

            cout << "Выберите существущий пункт меню." << endl;
            break;
        }
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    List* Queue = NULL;
    
    cout << "Задайте количество очередей для работы:" << endl;
    int num;
    num = IsInt();
    Queue = new List[num];
    system("cls");
    Menu(Queue, num);
    delete[] Queue;
 
    return 0;

}