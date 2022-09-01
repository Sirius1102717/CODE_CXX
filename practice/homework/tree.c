#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define ll long long
#define new(type) (type*)malloc(sizeof(type))
#define delete(type) free(type)
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;
void swap(void* a, void* b, int size) {
    void* c = new(void);
    memcpy(c, a, size), memcpy(a, b, size), memcpy(b, c, size), delete(c);
}

typedef struct node node;

struct node {
    int num;
    char name[100];
};

typedef struct list list;

struct list {
    node* data;
    int child_num;
    list** next;
};

void init(list** head, char* name, int num) {
    *head = new(list);
    list* p = *head;
    p->child_num = 0;
    p->data = new(node);
    p->next = new(list*);
    // p->child = (list**)malloc(10 * sizeof (list*));
    strcpy(p->data->name, name);
    p->data->num = num;
}

void push(list** tail, int num, char* name) {
    list* p = *tail;
    init(&p->next[p->child_num++], name, num);
}

bool empty(list* head) {
    return head->child_num == 0;
}

bool build(list** head, char* name, int num, char* child_name) {
    list* p = *head;
    if(!strcmp(p->data->name, name)) {
        push(&p, num, child_name);
        return 1;
    }
    int child_num = p->child_num;
    for(int i = 0; i < child_num; i++) {
        if(build(&p->next[i], name, num, child_name)) {
            return 1;
        }
    }
    return 0;
}

void whatis(list* head, char* name) {
    if(!strcmp(head->data->name, name)) {
        printf("Part %s subparts are\n", name);
        int child_num = head->child_num;
        for(int i = 0; i < child_num; i++) {
            printf("%d %s\n", head->next[i]->data->num, head->next[i]->data->name);
        }
        return;
    }
    int child_num = head->child_num;
    for(int i = 0; i < child_num; i++) {
        whatis(head->next[i], name);
    }
}

int num;
void dfs(list* head, char* name) {
    if(!strcmp(head->data->name, name)) {
        num = head->data->num;
        return;
    } else {
        int child_num = head->child_num;
        for(int i = 0; i < child_num; i++) {
            dfs(head->next[i], name);
        }
    }
}

void howmany(list* head, char* name, char* child_name) {
    if(strcmp(name, child_name)) {
        if(!strcmp(head->data->name, name)) {
            num = 0;
            printf("%s has ", name);
            dfs(head, child_name);
            printf("%d %s", num, child_name);
            return;
        }
        int child_num = head->child_num;
        for(int i = 0; i < child_num; i++) {
            howmany(head->next[i], name, child_name);
        }
    } else {
        printf("%s has 0 %s", name, child_name);
    }
}

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/homework/ds/definitions.txt", "r", stdin);
    char name[100], child_name[100];
    int num;
    scanf("%s%d%s", name, &num, child_name);
    list* head;
    init(&head, name, -1);
    build(&head, name, num, child_name);
    while(~scanf("%s%d%s", name, &num, child_name)) {
        build(&head, name, num, child_name);
    }
    int ans = 0;

    freopen("/home/freaver/CODE_C/practice/homework/ds/queries.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/homework/ds/output.txt", "w", stdout);
    char q[100];

    while(~scanf("%s%s", q, name)) {
        if(!strcmp(q, "howmany")) {
            scanf("%s", child_name);
            howmany(head, child_name, name);
        } else {
            whatis(head, name);
        }
        puts("");
    }

    return 0;
}
