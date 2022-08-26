//
// Created by freaver on 12/09/2021.
//

#ifndef LAB4_STACK_H
#define LAB4_STACK_H
#include <cstdio>
#include <ctime>
#include <sched.h>
const int SIZE = 100;
template<class T>
class Stack {
public:
    Stack();
    ~Stack();
    void Push(T);
    T Pop();

private:
    T stack[SIZE];
    int tos;
};

#endif//LAB4_STACK_H
/*
*
*/

template<class T>
Stack<T>::Stack() : tos(0) {}

template<class T>
Stack<T>::~Stack() {
}

template<class T>
void Stack<T>::Push(T t) {
    stack[tos++] = t;
}

template<class T>
T Stack<T>::Pop() {
    tos--;
    if (tos == -1) {
        return nullptr;
    }
    T t = stack[tos];
    return t;
}
