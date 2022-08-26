//
// Created by freaver on 12/09/2021.
//

#ifndef LAB4_LIST_H
#define LAB4_LIST_H

#pragma once
#include <iostream>
using namespace std;
template<class T>
class List {
public:
    List();
    ~List();
    void Add(T &);
    void Remove(T &);
    T *Find(T &);
    void PrintList();

protected:
    struct Node {
        Node *pNext;
        T *pT;
        Node() {
            pNext = nullptr;
        }
    };

    Node *pFirst;
};

#endif//LAB4_LIST_H

template<class T>
inline List<T>::List() : pFirst(nullptr) {
}

template<class T>
inline List<T>::~List() {}

template<class T>
inline void List<T>::Add(T &t) {
    if (!pFirst) {
        pFirst = new Node;
        //pFirst->pT = &x;
        pFirst->pT = new T;
        *pFirst->pT = t;
    } else {
        Node *p = pFirst;
        while (p->pNext) {
            p = p->pNext;
        }
        Node *node = new Node;
        node->pT = new T;
        *node->pT = t;
        //node->pT = &x;
        p->pNext = node;
    }
}

template<class T>
inline void List<T>::Remove(T &t) {
    Node *pre = pFirst;
    Node *cur = pre->pNext;
    while (cur) {
        if (*cur->pT == t) {
            pre->pNext = cur->pNext;
            delete cur;
            return;
        }
        pre = cur;
        cur = cur->pNext;
    }
}

template<class T>
inline T *List<T>::Find(T &t) {
    Node *p = pFirst;
    while (p) {
        if (*p->pT == t) {
            return p->pT;
        }
        p = p->pNext;
    }
    return nullptr;
}

template<class T>
inline void List<T>::PrintList() {
    Node *p = pFirst;
    while (p) {
        cout << *p->pT << " ";
        p = p->pNext;
    }
}
