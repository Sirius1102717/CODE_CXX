#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <locale>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

// template <class T>
struct node {
    size_t data;
    shared_ptr<node> prev;
    shared_ptr<node> next;
};

// template <class T>
class list {
private:
    size_t length;
    shared_ptr<node> head;
    shared_ptr<node> tail;

public:
    list();
    void push_back(const size_t& t);
    void show() const;
};
// template <class T>
void list::push_back(const size_t& t) {
    auto tmp = make_shared<node>();
    tmp->data = t;
    if(!length) {
        head = tmp;
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;
        tail->next = nullptr;
    } else {

        tmp->next = tail;
        tmp->prev = tail->prev;
        tmp->prev->next = tmp;
        tail->prev = tmp;
    }
    ++length;
}

list::list() {
    length = 0;
    tail = make_shared<node>();
    tail->prev = tail;
    tail->next = tail;
    tail->data = -1;
    head = tail;
    // tail = make_shared<node>();
    // head->next = tail;
    // head->data = -1;
    // head->prev = nullptr;
    // tail->prev = head;
    // tail->data = -1;
    // tail->next = nullptr;
}

void list::show() const {
    for(auto tmp = head; tmp != tail; tmp = tmp->next)
        cout << tmp->data << '\n';
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    auto l = list();
    for(size_t i = 0; i < 10; i++)
        l.push_back(i);

    l.show();

    return 0;
}
