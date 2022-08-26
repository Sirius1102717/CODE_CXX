#include <iostream>
#include <utility>

template<class T>
class share_ptr {
private:
    size_t* __num;
    T* __ptr;

public:
    share_ptr() : __ptr(nullptr), __num(new size_t) {}
    share_ptr(share_ptr&& sp) : __ptr(sp.__ptr), __num(sp.__num) {
        ++(*__num);}
        share_ptr(const share_ptr& sp): __ptr(sp.__ptr), __num(sp.__num){++(*__num);}
        share_ptr(T* t): __ptr(t), __num(new size_t){*__num = 1;}

        ~share_ptr() {
            --*__num;
            if (__num == 0) {
                delete __ptr;
                delete __num;
                __ptr = nullptr;
                __num = nullptr;
            }
        }

        T* operator->() {
            return *__ptr;
        }

        void operator=(share_ptr&& sp) {
            share_ptr(std::move(sp));
        }

        void operator=(const share_ptr& sp) {
            share_ptr(std::move(sp));
        }

        T& operator*() {
            return __ptr;
        }

        operator bool() {
            return __ptr == nullptr;
        }

        bool unique() {
            return *__num == 1;
        }

        void swap(share_ptr& sp) {
            swap(*this, sp);
        }

        size_t use() {
            return *__num;
        }
};

int main(int argc, char *argv[]) {
    int a = 1;
    share_ptr<int> b(&a);
    {
        auto c = share_ptr<int>(b);
        std::cout << b.use() << ' ' << c.use() << '\n';
    }
    std::cout << b.use() << '\n';

    return 0;
}

