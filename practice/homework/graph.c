#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define ll long long
#define new(type) (type*)malloc(sizeof(type))
#define delete(type) free(type)
const double EPS = 1e-8;
#define N 100
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
void swap(void* a, void* b, int size) {
    void* c = new(void);
    memcpy(c, a, size), memcpy(a, b, size), memcpy(b, c, size), delete(c);
}

int dis[N][N];
int next_point[N][N];
int point[N];
int tot, m;

typedef struct list list;
typedef struct graph graph;

struct list {
    char* name;
    list* next;
};

struct graph {
    int to;
    int nex;
    int w;
    int c;
} e[N];
int w[N], c[N];

void copy(char** o, char* name) {
    *o = (char*)malloc(sizeof name);
    strcpy(*o, name);
}

void init(list** p) {
    // *begin = (list*)malloc(sizeof(list));
    *p = new(list);
    (*p)->next = NULL;
    (*p)->name = NULL;
}

void push_back(list** end, char* name) {
    list* newNode;
    init(&newNode);
    copy(&newNode->name, name);
    // strcpy(newNode->name, name);
    (*end)->next = newNode;
    *end = newNode;
}

inline bool empty(list* p) {
    return p->next;
}

bool has(list* head, char* name) {
    list* p = head;
    while(p) {
        if(p->name && !strcmp(p->name, name)) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void insert_back(list* head, list** end, char* name) {
    if(!has(head, name)) {
        push_back(end, name);
        m++;
    }
}

int get_index(list* head, char* name) {
    int n = 0;
    list* p = head->next;
    while(p) {
        if(p->name && !strcmp(p->name, name)) {
            return n;
        }
        n++;
        p = p->next;
    }
    return -1;
}

int fa[N];

int get_fa(int x) {
    return !~fa[x] ? x : (fa[x] = get_fa(fa[x]));
    // return fa[x] == x ? x : get_fa(fa[x]);
}

bool join(int x, int y) {
    int xx = get_fa(x);
    int yy = get_fa(y);
    if(xx != yy) {
        fa[xx] = yy;
        return 1;
    }
    return 0;
}

int cmp(const void* _a, const void* _b) {
    graph a = *(graph*)_a;
    graph b = *(graph*)_b;
    return a.c - b.c;
}

int kruskal() {
    int ans = 0;
    int n = 0;
    // for (int i = 0; i < m; i++) {
    // fa[i] = i;
    // }
    memset(fa, -1, sizeof fa);
    qsort(e, tot, sizeof(graph), cmp);
    for(int i = 0; i < tot; i++) {
        int to = e[i].to, nex = e[i].nex;
        if(join(to, nex)) {
            printf("%d->%d: %d\n", e[i].to, e[i].nex, e[i].c);
            ans += e[i].c;
            n++;
        }
    }
    return n == m - 1 ? ans : -1;
}

int prim() {
    int ans = 0;
    int a[m], len_a = 0;
    bool b[m];
    memset(b, 0, sizeof b);
    a[len_a++] = 0;
    b[0] = 1;
    for(int i = 1; i < m; i++) {
        int mmin = INF;
        int pos = -1;
        int tmp;
        for(int k = 0; k < len_a; k++) {
            int to = a[k];
            int next_size = point[to];
            for(int j = 0; j < next_size; j++) {
                int p = next_point[to][j];
                if(!b[p] && dis[to][p] < mmin) {
                    tmp = to;
                    mmin = dis[to][p];
                    pos = p;
                }
            }
        }
        if(~pos) {
            ans += mmin;
            printf("%d->%d %d\n", tmp, pos, mmin);
            b[pos] = 1;
            a[len_a++] = pos;
        } else {
            return -1;
        }
    }
    return ans;
}

int main(int argc, char* argv[]) {

    freopen("/home/freaver/CODE_C/practice/homework/ds/services.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/homework/ds/output.txt", "w", stdout);
    char to[N], nex[N];
    int ww, cc;
    list *head, *end;
    init(&head);
    end = head;
    tot = m = 0;
    memset(dis, INF, sizeof dis);
    memset(point, 0, sizeof point);
    memset(next_point, -1, sizeof next_point);
    while(~scanf("%s%s%d%d", to, nex, &ww, &cc)) {
        // init(&head, &end);
        insert_back(head, &end, to);
        insert_back(head, &end, nex);
        e[tot].to = get_index(head, to);
        e[tot].nex = get_index(head, nex);
        next_point[e[tot].to][point[e[tot].to]++] = e[tot].nex;
        dis[e[tot].to][e[tot].nex] = cc;
        e[tot].c = cc, e[tot++].w = ww;
        // w[tot] = ww, c[tot++] = cc;
    }
    int n;
    printf("%d\n", kruskal());
    puts("");
    // printf("%d\n", prim());
    return 0;
}
