#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct node {
    int l, a;
    node(int ll, int aa) {
        l = ll, a = aa;
    }
};

vector<node> v;
stack<int> s;
int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    string ss;
    cin >> ss;
    int sum = 0;
    for(int i = 0; i < ss.size(); i++) {
        char c = ss[i];
        if(c == '\\') {
            // s.emplace(i);
            s.push(i);
        } else if(c == '/' && !ss.empty()) {
            int j = s.top();
            s.pop();
            int a = i - j;
            sum += a;
            while(!v.empty() && v.back().l > j) {
                a += v.back().a;
                v.pop_back();
            }
            v.push_back(node(j, a));
            // v.emplace_back(j, a);
        }
    }
    cout << sum << endl;
    cout << v.size();
    for(auto a : v) {
        cout << " " << a.a;
    }
    cout << endl;

    return 0;
}
