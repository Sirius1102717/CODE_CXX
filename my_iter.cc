#include <iostream>

template <class T> 
struct my_iter {
    typedef T value_type;
    T* ptr;
    my_iter(T* p = 0): ptr(p){}
    T& operator*() const {
        return *ptr;
    }
};

template <class T>
struct my_iterator_traits {
    typedef typename T::value_type value_type;
};

template <class T> 
struct my_iterator_traits<T*> {
    typedef T value_type;
};

template <class T>
struct my_iterator_traits<const T*> {
    typedef T value_type;
};

template <class I>
typename my_iterator_traits<I>::value_type Func(I ite) {
    std::cout << "normal version" << std::endl;
    return *ite;
}

int main(int argc, char *argv[]) {
    my_iter<int> ite(new int(6));
    std::cout << Func(ite) << std::endl;
    int *p = new int(7);
    std::cout << Func(p) << std::endl;
    const int k = 8;
    std::cout << Func(&k) << std::endl;
    return 0;
}

