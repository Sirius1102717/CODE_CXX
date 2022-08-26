#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define new(type) (type*)malloc(sizeof(type))
// #define delete(type) free(type)
const double EPS = 1e-8;
const int INF = 0x3f3f3f3f;
void swap(void* a, void* b, int size) {
    void* c = new(void);
    memcpy(c, a, size), memcpy(a, b, size), memcpy(b, c, size), free(c);
}

typedef struct tree tree;

struct tree {
    int data;
    int h;
    tree *l, *r;
};

void init(tree** p, int data) {
    *p = new(tree);
    (*p)->data = data;
    (*p)->l = NULL, (*p)->r = NULL;
    (*p)->h = 0;
}

int get_height(tree* p) {
    return p ? p->h : 0;
}

void ll(tree** p) {
    tree *pp = *p;
    tree *tmp = pp->l;
    pp->l = tmp->r;
    tmp->r = *p;

    pp->h = max(get_height(pp->l), get_height(pp->r)) + 1;
    tmp->h = max(get_height(tmp->l), get_height(tmp->r)) + 1;
    *p = tmp;
}

tree* l(tree *p) {
    tree *tmp = p->l;
    p->l = tmp->r;
    tmp->r = p;

    p->h = max(get_height(p->l), get_height(p->r)) + 1;
    tmp->h = max(get_height(tmp->l), get_height(tmp->r)) + 1;
    return tmp;

}

void rr(tree** p) {
    tree *pp = *p;
    tree *tmp = pp->r;
    pp->r = tmp->l;
    tmp->l = *p;

    pp->h = max(get_height(pp->l), get_height(pp->r)) + 1;
    tmp->h = max(get_height(tmp->l), get_height(tmp->r)) + 1;
    *p = tmp;
    // tree *tmp = (*p)->r;
    // (*p)->r = tmp->l;
    // tmp->l = *p;
    // (*p)->h = max(get_height((*p)->l), get_height((*p)->r)) + 1;
    // tmp->h = max(get_height(tmp->l), get_height(tmp->r)) + 1;
}

void lr(tree** p) {
    rr(&(*p)->l);
    ll(p);
}


void rl(tree** p) {
    ll(&(*p)->r);
    rr(p);
}


void insert(tree** p, int data) {
    if(!*p) {
        tree* node;
        init(&node, data);
        *p = node;
    } else {
        if(data < (*p)->data) {
            insert(&(*p)->l, data);
        } else {
            insert(&(*p)->r, data);
        }
        int factor = get_height((*p)->l) - get_height((*p)->r);
        if(factor > 1) {
            if(data < (*p)->data) {
                lr(p);
            } else {
                ll(p);
            }
        } else if (factor < -1){
            if(data < (*p)->data) {
                rr(p);
            } else {
                rl(p);
            }
        }
    }

    (*p)->h = max(get_height((*p)->l), get_height((*p)->r)) + 1;
}

tree* get_min(tree *p)  {
    if (!p->l) {
        return p;
    } else {
        return get_min(p->l);
    }
}

tree *get_max(tree *p) {
    if (!p->r) {
        return p;
    } else {
        return get_max(p->r);
    }
}

void delete(tree **p, int data) {
    int cur_data = (*p)->data;
    if (cur_data == data) {
        if (get_height((*p)->l) > get_height((*p)->r)) {
            tree *pp = get_max((*p)->l);
            (*p)->data = pp->data;
            free(pp);
        } else {
            tree *pp = get_min((*p)->r);
            (*p)->data = pp->data;
            free(pp);
        }
    } else {
        if ( cur_data < data) {
            
            delete(&(*p)->l, data);
        } else {
            delete(&(*p)->r, data);
        }
    }
}



int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/homework/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/homework/output.tput.txt", "w", stdout);
    tree* head = NULL;
    // init(&head);
    int n;
    // scanf("%d", &n);
    // head->data = n;
    while(~scanf("%d", &n)) {
        insert(&head, n);
    }
    int tmp;
    return 0;
}
