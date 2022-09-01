#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> a, b;

int n;
int get_kth_element(int k) {
    int i1 = 0, i2 = 0;
    while(1) {
        if(i1 == n) return b[i2 + k - 1];
        if(i2 == n) return a[i1 + k - 1];
        if(k == 1) return min(a[i1], b[i2]);

        int ni1 = min(i1 + k / 2, n) - 1;
        int ni2 = min(i2 + k / 2, n) - 1;
        int p1 = a[ni1], p2 = b[ni2];
        if(p1 <= p2) {
            k -= ni1 - i1 + 1;
            i1 = ni1 + 1;
        } else {
            k -= ni2 - i2 + 1;
            i2 = ni2 + 1;
        }
    }
}

int find_mid() {
    return (get_kth_element(n) + get_kth_element(n + 1)) / 2;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.emplace_back(x);
    }
        
    for(int i = 0; i < n; i++) {
        cin >> x;
        b.emplace_back(x);
    }
    cout << find_mid() << '\n';

    return 0;
}
