#include <algorithm>
#include <cstdio>
#include <iostream>
#include <mutex>
#include <string>
#include <vector>

using namespace std;

class singleton {
private:
    singleton() = default;
    singleton(const singleton&) = default;
    singleton(singleton&& s) = default;
    singleton& operator=(const singleton&);

public:
    static singleton& get_instance() {
        static singleton INSTANCE;
        return INSTANCE;
    }

    void print() {
        std::cout << "hello world\n";
    }
};

int main(int argc, char* argv[]) {
    // auto s2 = singleton::get_singletion;
    printf("%p %p\n", &singleton::get_instance(), &singleton::get_instance());
    vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    return 0;
}
