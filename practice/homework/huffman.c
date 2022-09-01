#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define ll long long
#define new(type, size) (type*)malloc(sizeof(type) * (size))
#define delete(type) free(type)
#define N 100
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
// const int N = 100;
void swap(void* a, void* b, int size) {
    void* c = new(void, 1);
    memcpy(c, a, size), memcpy(a, b, size), memcpy(b, c, size), delete(c);
}

typedef struct tree tree;
struct tree {
    int sum;
    tree *l, *r;
} a[N];

inline void init(tree** p) {
    *p = new(tree, 1);
    (*p)->sum = -1;
    (*p)->l = NULL, (*p)->r = NULL;
}

int cmp(const void* _a, const void* _b) {
    tree* a = (tree*)_a;
    tree* b = (tree*)_b;
    return b->sum - a->sum;
}

char* strappend(const char* s1, const char* s2) {
    char* s = (char*)malloc(sizeof(char) * (strlen(s1) + strlen(s2)));
    // char *s = new(char, strlen(s1) + strlen(s2));
    strcpy(s, s1);
    strcat(s, s2);
    return s;
}

tree* build(tree* a, int n) {
    if(n < 2) {
        return &a[0];
    } else {
        tree l = a[n - 1], r = a[n - 2];
        tree node;
        node.l = &l, node.r = &r, node.sum = l.sum + r.sum;
        tree b[n - 1];

        int i = 0;
        while(a[i].sum > node.sum && i < n - 2) {
            b[i] = a[i];
            i++;
        }
        b[i] = node;
        while(i < n - 2) {
            b[i + 1] = a[i];
            i++;
        }
        return build(b, n - 1);
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

bool tmp_get_code(tree* p, int n, char* s, int len) {
    if(p->sum == n) {
        return 1;
    } else if(!p->l && !p->r) {
        return 0;
    } else {
        // int len = strlen(code);
        // char* new_code = new(char, len + 1);
        // strcpy(new_code + 1, code);
        // new_code[0] = '0';
        // return get_code(p->l, n, new_code);
        // strcat(code, "0");
        s[len] = '0';
        return tmp_get_code(p->l, n, s, len + 1);
        // new_code[0] = '1';
        // strcat(code, "1");
        // tree* r = p->r;
        // code[++len] = '1';
        // strcat(code, "1\0");
        s[len] = '1';
        return tmp_get_code(p->r, n, s, len + 1);
        // return get_code(r, n, strappend(code, "1\0"));
    }
}


void show_code(tree *p, int len,  int *arr) {
    if (p) {
        if (!p->l && !p->r) {
            printf("%d: ", p->sum);
            for (int i = 0; i < len; i++) {
                printf("%d ", arr[i]);
            }
            puts("");
        } else {
            arr[len] = 0;
            show_code(p->l, len + 1, arr);
            arr[len] = 1;
            show_code(p->r, len + 1, arr);
        }
    }

}

char* get_code(tree* p, int n) {
    static char s[50];

    memset(s, 0, sizeof s);
    int len = 0;
    
    return tmp_get_code(p, n, s, len) ? s : NULL;
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/homework/input.txt", "r", stdin);
    int n, i = 0;
    while(~scanf("%d", &n)) {
        a[i++].sum = n;
    }
    qsort(a, i, sizeof(a[0]), cmp);
    tree* head = build(a, i);
    // get_code(head, 8);
    int arr[50];
    show_code(head, 0, arr);
    // printf("%s\n", get_code(head, 8, ""));
    // printf("%s\n", get_code(head, 4, "\0"));
    // printf("%s\n", get_code(head, 12, "\0"));
    // printf("%s\n", get_code(head, 2, "\0"));
    // printf("%s\n", get_code(head, 6, "\0"));
    // printf("%s\n", get_code(head, 5, "\0"));
    // int m;

    return 0;
}
