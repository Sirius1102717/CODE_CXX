#include <algorithm>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>
#include<queue>
#include <vector>
using namespace std;
const int N = 100;
struct tree {
    int sum;
    tree *l, *r;
    tree() {
        l = nullptr, r = nullptr, sum = -1;
    }
    friend bool operator>(tree t1, tree t2) {
        return t1.sum > t2.sum;
    }
};

priority_queue<tree, vector<tree>, greater<tree>> a;

char* strappend(const char* s1, const char* s2) {
    char* s = (char*)malloc(sizeof(char) * (strlen(s1) + strlen(s2)));
    // char *s = new(char, strlen(s1) + strlen(s2));
    strcpy(s, s1);
    strcat(s, s2);
    return s;
}

tree build(int n) {
    if(n < 2) {
        return a.top();
    } else {
        tree l = a.top();
        a.pop();
        tree r = a.top();
        a.pop();
        tree node;
        node.l = &l, node.r = &r, node.sum = l.sum + r.sum;
        a.push(node);
        return build(n - 1);
    }
}

// char* get_code(tree* p, int n, char* code) {
// if(p->sum == n) {
// return code;
// } else {
// int len = strlen(code);
// char* new_code = new(char, len + 1);
// strcpy(new_code + 1, code);
// if(p->sum < n) {
// new_code[0] = '0';
// return get_code(p->l, n, new_code);
// return get_code(p->l, n, strcat(code, "0"));
// } else {
// new_code[0] = '1';
// return get_code(p->r, n, strcat(code, "1"));
// }
// }
// }
string get_code(tree& p, int n, string code) {
    if(p.sum == n) {
        return code;
    } else {
        // int len = strlen(code);
        // char* new_code = new(char, len + 1);
        // strcpy(new_code + 1, code);
        if(p.sum < n) {
            // new_code[0] = '0';
            // return get_code(p->l, n, new_code);
            // strcat(code, "0");
            return get_code(*p.l, n, code + '0');
        } else {
            // new_code[0] = '1';
            // strcat(code, "1");
            // strcat(code, "1\0");
            return get_code(*p.r, n, code + '1');
            // return get_code(r, n, strappend(code, "1\0"));
        }
    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/homework/input.txt", "r", stdin);
    int n, i = 0;
    while(~scanf("%d", &n)) {
        tree node;
        node.sum = n;
        a.push(node);
        i++;
    }
    // sort(a, a + N);
    tree head = build(i);
    int m;
    // string s = get_code(head, 8, "0");
    // cout << s << endl;

    // printf("%s\n", get_code(head, 8, ""));
    // printf("%s\n", get_code(head, 4, "\0"));
    // printf("%s\n", get_code(head, 12, "\0"));
    // printf("%s\n", get_code(head, 2, "\0"));
    // printf("%s\n", get_code(head, 6, "\0"));
    // printf("%s\n", get_code(head, 5, "\0"));
    // int m;

    return 0;
}
