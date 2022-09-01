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


typedef struct deque deque;
typedef deque stack;
typedef deque queue;

struct deque {
    char data;
    deque* next;
    deque* pre;
};
void push_back(deque** tail, char data) {
    deque* newNode = new(deque);
    newNode->data = data;
    newNode->next = NULL;
    (*tail)->next = newNode;
    newNode->pre = *tail;
    *tail = newNode;
}
void push_front(deque** head, char data) {
    deque* newNode = new(deque);
    newNode->data = data;
    newNode->pre = NULL;
    (*head)->pre = newNode;
    newNode->next = *head;
    *head = newNode;
}
char front(deque* head) {
    return head->next->data;
}
char back(deque* tail) {
    return tail->data;
}
void push(stack** tail, char data) {
    push_back(tail, data);
}
char top(stack* tail) {
    return back(tail);
}
void pop_back(deque** tail) {
    deque* p = *tail;
    p->pre->next = NULL;
    *tail = p->pre;
    delete(p);
}
void pop_front(deque** head) {
    deque* p = *head;
    p->next->pre = NULL;
    *head = p->next;
    delete(p);
}
void pop(stack** tail) {
    pop_back(tail);
}
bool empty(deque* head) {
    return head->next == NULL;
}



int get_int(char* expression, int* i, int e) {
    int ref = 0;
    for(; *i < e; i++) {
        char c = expression[*i];
        if(isdigit(c)) {
            ref *= 10;
            ref += (c - '0');
        } else {
            break;
        }
    }
    return ref;
}

void init(deque** head, deque** tail) {
    (*head) = new(deque);
    (*head)->pre = NULL, (*head)->next = NULL;
    *tail = *head;
}

void trans(deque** head, deque** tail, stack** signal_head, stack** signal_tail, char* expression) {

    init(head, tail);
    init(signal_head, signal_tail);
    int len = strlen(expression);
    for(int i = 0; i < len; i++) {
        char c = expression[i];
        if(c == '(') {
            push(signal_tail, c);
        } else if(c == ')') {
            while(!empty(*signal_head)) {
                char e = top(*signal_tail);
                pop(signal_tail);
                if(e == '(') {
                    break;
                } else {
                    push_back(tail, e);
                }
            }
        } else if(c == '+' || c == '-') {
            while(!empty(*signal_head)) {
                char e = top(*signal_tail);
                if(e != '(') {
                    push_back(tail, e);
                    pop(signal_tail);
                } else{
                    break;
                }
            }
            push(signal_tail, c);
        } else if(c == '*' || c == '/') {
            while(!empty(*signal_head)) {
                char e = top(*signal_tail);
                if(e == '*' || e == '/') {
                    push_back(tail, e);
                    pop(signal_tail);
                } else {
                    break;
                }
            }
            push(signal_tail, c);
        } else {
            push_back(tail, c);
        }
    }
    while(!empty(*signal_head)) {
        push_back(tail, top(*signal_tail));
        pop(signal_tail);
    }
}

int cal(deque* head) {
    int num[100];
    int pos = 0;
    while(!empty(head)) {
        char c = front(head);
        pop_front(&head);
        if(isdigit(c)) {
            num[pos++] = c - '0';
        } else {
            int r = num[--pos];
            int l = num[--pos];
            if(c == '+') {
                l += r;
            } else if(c == '-') {
                l -= r;
            } else if(c == '/') {
                l /= r;
            } else if(c == '*') {
                l *= r;
            }
            // pop -= 2;
            num[pos++] = l;
        }
    }
    return num[0];
}
int main(int argc, char* argv[]) {

    stack *head, *tail;
    stack *signal_head, *signal_tail;
    char expression[100];
    scanf("%s", expression);
    // fgets(expression, 100, stdin);
    trans(&head, &tail, &signal_head, &signal_tail, expression);
    int ans = cal(head);
    printf("%d\n", ans);

    return 0;
}
