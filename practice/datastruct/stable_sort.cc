#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int INF = 0x3f3f3f3f;

typedef struct card card;
struct card {
    string color;
    int n;
} a[36];

void bubble_sort(card* a, int n) {

    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j > i; j--) {
            if(a[j].n < a[j - 1].n) {
                swap(a[j], a[j - 1]);
                // swap(&a[j], &a[j - 1], sizeof(card));
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
        swap(a[i], a[mini]);
    }
}

string stable[20];
string stable_bubble[20];
string stable_select[20];
int num[10];
card b[50];
int main(int argc, char* argv[]) {
    int n;
    while(~scanf("%d", &n)) {
        string c;
        fill(stable, stable + 20, "");
        fill(stable_bubble, stable_bubble + 20, "");
        fill(stable_select, stable_select + 20, "");
        for(int i = 0; i < n; i++) {
            cin >> c;
            a[i].color = c[0];
            a[i].n = c[1] - '0';
            stable[a[i].n] += a[i].color;
        }
        copy(a, a + n, b);

        // memcpy(&b, &a, sizeof a);
        // copy(b, a, n);
        bubble_sort(b, n);
        memset(num, 0, sizeof num);
        for(int i = 0; i < n; i++) {
            cout << b[i].color << b[i].n << " ";
            // printf("%c%d ", b[i].color, b[i].n);
            stable_bubble[b[i].n] += b[i].color;
        }
        // puts("");
        cout << endl;
        bool flag = 1;
        for(int i = 0; i < 9; i++) {
            if(stable[i] != stable_bubble[i]) {
                puts("Not stable");
                flag = 0;
                break;
            }
            // if(memcmp(stable[i], stable_bubble[i], 4)) {
            // puts("Not stable");
            // flag = 0;
            // break;
            // }
        }
        if(flag) {
            puts("Stable");
        }
        copy(a, a + n, b);
        // memcpy(&b, &a, sizeof a);
        select_sort(b, n);
        memset(num, 0, sizeof num);
        for(int i = 0; i < n; i++) {
            cout << b[i].color << b[i].n << " ";
            // printf("%c%d ", b[i].color, b[i].n);
            stable_select[b[i].n] += b[i].color;
        }
        // puts("");
        cout << endl;
        flag = 1;
        for(int i = 0; i < 9; i++) {
            if(stable[i] != stable_select[i]) {
                puts("Not stable");
                flag = 0;
                break;
            }
            // if(memcmp(stable[i], stable_select[i], 4)) {
            // puts("Not stable");
            // flag = 0;
            // break;
            // }
        }
        if(flag) {
            puts("Stable");
        }
    };
    return 0;
}
