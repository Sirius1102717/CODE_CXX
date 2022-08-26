#include "Stack.h"
//#include "Stack.cpp"
#include "List.h"
#include <iostream>
template<class T>
T Min(const T& a, const T& b) {
    return a < b ? a : b;

    //bool operator < (char* a, char* b) {
    //return strcmp(a, b) <= 0 ? a : b;
    //}
}
int main() {
    List<int> l;

    for (int i = 0; i < 5; i++) {
        l.Add(i);
    }
    int n = 2;
    int m = 3;
    l.Remove(m);
    cout << *l.Find(n) << endl;
    l.PrintList();
    //char* a = "abc";
    //char* b = "abd";
    //cout << Min(a, b) << endl;

    return 0;
}
