#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define new(type) (type*)malloc(sizeof(type))
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)
#define delete(type) free(type)
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

typedef struct card card;
struct card {
    char color;
    int n;
} a[36];

void swap(void* a, void* b, int size) {
    void* c = new(void);
    memcpy(c, a, size);
    memcpy(a, b, size);
    memcpy(b, c, size);
    delete(c);
}

void bubble_sort(card* a, int n) {

    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j > i; j--) {
            if(a[j].n < a[j - 1].n) {
                swap(&a[j], &a[j - 1], sizeof(card));
            }
        }
    }
}

void select_sort(card* a, int n) {

    for(int i = 0; i < n; i++) {
        int mini = i;
        for(int j = i; j < n; j++) {
            if(a[j].n < a[mini].n) {
                mini = j;
            }
        }
        swap(&a[i], &a[mini], sizeof(card));
    }
}

char stable[20][20];
char stable_bubble[20][20];
char stable_select[20][20];
int num[10];
card b[50];
int main(int argc, char* argv[]) {
    int n;
    while(~scanf("%d", &n)) {
        memset(num, 0, sizeof num);
        char c[10];
        for(int i = 0; i < n; i++) {
            scanf("%s", c);
            a[i].color = c[0];
            a[i].n = c[1]- '0';
            // a[i].color = c[0], a[i].n = c[1] - '0';
            stable[a[i].n][num[a[i].n]++] = a[i].color;
        }
        memcpy(&b, &a, sizeof a);
        // copy(b, a, n);
        bubble_sort(b, n);
        memset(num, 0, sizeof num);
        for(int i = 0; i < n; i++) {
            printf("%c%d ", b[i].color, b[i].n);
            stable_bubble[b[i].n][num[b[i].n]++] = b[i].color;
        }
        puts("");
        bool flag = 1;
        for(int i = 0; i < 9; i++) {
            if(memcmp(stable[i], stable_bubble[i], 4)) {
                puts("Not stable");
                flag = 0;
                break;
            }
        }
        if(flag) {
            puts("Stable");
        }
        memcpy(&b, &a, sizeof a);
        select_sort(b, n);
        memset(num, 0, sizeof num);
        for(int i = 0; i < n; i++) {
            printf("%c%d ", b[i].color, b[i].n);
            stable_select[b[i].n][num[b[i].n]++] = b[i].color;
        }
        puts("");
        flag = 1;
        for(int i = 0; i < 9; i++) {
            if(memcmp(stable[i], stable_select[i], 4)) {
                puts("Not stable");
                flag = 0;
                break;
            }
        }
        if(flag) {
            puts("Stable");
        }
    }
    return 0;
}
