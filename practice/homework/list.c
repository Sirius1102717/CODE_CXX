#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define new(type) (type*)malloc(sizeof(type))
#define delete(type) free(type)

typedef struct deque deque;

typedef struct list
{
    int factor, index;
    struct list *pre, *next;
} LIST;

typedef struct deque
{
    deque *pre, *next;
    deque *front, *end;
} deque;

void push_back(deque* d, deque* newNode)
{
    newNode->pre = d->end;
    d->end->next = newNode;
    d->end = newNode;
}

void push_front(deque* d, deque* newNode)
{
    newNode->next = d->front;
    d->front->pre = newNode;
    d->front = newNode;
}

void pop_back(deque* d)
{
    deque* p = d->end;
    d->end = p->pre;
    d->end->next = NULL;
    free(p);
}

void pop_front(deque* d)
{
    deque* p = p->front;
    d->front = p->next;
    d->front->pre = NULL;
    free(p);
}

void insert(LIST** end, LIST* newNode, LIST* begin)
{
    newNode->pre = *end;
    newNode->next = begin;
    (*end)->next = newNode;
    *end = newNode;
}

void init(LIST** begin, LIST** end)
{
    // *begin = (LIST*)malloc(sizeof(LIST));
    *begin = new(LIST);
    *end = *begin;
    (*begin)->pre = *end;
    (*end)->next = *begin;
}

bool del(LIST* begin, LIST* node)
{
    LIST* p = begin;
    bool flag = 0;
    while(p) {
        if(p->index == node->index && p->factor == node->factor) {
            p->pre->next = p->next;
            p->next->pre = p->pre;
            free(p);
            flag = 1;
            break;
        }
    }
    return flag;
}

void poly_add(LIST* h1, LIST* h2)
{
    while(h2) {
        if(h1->index > h2->index) {
            while(h1) {
                if(h1->index == h2->index) {
                    h1->factor += h2->factor;
                    break;
                }
                h1 = h1->next;
            }
        } else if(h1->index < h2->index) {
            while(h1) {
                if(h1->index == h2->index) {
                    h1->factor += h2->factor;
                    break;
                }
                h1 = h1->pre;
            }
        } else {
            h1->factor += h2->factor;
        }
        h2 = h2->next;
    }
}

int main() {}
