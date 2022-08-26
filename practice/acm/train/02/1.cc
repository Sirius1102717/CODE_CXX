#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const double EPS = 1e-8;
const ll MAXN = 1e18;
const int INF = 0x3f3f3f3f;

int main(int argc, char* argv[]) {
    freopen("/home/freaver/CODE_C/practice/input.txt", "r", stdin);
    freopen("/home/freaver/CODE_C/practice/output.txt", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int hh, mm, MM;
    while(scanf("%d", &n), n) {
        int l = 0, d = 0, mid = 0;
        int ll = 0, dd = 0, midm = 0;
        while(n--) {
            scanf("%d%*c%d%d", &hh, &mm, &MM);
            if(MM < mm) MM += 60;
            MM -= mm;
            if (hh < 2) hh += 24;
            if(hh >= 11 && hh < 15) {
                l++;
                if(MM <= 8) ll++;
            }
            if(hh >= 18 && hh < 21) {
                d++;
                if(MM <= 8) dd++;
            }
            if(hh >= 21 && hh < 26) {
                mid++;
                if(MM <= 8) midm++;
            }
        }
        printf("lunch ");
        if(l)
            printf("%d\n", ll * 100 / l);
        else
            puts("no guest");
        printf("dinner ");
        if(d)
            printf("%d\n", dd * 100 / d);
        else
            puts("no guest");
        printf("midnight ");
        if(mid)
            printf("%d\n", midm * 100 / mid);
        else
            puts("no guest");
    }
    return 0;
}
