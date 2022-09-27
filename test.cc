#include <iostream>
#include <vector>
int main() {
    std::vector<int> v;
    v.push_back(1);
    std::swap(v[0], v[0]);
}
