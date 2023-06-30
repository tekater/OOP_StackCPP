#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>

using namespace std;

class Stack {
    int* mas;
    int maxsize;
    int top; // "Указатель" на вершину
public:
    Stack(int size = 10);
    void Push(int x);
    int Pop();
    void Clear();
    bool isEmpty();
    bool isFull();
    int getCount();

    void print();

    ~Stack() {
        delete[] mas;
    }
};

Stack::Stack(int size) {
    mas = new int[size];
    maxsize = size;
    top = 0;
}
void Stack::Push(int x) {
    if (!isFull()) {
        mas[top++] = x;
    }
}
int Stack::Pop() {
    if (!isEmpty()) {
        for (int i = 0; i < top - 1; i++) {
            mas[i] = mas[i + 1];
        }
        top--;
        return mas[top];
    }
}
void Stack::Clear() {
    top = 0;
}
bool Stack::isEmpty() {
    return top == 0;
}
bool Stack::isFull() {
    return top == maxsize;
}
int Stack::getCount() {
    return top;
}

void Stack::print() {
    for (int i = 0; i < top; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int main() {

    setlocale(0, "");
    srand(time(NULL));

    Stack stack;
    for (int i = 0; i < 5; i++) {
        stack.Push(rand() % 100);
    }
    stack.print();
    for (int i = 0; i < 2; i++) {
        cout << stack.Pop() << endl;
    }
    stack.print();

    stack.Clear();

    stack.print();
    while (!stack.isFull()) {
        stack.Push(rand() % 100);
    }
    stack.print(); cout << endl;
    while (!stack.isEmpty()) {
        stack.Pop();
    }
    stack.print();


}
