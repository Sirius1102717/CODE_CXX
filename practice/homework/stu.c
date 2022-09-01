#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int INF = 0x3f3f3f3f;
#define new(type) (type*)malloc(sizeof(type))
#define delete(type) free(type)

typedef struct deque deque;

typedef struct list list;

struct list
{
    int factor, index;
    list *pre, *next;
};

list* copy(list* p)
{
    list* tmp = new(list);
    tmp->factor = p->factor;
    tmp->index = p->index;
    return tmp;
}

void push_back(list** end, list* newNode)
{
    (*end)->next = newNode;
    newNode->pre = *end;
    *end = newNode;
}

void insert_back(list** p, list* newNode)
{
    (*p)->next->pre = newNode;
    newNode->pre = *p;
    newNode->next = (*p)->next;
    (*p)->next = newNode;
}

void insert(list** end, list* newNode)
{
    if(newNode->index < (*end)->index) {
        push_back(end, newNode);
    } else if(newNode->index == (*end)->index) {
        (*end)->factor += newNode->factor;
    } else {
        list* p = (*end)->pre;
        while(p) {
            if(newNode->index < p->index) {
                insert_back(&p, newNode);
                break;
            } else if(newNode->factor == p->index) {
                p->factor += newNode->factor;
                break;
            } else {
                p = p->pre;
            }
        }
    }
}

void init(list** begin, list** end)
{
    // *begin = (list*)malloc(sizeof(list));
    *begin = new(list);
    *end = *begin;
    (*end)->index = INF;
}

bool del(list* begin, list* node)
{
    list* p = begin;
    bool flag = 0;
    while(p) {
        if(p->index == node->index && p->factor == node->factor) {
            p->pre->next = p->next;
            p->next->pre = p->pre;
            // free(p);
            delete(p);
            flag = 1;
            break;
        }
    }
    return flag;
}

void poly_add(list* h1, list* h2, list** e1)
{
    list *p1 = h1->next, *p2 = h2->next;
    while(p2) {
        if(p1->index > p2->index) {
            p1 = p1->next;
            bool flag = 1;
            while(p1) {
                if(p1->index == p2->index) {
                    p1->factor += p2->factor;
                    flag = 0;
                    break;
                }
                p1 = p1->next;
            }
            if(flag) {
                while(p2) {
                    push_back(e1, copy(p2));
                    p2 = p2->next;
                }
            }
        } else if(p1->index < p2->index) {
            bool flag = 1;
            while(p1) {
                if(p1->index == p2->index) {
                    p1->factor += p2->factor;
                    flag = 0;
                    break;
                }
                p1 = p1->pre;
            }
            if(flag) {
                p1 = h1;
                insert_back(&p1, copy(p2));
            }
        } else {
            p1->factor += p2->factor;
        }
        p2 = p2->next;
    }
}

void initList(int n, list** end)
{
    int factor, index;
    while(n--) {
        scanf("%d%d", &index, &factor);
        list* newNode = new(list);
        // list *newNode = (list *) malloc(sizeof (list));

        newNode->factor = factor;
        newNode->index = index;
        insert(end, newNode);
    }
}

void output(list* head)
{
    list* p = head->next;
    while(p) {
        printf("%d %d\n", p->index, p->factor);
        p = p->next;
    }
}

int main(void)
{
    int n1, n2;
    printf("请分别输入两个多项式的项数\n");
    scanf("%d%d", &n1, &n2);
    list *h1, *e1, *h2, *e2;
    printf("分别请输入指数和系数\n");
    init(&h1, &e1);
    init(&h2, &e2);
    initList(n1, &e1);
    initList(n2, &e2);
    output(h1);
    puts("");
    output(h2);
    puts("");
    poly_add(h1, h2, &e1);
    puts("");
    output(h1);
}